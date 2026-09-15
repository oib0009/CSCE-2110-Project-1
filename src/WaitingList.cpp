// Waiting list implementation
#include "WaitingList.h"
#include <iostream>
using namespace std;

void WaitingList::addStudent(const Reservation&reservation) {
    waitingList.push(reservation); //Adds student from reservation to the waiting list
}

bool WaitingList::removeStudent(Reservation& removedStudent) {
    if (waitingList.empty()) { //If statement checks if the waiting list is empty, if it is then returns false. Otherwise moves on
        cout << "The waiting list is empty." << endl;
        return false;
    }
    removedStudent = waitingList.front(); //This assigns removedStudent with the first student in waiting list
    waitingList.pop(); //This then removes the first student from the waiting list, the line above keeps tab of the removed student
    return true; //Then returns true to show that the removal was successful
}

void WaitingList::displayWaitingList() const {
    if (waitingList.empty()) { //First check just to make sure that waiting list is  empty. Otherwise continues to display the waiting list
        cout << "The waiting list is empty, nothing to display." << endl;
        return;
    }

    queue<Reservation> tempWaitingList = waitingList; //Temporary copy of the waiting list to original isn't changed while displaying the waiting list
    cout << "Waiting List: " << endl;

    while (!tempWaitingList.empty()) { //While loop that continues to display waiting list while list isn't empty
        Reservation currentReservation = tempWaitingList.front(); //currentReservation is assigned with the first student in the waiting list
        cout << "Reservation ID: " << currentReservation.reservationId << endl; //Lines 31-35 display reservation info. In order just like the reservations.txt file
        cout << "Student ID: " << currentReservation.studentId << endl;
        cout << "Student Name: " << currentReservation.studentName << endl;
        cout << "Resource ID: " << currentReservation.resourceId << endl;
        cout << "Reservation Date: " << currentReservation.reservationDate << endl;
        cout << endl;
        tempWaitingList.pop(); //Removes the first student from the temporary waiting list, then the while loop loops to begin again while list ins't empty
    }
}