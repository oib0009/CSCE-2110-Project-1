# Group Contribution Report

## Campus Resource Reservation System

### Team Members
* Ashish Thapa
* Olu Babalola
* Uriel Trejo

### Contribution

| Team Member | Component(s) | Specific Tasks Completed | Testing/Debugging | GitHub Contributions |
| --- | --- | --- | --- | --- |
| **Ashish Thapa** | • Reservation Management<br>• Reservation data structure<br>• Integration of Reservation Management with the active reservation linked list<br>• Main program integration | **Files/Features:**<br>`include/Reservation.h`<br>`include/ReservationManager.h`<br>`src/Reservation.cpp`<br>`src/ReservationManager.cpp`<br>`main.cpp`<br><br>**Functions & Features:**<br>• Created `Reservation` structure/class storing reservation ID, student ID, student name, resource ID, and reservation date<br>• Validated reservation data<br>• Added new reservations & cancelled existing reservations<br>• Found reservations by ID, displayed active reservations, and counted active reservations<br>• Integrated `ReservationManager` with the team's linked-list implementation<br>• Connected reservation operations with resource validation, waiting list, and cancellation history in main program<br>• Helped integrate menu-driven CLI | • Tested reservation creation, searching, cancellation, and active-reservation display<br>• Performed integration testing to ensure reservation system worked with shared linked list and project components<br>• Identified and debugged compilation and include-path issues during team integration | • Worked on a separate feature branch for reservation management<br>• Submitted reservation-related code for integration<br>• Contributed to initial project structure and team responsibility documentation |
| **Olu Babalola** | • Resource Management<br>• Resource file input<br>• Active Reservation Linked List | **Functions & Features:**<br>• Loaded resource information from resource data file<br>• Stored and displayed available resources<br>• Found resources by resource ID<br>• Implemented linked list used to store active reservations<br>• Created linked-list node operations<br>• Inserted, deleted, searched, traversed, and displayed reservations in linked list<br>• Integrated linked-list implementation with Reservation Management component for a single shared list | • Contributed to testing resource loading and linked-list operations<br>• Helped with integration of shared project components | • Worked on assigned components using branches and commits to document individual contributions<br>• Completed work integrated into main project after readiness for team testing |
| **Uriel Trejo** | • Waiting List Queue<br>• Cancellation History Stack | **Functions & Features:**<br>• *Waiting List Queue:* Added students/reservations, maintained FIFO queue order, processed/removed next student, displayed waiting list<br>• *Cancellation History Stack:* Recorded cancelled reservations, maintained history using a stack, displayed history, restored most recently cancelled reservation<br>• Integrated waiting-list and cancellation-history components with Reservation Management through main program | • Contributed to testing waiting-list queue and cancellation-history stack<br>• Helped ensure components worked correctly with the rest of the project | • Worked on assigned components using branches and commits to document individual contributions<br>• Completed work integrated into main project after readiness for team testing |

---

### Shared Team Contributions

All team members participated in integrating their individual components into the Campus Resource Reservation System.

**Shared work included:**
* Integrating header and source files
* Connecting the different data structures
* Testing the complete program
* Debugging compilation and integration problems
* Reviewing the menu-driven `main.cpp`
* Updating project documentation
* Verifying that the system met Milestone 1 requirements

*The final integrated system includes Resource Management, Reservation Management, an active-reservation linked list, a waiting-list queue, a cancellation-history stack, and a menu-driven command-line interface.*

---

### GitHub Workflow

The team used GitHub for version control and collaboration. Team members worked on assigned components and used branches and commits to document their individual contributions. Completed work was integrated into the main project after the components were ready for team testing.
