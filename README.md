# Campus Resource Reservation System

A C++ command-line program for managing campus resources, active reservations, waiting lists, and cancellation history. The system includes reports generated from the resources and reservations held by the running program.

## Build and Run

Run these commands from the repository root with a C++11 compiler:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -I include src/*.cpp -o reservation_system
./reservation_system
```

The program loads resource records from `data/resources.txt`, so run it from the repository root. With MSYS2 on Windows, use the UCRT64 terminal and the same commands.

## Menu Features

| Option | Feature |
| --- | --- |
| 1 | Display resources and availability |
| 2 | Create a reservation |
| 3 | Cancel a reservation |
| 4 | Search for a reservation by ID |
| 5 | Display active reservations |
| 6 | Add an existing reservation to the waiting list |
| 7 | Process the next waiting-list entry (FIFO) |
| 8 | Display the waiting list |
| 9 | Display cancellation history |
| 10 | Restore the most recently cancelled reservation |
| 11 | Display waiting-list counts for each resource |
| 12 | Display active reservation counts for each resource |
| 13 | Rank resources by active reservation count |

The Most Requested Resources report currently defines "requested" as an active reservation. Reservation, waiting-list, and cancellation-history data are held in memory for the current run; only the resource catalog is loaded from a file.

## Project Structure

- `data/` contains the resource catalog and reservation data files.
- `docs/` contains the user guide, complexity analysis, testing results, contribution report, and repository URL.
- `include/` contains declarations for reservations, resources, the linked list, waiting list, and cancellation history.
- `src/` contains the implementations and menu-driven application.

## Team Responsibilities

- **Ashish Thapa:** reservation management, reservation search, and Most Requested Resources.
- **Olu Babalola:** resource management, linked-list integration, Merge Sort, and Resource Utilization.
- **Uriel Trejo:** waiting list, cancellation history, and Waiting-List Statistics.

All team members contributed to integration, testing, and documentation. See the contribution report for details.
