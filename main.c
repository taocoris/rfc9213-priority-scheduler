#include <stdio.h>
#include "rfc_parser.h"
#include "heap_manager.h"

int main() {
    PriorityQueue* gateway_pq = create_queue(10);
    
    const char* headers[] = {"u=5", "u=0", "u=3", "u=1"};
    const char* ids[] = {"REQ_LOW", "REQ_CRITICAL", "REQ_MEDIUM", "REQ_HIGH"};

    printf("--- Istekler Aliniyor ---\n");
    for(int i=0; i<4; i++) {
        HttpRequest req;
        req.urgency = parse_priority(headers[i]);
        strcpy(req.request_id, ids[i]);
        
        printf("Alindi: %s (Urgency: %d)\n", req.request_id, req.urgency);
        push(gateway_pq, req);
    }

    printf("\n--- API Gateway Zamanlayici Calisiyor ---\n");
    while(gateway_pq->size > 0) {
        HttpRequest processed = pop(gateway_pq);
        printf("Isleniyor: %s [RFC 9213 Urgency: %d]\n", processed.request_id, processed.urgency);
    }

    free_queue(gateway_pq);
    return 0;
}