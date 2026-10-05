# Project 1 - Team Responsibilities

## Ashish - Reservations, Searching & Most Requested Resources

**Files:**

* `include/Reservation.h`
* `include/ReservationManager.h`
* `src/Reservation.cpp`
* `src/ReservationManager.cpp`

**Responsibilities:**

* Reservation creation, cancellation, validation, and display
* Maintain active reservations
* Linear Search for reservations
* Most Requested Resources report using actual reservation data
* Ensure search/reporting is integrated into the system

---

## Olu - Resources, Linked List, Sorting & Resource Utilization

**Files:**

* `linked_list.h`
* `Linked_list.cpp`
* `include/Resource.h`
* `src/Resource.cpp`
* `data/resources.txt`

**Responsibilities:**

* Resource class and resource data
* Load, store, display, and manage resources
* Linked list implementation
* Implement and integrate **Merge Sort or Quick Sort**
* Resource Utilization report showing every resource and its reservation count
* Reports must use actual system data, not hard-coded results

---

## Uriel - Waiting List & Cancellation History

**Files:**

* `include/WaitingList.h`
* `include/CancellationHistory.h`
* `src/WaitingList.cpp`
* `src/CancellationHistory.cpp`

**Responsibilities:**

* Waiting list queue
* Add/remove students from waiting list
* Cancellation history stack
* Undo/display cancellation history
* Waiting-List Statistics report showing students waiting for each resource
* Statistics must use actual waiting-list data

---

## Shared Responsibilities

**Files:**

* `src/main.cpp`
* Documentation

All members contribute to:

* System integration
* Testing and debugging
* Error handling
* Complexity analysis
* Documentation
* Contribution report
* Final demo preparation

### Final Requirements

| Requirement              | Owner    |
| ------------------------ | -------- |
| Linear Search            | Ashish   |
| Merge Sort / Quick Sort  | Olu      |
| Active Reservations      | Ashish   |
| Resource Utilization     | Olu      |
| Most Requested Resources | Ashish   |
| Waiting-List Statistics  | Uriel    |
| Integration & Testing    | Everyone |
| Documentation & Demo     | Everyone |

### Important

* Searching and sorting algorithms must be implemented by the team.
* `std::sort()` cannot be used to satisfy the sorting requirement.
* Reports must be generated from actual system data.
* Hard-coded report results are not allowed.
