# Complexity Analysis

Campus Resource Reservation System

The active reservations are stored in a singly linked list, waiting-list entries in a FIFO queue, and cancelled reservations in a stack. Let `n` be the number of active reservations, `r` the number of loaded resources, and `w` the number of waiting-list entries.

## Core Operations

| Operation | Time | Explanation |
| --- | --- | --- |
| Find reservation by ID (linear search) | O(n) | The linked list is traversed node by node until the matching ID is found or the list ends. |
| Insert reservation | O(n) | Duplicate-ID validation searches the list, and insertion at the end traverses the list. |
| Remove reservation | O(n) | The list may need to be searched to find the reservation and its predecessor. |
| Add or process next waiting entry | O(1) | Queue insertion and removal operate at the back and front, respectively. |
| Display waiting list | O(w) | Each queue entry is copied and visited once. |
| Undo cancellation | O(n) | Popping the cancellation stack is O(1); validating and reinserting the reservation is O(n). |
| Find resource by ID | O(r) | Resource records are checked sequentially. |

## Sorting and Reports

Merge Sort is implemented by the project and is used to order report rows by descending active-reservation count, with resource ID as the tie-breaker. Sorting `r` resources takes O(r log r) time and O(r) extra space.

| Operation | Time | Explanation |
| --- | --- | --- |
| Resource Utilization report | Average O(n + r log r) | Active reservations are counted by resource, then all `r` resource rows are sorted and displayed. Hash-map counting is average O(n); Merge Sort is O(r log r). |
| Most Requested Resources report | Average O(n + r log r) | It counts active reservations per resource and sorts all resources using the same Merge Sort. "Requested" currently means an active reservation. |
| Waiting-List Statistics report | O(rw) | For each resource, the queue is copied and scanned to count matching entries. The total waiting-entry count adds one additional O(w) traversal. |

The report-counting costs use average-case hash-map behavior. The waiting-list statistics implementation deliberately scans the live queue, so its counts reflect current entries without changing queue contents.

## Summary

| Requirement operation | Data structure or algorithm | Time complexity |
| --- | --- | --- |
| Reservation insertion | Linked list and linear validation | O(n) |
| Reservation removal | Linked list | O(n) |
| Reservation search | Linear search over linked list | O(n) |
| Waiting-list processing | Queue | O(1) |
| Undo cancellation | Stack and linked list | O(n) |
| Report sorting | Team-implemented Merge Sort | O(r log r) |

The linked list supports dynamic reservation insertion and deletion, the queue preserves FIFO processing, and the stack provides direct access to the most recent cancellation.

