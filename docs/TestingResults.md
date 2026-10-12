# Testing Results

## Local Integration Checks

The integrated program was built and exercised on Windows with MSYS2 UCRT64 C++11, and g++ on October 11, 2026. Tests used the menu-driven executable and temporary in-memory records; the repository data files were not changed.

| Test | Expected result | Result |
| --- | --- | --- |
| Build the complete program | Program builds and starts | **Pass**; the compiler displayed one minor warning. |
| Build and run the program on UNT CSE CELL | Program compiles and runs in the required environment | **Pass**, confirmed by the team. |
| Create reservations for resources 101 and 102; show Resource Utilization | Counts reflect each active reservation | **Pass**. |
| Cancel a reservation and show Resource Utilization again | The cancelled reservation is no longer counted | **Pass**. |
| Undo cancellation and show Resource Utilization again | Restored reservation is counted again | **Pass**. |
| Add waiting entries for resources 101 and 102; show Waiting-List Statistics | Each resource shows its current waiting count | **Pass**. |
| Process the next waiting entry and show statistics again | Processed resource count decreases; other resource count is unchanged | **Pass**. |
| Show Most Requested Resources with no active reservations | Report handles the empty active-reservation case | **Pass**. |
| Create three active reservations for resource 101 and one for 102 | Resource 101 ranks above 102 with counts 3 and 1 | **Pass**. |
| Cancel one of resource 101's reservations and rerun Most Requested | Its count updates from 3 to 2 | **Pass**. |
| Search for an existing reservation ID and display active reservations | Search finds the record and active count is correct | **Pass**. |
| Display cancellation history after cancellation | Cancelled reservation is shown | **Pass**. |

