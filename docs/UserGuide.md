# User Guide

## Starting the Program

Run the program from the repository root so it can find `data/resources.txt`.

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -I include src/*.cpp -o reservation_system
./reservation_system
```

For Windows, use the MSYS2 UCRT64 terminal. The resource catalog is loaded at startup. Reservations, waiting-list entries, and cancellation history exist only during the current run.

## Menu Options

| Option | What it does |
| --- | --- |
| 1 | Lists resources and their availability. |
| 2 | Creates a reservation after prompting for IDs, name, resource, and date. |
| 3 | Cancels an active reservation and records it in cancellation history. |
| 4 | Searches active reservations by reservation ID. |
| 5 | Lists active reservations and their total count. |
| 6 | Adds an existing active reservation to the waiting-list queue. |
| 7 | Removes and displays the next waiting-list entry (first in, first out). |
| 8 | Displays the current waiting list without removing entries. |
| 9 | Displays cancellation history, newest cancellation first. |
| 10 | Restores the most recently cancelled reservation. |
| 11 | Shows the waiting-student count for each resource and the total waiting count. |
| 12 | Shows active reservation counts for all resources. |
| 13 | Ranks resources by active reservation count and identifies the current leader. |
| 0 | Exits the program. |

## Creating a Reservation

1. Select option 1 to find an available resource ID.
2. Select option 2 and enter a unique reservation ID, positive student ID, student name, resource ID, and date in `MM/DD/YYYY` format.
3. The program checks the reservation data, duplicate reservation ID, resource ID, and resource availability before adding the reservation.

The date check verifies the required shape and digits; it does not validate calendar dates such as the number of days in a month.

## Waiting List and Cancellation

To add someone to the waiting list, first create an active reservation, then select option 6 and enter its reservation ID. Option 7 processes the queue in FIFO order. Option 11 reports current counts and does not remove queue entries.

To cancel, select option 3 and enter an active reservation ID. The cancelled reservation is pushed onto the cancellation-history stack. Select option 9 to display the history, or option 10 to restore the most recently cancelled reservation.

## Reports

- **Waiting-List Statistics (11):** Counts queued reservations for every loaded resource using the current waiting queue.
- **Resource Utilization (12):** Counts active reservations for every loaded resource.
- **Most Requested Resources (13):** Ranks loaded resources by their active reservation count. In this version, "requested" means currently active, not historical reservations that have since been cancelled.

Reports reflect changes made during the current program run. Exiting the program clears in-memory reservations, queue entries, and cancellation history.

## Input Errors

For numeric prompts, enter a number. Reservation creation rejects invalid reservation fields, duplicate reservation IDs, unknown resources, unavailable resources, and incorrectly formatted dates. Searching or cancelling a missing reservation reports that it was not found. Processing an empty waiting list and restoring from an empty cancellation history are also handled with a message.