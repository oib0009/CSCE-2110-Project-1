Group Contribution Report

Campus Resource Reservation System

Team Members

•	Ashish Thapa

•	Olu Babalola

•	Uriel Trejo

Ashish Thapa

Components
•	Reservation Management

•	Reservation data structure

•	Integration of Reservation Management with the active reservation linked list

•	Main program integration


Files / Features

•	include/Reservation.h

•	include/ReservationManager.h

•	src/Reservation.cpp

•	src/ReservationManager.cpp

•	Integration work in main.cpp


Functions and Features

Ashish implemented the reservation management portion of the project. This included:

•	Creating the Reservation structure/class used throughout the project

•	Storing reservation ID, student ID, student name, resource ID, and reservation date

•	Validating reservation data

•	Adding new reservations

•	Cancelling existing reservations

•	Finding reservations by reservation ID

•	Displaying active reservations

•	Counting active reservations

•	Integrating ReservationManager with the team's linked-list implementation

•	Connecting reservation operations with resource validation, the waiting list, and cancellation history through the main program

•	Helping integrate the menu-driven command-line interface


Testing and Debugging

Ashish tested reservation creation, searching, cancellation, and active-reservation display. Integration testing was also performed to make sure the reservation system worked with the shared linked list and other project components. Compilation and include-path issues were identified and debugged during team integration.

GitHub Activity

Ashish worked on the project through a separate feature branch for reservation management and submitted reservation-related code for integration with the shared project. Ashish also contributed to the initial project structure and team responsibility documentation.


Olu Babalola

Components

•	Resource Management

•	Resource file input

•	Active Reservation Linked List


Functions and Features

Olu implemented the project's resource management functionality and linked-list data structure. His work included:

•	Loading resource information from the resource data file

•	Storing and displaying available resources

•	Finding resources by resource ID

•	Implementing the linked list used to store active reservations

•	Creating linked-list node operations

•	Inserting reservations into the linked list

•	Deleting reservations from the linked list

•	Searching the linked list

•	Traversing and displaying reservations


Olu's linked-list implementation was integrated with the Reservation Management component so that the project uses one shared active-reservation list.

Testing and Debugging

Olu contributed to testing resource loading and linked-list operations and helped with integration of the shared project components.



Uriel Trejo

Components

•	Waiting List Queue

•	Cancellation History Stack


Functions and Features

Uriel implemented the waiting-list and cancellation-history portions of the project.

Waiting-list functionality included:

•	Adding students/reservations to the waiting list

•	Maintaining FIFO queue order

•	Processing/removing the next student from the waiting list

•	Displaying the waiting list

Cancellation-history functionality included:

•	Recording cancelled reservations

•	Maintaining cancellation history using a stack

•	Displaying cancellation history

•	Restoring the most recently cancelled reservation


These components were integrated with Reservation Management through the main program.

Testing and Debugging

Uriel contributed to testing the waiting-list queue and cancellation-history stack and helped ensure that these components worked correctly with the rest of the project.



Shared Team Contributions

All team members participated in integrating their individual components into the Campus Resource Reservation System.

Shared work included:

•	Integrating header and source files

•	Connecting the different data structures

•	Testing the complete program

•	Debugging compilation and integration problems

•	Reviewing the menu-driven main.cpp

•	Updating project documentation

•	Verifying that the system met Milestone 1 requirements


The final integrated system includes Resource Management, Reservation Management, an active-reservation linked list, a waiting-list queue, a cancellation-history stack, and a menu-driven command-line interface.


GitHub Workflow

The team used GitHub for version control and collaboration. Team members worked on assigned components and used branches and commits to document their individual contributions. Completed work was integrated into the main project after the components were ready for team testing.

