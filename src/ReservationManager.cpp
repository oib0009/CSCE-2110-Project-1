// Reservation manager implementation
#include "../include/ReservationManager.h"
#include <iostream>

using namespace std;

//default const
ReservationManager::ReservationManager() {
    head = nullptr;
}

//destructor
ReservationManager::~ReservationManager() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

//check if reservation ID already exists
bool ReservationManager::reservationIdExists(
    int reservationId) const {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    return found != nullptr;
}

//to validate reservation
bool ReservationManager::validateReservation(
    const Reservation& reservation) const {
    if (!reservation.hasValidData()) {
        cout << "Invalid reservation data." << endl;
        return false;
    }

    //prevent duplicate reservation IDs
    if (reservationIdExists(reservation.reservationId)) {
        cout << "Reservation ID already exists." << endl;
        return false;
    }
    return true;
}

//add a new reservation
bool ReservationManager::addReservation(
    const Reservation& reservation) {
    //validate before adding
    if (!validateReservation(reservation)) {
        return false;
    }
    insertAtEnd(&head, reservation);
    cout << "Reservation created successfully." << endl;
    return true;
}

//cancel a reservation
bool ReservationManager::cancelReservation(
    int reservationId) {
    //find reservation first
    ReservationNode* found =
        findReservationNode(head, reservationId);
    if (found == nullptr) {
        cout << "Reservation not found." << endl;
        return false;
    }
    bool removed =
        deleteNode(&head, reservationId);
    if (removed) {
        cout << "Reservation cancelled successfully." << endl;
        return true;
    }
    return false;
}
//find reservation by ID
Reservation* ReservationManager::findReservation(
    int reservationId) {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    if (found == nullptr) {
        return nullptr;
    }
    return &(found->data);
}

//display all active reservations
void ReservationManager::displayActiveReservations() const {
    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }
    printReservations(head);
}

//count active reservations
int ReservationManager::getActiveReservationCount() const {
    int count = 0;
    ReservationNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}




