# RFC 9213 Compliant Priority Request Scheduler

This project implements a modular **API Gateway Request Scheduler** in C, utilizing the **Min-Heap** data structure to manage HTTP requests based on the **RFC 9213 (Extensible HTTP Priorities)** standard.

## 🏗 System Architecture
The system is designed with a modular approach, separating concerns into three distinct layers:
* **RFC Parser:** Extracts urgency levels (u=0 to u=7) from HTTP priority headers.
* **Priority Queue (Min-Heap):** Manages the requests in a binary heap to ensure $O(\log n)$ efficiency.
* **Gateway Engine:** The main driver that simulates real-time request processing.

## 🚀 Why Min-Heap? (Algorithm Analysis)
In a high-traffic API Gateway, performance is critical. We chose a Min-Heap over a standard Array or Linked List for the following reasons:

| Operation | Array (Unsorted) | Min-Heap |
| :--- | :--- | :--- |
| **Insert** | $O(1)$ | $O(\log n)$ |
| **Extract-Min** | $O(n)$ | $O(\log n)$ |
| **Find-Min** | $O(n)$ | $O(1)$ |

By using a Min-Heap, we guarantee that the most urgent request (lowest urgency value) is always at the root, allowing for efficient scheduling even under heavy load.



## 🛠 Features
* **Standard Compliance:** Full implementation of RFC 9213 priority levels.
* **Modular Design:** Clean separation between `.h` and `.c` files for scalability.
* **Memory Management:** Dynamic memory allocation with `malloc`, `realloc`, and strict `free` protocols to ensure zero memory leaks.
* **Efficiency:** Heapify Up/Down algorithms implemented for optimal queue reordering.

## 📦 Build and Run
To compile the project, use the following command:
```
gcc main.c rfc_parser.c heap_manager.c -o priority_gateway
./priority_gateway

```
## 📜 Standards
RFC 9213: Urgency levels are parsed where u=0 is the highest priority and u=7 is the lowest.
