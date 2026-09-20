#include <iostream>
#include <limits>
#include <string>

#include "../include/Reservation.h"
#include "../include/ReservationManager.h"
#include "../include/Resource.h"
#include "../include/WaitingList.h"
#include "../include/CancellationHistory.h"

using namespace std;

void displayMenu() {
    cout << "\n=============================================\n";
    cout << "   Campus Resource Reservation System\n";
    cout << "=============================================\n";
    cout << "1. Display Resources\n";
    cout << "2. Create Reservation\n";
    cout << "3. Cancel Reservation\n";
    cout << "4. Search Reservation\n";
    cout << "5. Display Active Reservations\n";
    cout << "6. Add Student to Waiting List\n";
    cout << "7. Process Next Student in Waiting List\n";
    cout << "8. Display Waiting List\n";
    cout << "9. Display Cancellation History\n";
    cout << "10. Undo Last Cancellation\n";
    cout << "0. Exit\n";
    cout << "=============================================\n";
    cout << "Enter choice: ";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidDateFormat(const string& date) {
    if (date.size() != 10 || date[2] != '/' || date[5] != '/') {
        return false;
    }

    for (size_t index = 0; index < date.size(); index++) {
        if (index == 2 || index == 5) {
            continue;
        }

        if (date[index] < '0' || date[index] > '9') {
            return false;
        }
    }

    return true;
}

int main() {

    ReservationManager reservationManager;
    WaitingList waitingList;
    CancellationHistory cancellationHistory;

    // Load resource information from file
    if (!Resource::loadResources("data/resources.txt")) {
        cout << "Warning: Resource file could not be loaded." << endl;
    }

    int choice;

    do {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            clearInput();
            continue;
        }

        switch (choice) {

            // -----------------------------------------
            // Display Resources
            // -----------------------------------------
            case 1: {
                cout << "\n--- Available Campus Resources ---\n";
                Resource::displayResources();
                break;
            }

            // -----------------------------------------
            // Create Reservation
            // -----------------------------------------
            case 2: {
                int reservationId;
                int studentId;
                string studentName;
                int resourceId;
                string reservationDate;

                cout << "\n--- Create Reservation ---\n";

                cout << "Enter Reservation ID: ";
                if (!(cin >> reservationId)) {
                    cout << "Invalid Reservation ID." << endl;
                    clearInput();
                    break;
                }

                cout << "Enter Student ID: ";
                if (!(cin >> studentId)) {
                    cout << "Invalid Student ID." << endl;
                    clearInput();
                    break;
                }

                clearInput();

                cout << "Enter Student Name: ";
                getline(cin, studentName);

                cout << "Enter Resource ID (example: 101): ";
                if (!(cin >> resourceId)) {
                    cout << "Invalid Resource ID." << endl;
                    clearInput();
                    break;
                }

                clearInput();

                cout << "Enter Reservation Date (MM/DD/YYYY): ";
                getline(cin, reservationDate);

                if (!isValidDateFormat(reservationDate)) {
                    cout << "Invalid date format. Use MM/DD/YYYY." << endl;
                    break;
                }

                // Make sure resource ID exists and is available
                if (!Resource::findById(resourceId)) {
                    cout << "Cannot create reservation. "
                         << "Resource ID does not exist." << endl;
                    break;
                }

                if (!Resource::isResourceAvailable(resourceId)) {
                    cout << "Cannot create reservation. "
                         << "Resource is currently unavailable." << endl;
                    break;
                }

                Reservation newReservation(
                    reservationId,
                    studentId,
                    studentName,
                    resourceId,
                    reservationDate
                );

                reservationManager.addReservation(newReservation);

                break;
            }

            // -----------------------------------------
            // Cancel Reservation
            // -----------------------------------------
            case 3: {
                int reservationId;

                cout << "\n--- Cancel Reservation ---\n";
                cout << "Enter Reservation ID: ";

                if (!(cin >> reservationId)) {
                    cout << "Invalid Reservation ID." << endl;
                    clearInput();
                    break;
                }

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                    break;
                }

                // Save a copy before removing it
                Reservation cancelledReservation = *reservation;

                if (reservationManager.cancelReservation(reservationId)) {

                    // Store cancellation on stack
                    cancellationHistory.addCancellation(
                        cancelledReservation
                    );

                    cout << "Reservation added to "
                         << "cancellation history." << endl;
                }

                break;
            }

            // -----------------------------------------
            // Search Reservation
            // -----------------------------------------
            case 4: {
                int reservationId;

                cout << "\n--- Search Reservation ---\n";
                cout << "Enter Reservation ID: ";

                if (!(cin >> reservationId)) {
                    cout << "Invalid Reservation ID." << endl;
                    clearInput();
                    break;
                }

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                }
                else {
                    cout << "\nReservation Found\n";
                    cout << "-----------------------------\n";
                    cout << "Reservation ID: "
                         << reservation->reservationId << endl;
                    cout << "Student ID: "
                         << reservation->studentId << endl;
                    cout << "Student Name: "
                         << reservation->studentName << endl;
                    cout << "Resource ID: "
                         << reservation->resourceId << endl;
                    cout << "Reservation Date: "
                         << reservation->reservationDate << endl;
                }

                break;
            }

            // -----------------------------------------
            // Display Active Reservations
            // -----------------------------------------
            case 5: {
                cout << "\n--- Active Reservations ---\n";

                reservationManager.displayActiveReservations();

                cout << "\nTotal Active Reservations: "
                     << reservationManager.getActiveReservationCount()
                     << endl;

                break;
            }

            // -----------------------------------------
            // Add Student to Waiting List
            // -----------------------------------------
            case 6: {
                int reservationId;

                cout << "\n--- Add to Waiting List ---\n";
                cout << "Enter existing Reservation ID: ";

                if (!(cin >> reservationId)) {
                    cout << "Invalid Reservation ID." << endl;
                    clearInput();
                    break;
                }

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                    cout << "Create the reservation first." << endl;
                    break;
                }

                waitingList.addStudent(*reservation);

                cout << "Student added to waiting list." << endl;

                break;
            }

            // -----------------------------------------
            // Process Next Waiting Student
            // -----------------------------------------
            case 7: {
                cout << "\n--- Process Waiting List ---\n";

                Reservation nextStudent;

                if (waitingList.removeStudent(nextStudent)) {

                    cout << "Next student removed from waiting list."
                         << endl;

                    cout << "Reservation ID: "
                         << nextStudent.reservationId << endl;

                    cout << "Student ID: "
                         << nextStudent.studentId << endl;

                    cout << "Student Name: "
                         << nextStudent.studentName << endl;

                    cout << "Resource ID: "
                         << nextStudent.resourceId << endl;
                }
                else {
                    cout << "Waiting list is empty." << endl;
                }

                break;
            }

            // -----------------------------------------
            // Display Waiting List
            // -----------------------------------------
            case 8: {
                cout << "\n--- Waiting List ---\n";

                waitingList.displayWaitingList();

                break;
            }

            // -----------------------------------------
            // Display Cancellation History
            // -----------------------------------------
            case 9: {
                cout << "\n--- Cancellation History ---\n";

                cancellationHistory.displayCancellationHistory();

                break;
            }

            // -----------------------------------------
            // Undo Last Cancellation
            // -----------------------------------------
            case 10: {
                cout << "\n--- Undo Last Cancellation ---\n";

                Reservation restoredReservation;

                if (cancellationHistory.restoreLastCancellation(
                        restoredReservation)) {

                    if (reservationManager.addReservation(
                            restoredReservation)) {

                        cout << "Most recent cancellation restored."
                             << endl;
                    }
                    else {
                        cancellationHistory.addCancellation(
                            restoredReservation);
                        cout << "Unable to restore reservation."
                             << endl;
                    }
                }
                else {
                    cout << "Cancellation history is empty." << endl;
                }

                break;
            }

            // -----------------------------------------
            // Exit
            // -----------------------------------------
            case 0: {
                cout << "\nExiting Campus Resource "
                     << "Reservation System." << endl;

                cout << "Goodbye!" << endl;

                break;
            }

            // -----------------------------------------
            // Invalid Menu Selection
            // -----------------------------------------
            default: {
                cout << "Invalid menu selection. "
                     << "Please try again." << endl;

                break;
            }
        }

    } while (choice != 0);

    return 0;
}