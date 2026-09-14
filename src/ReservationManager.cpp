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
//to check if reservtion Id exists
bool ReservationManager::reservationIdExists(
    int reservationId) const {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    return found != nullptr;
}
//validate reservation
bool ReservationManager::validateReservation(
    const Reservation& reservation) const {
    if (!reservation.hasValidData()) {
        cout << "Invalid reservation data." << endl;
        return false;
    }
    if (reservationIdExists(reservation.reservationId)) { //prevents duplicate id
        cout << "Reservation ID already exists." << endl;
        return false;
    }
    return true;
}
//add new reservation
bool ReservationManager::addReservation(
    const Reservation& reservation) {
    if (!validateReservation(reservation)) { //validate before adding
        return false;
    }
    insertAtEnd(&head, reservation);
    cout << "Reservation created successfully." << endl;
    return true;
}
//cancel reservation
bool ReservationManager::cancelReservation(
    int reservationId) {
    ReservationNode* found =                           //find reservation firsr
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
//to find reservation by id
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
//couunt active reservations
int ReservationManager::getActiveReservationCount() const {
    int count = 0;
    ReservationNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
