Complexity Analysis
Campus Resource Reservation System
The following describes the time complexity of the core data structure operations implemented in the Campus Resource Reservation System. The active reservations are stored in a linked list, the waiting list in a queue and the cancellation history in a stack.
Let n be the number of active reservations in the linked list.
1.	Reservation Insertion
Time Complexity: O(n)
A new reservation is created and validation is performed in the ReservationManager::addReservation() function. Before insertion the active reservation list is checked. A search of the list may be necessary to ensure that no reservation uses the same reservation ID. If the reservation is to be inserted at the end of the list, traversal may be needed to reach the end of the list.
The number of nodes that may need to be checked increases with the number of active reservations. Thus, the worst-case time complexity is O(n).

2.	Reservation Removal
Time Complexity: O(n)
When a reservation is cancelled, a search is performed on the list of active reservations for the given reservation ID. The reservation may be found in any position within the list including at the end of the list.
Once the reservation is found it is then removed from the list of active reservations. Since a search of the entire list may be needed to find the reservation the worst-case time complexity is O(n).

3.	Waiting- List Processing
Time Complexity: O(1)
The waiting list is implemented using a queue. Students are processed using First-In, First-Out (FIFO) ordering.
To get to the next student in the list, a call is made to WaitingList::removeStudent(), which removes the next student in the queue. The front of the waiting list is stored in the queue and thus there is no need to search through all of the students in the list.
•	Pop from cancellation-history stack: O(1) 
•	Add reservation back to active reservations: O(n) 
•	Overall undo-cancellation operation: O(n)

4.	Undo cancellation
Time Complexity: O(n)
Cancellation history is stored in a stack. The most recently cancelled reservation can be retrieved from the cancellation history with CancellationHistory::restoreLastCancellation(). This operation is O(1) since the most recently cancelled reservation is always at the top of the stack.
Once restored, the reservation is passed into the ReservationManager::addReservation() function and inserted into the list of active reservations. Insertion into the list of active reservations may require traversal or a search of the list.
Thus,
•	Pop from cancellation-history stack: O(1)
•	Insert reservation into active reservations: O(n)
•	Undo-cancellation operation: O(n)

Complexity Summary
| Operation | Data Structure | Time Complexity |
| :--- | :--- | :--- |
| Reservation Insertion | Linked List | O(n) |
| Reservation Removal | Linked List | O(n) |
| Waiting-List Processing | Queue | O(1) |
| Undo Cancellation | Stack + Linked List | O(n) |

The chosen data structures are appropriate for the Campus Resource Reservation System. The linked list can allow dynamic insertion and deletion of active reservations while the queue maintains proper FIFO processing of the waiting list students. The stack provides easy access to the most recently cancelled reservation.

