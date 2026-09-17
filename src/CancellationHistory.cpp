// Cancellation history implementation
#include "CancellationHistory.h"
#include <iostream>
using namespace std;

//Adds a cancelled reservation to the cancellation history
void CancellationHistory::addCancellation(const Reservation& cancelledReservation) {
    cancellationHistory.push(cancelledReservation); //Adds cancelled reservation to the cancellation history
}

//Restores and removes the last cancellation from cancellation history, bool returns true if successful, false if cancellation history is empty
bool CancellationHistory::restoreLastCancellation(Reservation& restoredReservation) {
    if (cancellationHistory.empty()) {
        cout << "Cancellation history is empty." << endl;
        return false; //Returns false since there isn't anything in cancellation history to restore.
    }
    restoredReservation = cancellationHistory.top(); //This gets the top cancelled reservation from the stack and assigns to restoredReservation
    cancellationHistory.pop(); //This then removes the top cancelled reservation from cancellation history. Since it has been restored.
    return true; //Returns true since a canceleld reservation was restored. 
}

//Displays the cancellation history
void CancellationHistory::displayCancellationHistory() const {
    if (cancellationHistory.empty()) {
        cout << "Cancellation history is empty, nothing to display." << endl;
        return; 
    }
    stack<Reservation> tempCancellationHistory = cancellationHistory; //Temporary cancellation history to display without orignal being changed
    cout << "Cancellation History: " << endl;

    while (!tempCancellationHistory.empty()) { //While loop that displays cancellation hisotry while it ins't empty
        Reservation canceledReservation = tempCancellationHistory.top();
        cout << "Reservation ID: " << canceledReservation.reservationId << endl; //Lines 33-37 displays reservation info
        cout << "Student ID: " << canceledReservation.studentId << endl;
        cout << "Student Name: " << canceledReservation.studentName << endl;
        cout << "Resource ID: " << canceledReservation.resourceId << endl;
        cout << "Reservation Date: " << canceledReservation.reservationDate << endl;
        cout << endl;
        tempCancellationHistory.pop(); //Removes the top cancelled reservation from the temporary cancellation history,

    }
}