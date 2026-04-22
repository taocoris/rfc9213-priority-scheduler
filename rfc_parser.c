#include "rfc_parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parse_priority(const char* priority_header) {
    char* u_ptr = strstr(priority_header, "u=");
    if (u_ptr) {
        int val = u_ptr[2] - '0'; 
        if (val >= 0 && val <= 7) return val;
    }
    return 7; 
}