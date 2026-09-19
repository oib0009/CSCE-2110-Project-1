// Main program - shared team integration
#include <iostream>
#include <limits>

#include "../include/Reservation.h"
#include "../include/ReservationManager.h"
#include "../include/Resource.h"
#include "../include/WaitingList.h"
#include "../include/CancellationHistory.h"

using namespace std;

int main() {

    ReservationManager reservationManager;
    WaitingList waitingList;
    CancellationHistory cancellationHistory;

    // Load resources from file
    if (!Resource::loadResources("data/resources.txt")) {
        cout << "Warning: Could not load resources." << endl;
    }

    int choice = -1;

    while (choice != 0) {

        cout << "\n=====================================\n";
        cout << " Campus Resource Reservation System\n";
        cout << "=====================================\n";
        cout << "1. Display Resources\n";
        cout << "2. Add Reservation\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Find Reservation\n";
        cout << "5. Display Active Reservations\n";
        cout << "6. Add Student to Waiting List\n";
        cout << "7. Process Next Student in Waiting List\n";
        cout << "8. Display Waiting List\n";
        cout << "9. Display Cancellation History\n";
        cout << "10. Undo Last Cancellation\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {

            // Display resources
            case 1: {
                Resource::displayResources();
                break;
            }

            // Add reservation
            case 2: {
                int reservationId;
                int studentId;
                string studentName;
                int resourceId;
                string reservationDate;

                cout << "Enter reservation ID: ";
                cin >> reservationId;

                cout << "Enter student ID: ";
                cin >> studentId;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter student name: ";
                getline(cin, studentName);

                cout << "Enter resource ID: ";
                cin >> resourceId;

                cout << "Enter reservation date: ";
                cin >> reservationDate;

                // Make sure resource exists
                if (!Resource::findById(resourceId)) {
                    cout << "Resource not found." << endl;
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

            // Cancel reservation
            case 3: {
                int reservationId;

                cout << "Enter reservation ID to cancel: ";
                cin >> reservationId;

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                    break;
                }

                // Save reservation before deleting it
                Reservation cancelledReservation = *reservation;

                if (reservationManager.cancelReservation(reservationId)) {
                    cancellationHistory.addCancellation(
                        cancelledReservation
                    );
                }

                break;
            }

            // Find reservation
            case 4: {
                int reservationId;

                cout << "Enter reservation ID: ";
                cin >> reservationId;

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                } else {
                    cout << "\nReservation Found\n";
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

            // Display active reservations
            case 5: {
                reservationManager.displayActiveReservations();

                cout << "Total active reservations: "
                     << reservationManager.getActiveReservationCount()
                     << endl;

                break;
            }

            // Add student to waiting list
            case 6: {
                int reservationId;

                cout << "Enter reservation ID to add to waiting list: ";
                cin >> reservationId;

                Reservation* reservation =
                    reservationManager.findReservation(reservationId);

                if (reservation == nullptr) {
                    cout << "Reservation not found." << endl;
                } else {
                    waitingList.addStudent(*reservation);
                    cout << "Student added to waiting list." << endl;
                }

                break;
            }

            // Process waiting list
            case 7: {
                Reservation nextStudent;

                if (waitingList.removeStudent(nextStudent)) {
                    cout << "Processing next student:" << endl;
                    cout << "Reservation ID: "
                         << nextStudent.reservationId << endl;
                    cout << "Student ID: "
                         << nextStudent.studentId << endl;
                    cout << "Student Name: "
                         << nextStudent.studentName << endl;
                }

                break;
            }

            // Display waiting list
            case 8: {
                waitingList.displayWaitingList();
                break;
            }

            // Display cancellation history
            case 9: {
                cancellationHistory.displayCancellationHistory();
                break;
            }

            // Undo cancellation
            case 10: {
                Reservation restoredReservation;

                if (cancellationHistory.restoreLastCancellation(
                        restoredReservation)) {

                    if (reservationManager.addReservation(
                            restoredReservation)) {

                        cout << "Last cancellation restored."
                             << endl;
                    } else {
                        cout << "Could not restore reservation."
                             << endl;
                    }
                }

                break;
            }

            case 0: {
                cout << "Exiting program." << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
    }

    return 0;
}
