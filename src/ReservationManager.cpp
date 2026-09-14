// Reservation manager implementation
#include "../include/ReservationManager.h"
#include <iostream>

using namespace std;
//default const
ReservationManager::ReservationManager() {
    head = nullptr;
} 
// Destructor
ReservationManager::~ReservationManager() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* temp = current;
        current = current->next;

        delete temp;
    }
    head = nullptr;
}

// Check if reservation ID already exists
bool ReservationManager::reservationIdExists(
    int reservationId) const {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    return found != nullptr;
}
// Validate reservation
bool ReservationManager::validateReservation(
    const Reservation& reservation) const {
    if (!reservation.hasValidData()) {
        cout << "Invalid reservation data." << endl;
        return false;
    }

    // Prevent duplicate reservation IDs
    if (reservationIdExists(reservation.reservationId)) {
        cout << "Reservation ID already exists." << endl;
        return false;
    }
    return true;
}
// Add a new reservation
bool ReservationManager::addReservation(
    const Reservation& reservation) {
    if (!validateReservation(reservation)) {
        return false;
    } // Validate before adding
    insertAtEnd(&head, reservation);
    cout << "Reservation created successfully." << endl;
    return true;
}
// Cancel a reservation
bool ReservationManager::cancelReservation(
    int reservationId) {
    ReservationNode* found =
        findReservationNode(head, reservationId); // Find reservation first
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
// Find reservation by ID
Reservation* ReservationManager::findReservation(
    int reservationId) {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    if (found == nullptr) {
        return nullptr;
    }
    return &(found->data);
}

// Display all active reservations
void ReservationManager::displayActiveReservations() const {
    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }
  
    printReservations(head);
}

// Count active reservations
int ReservationManager::getActiveReservationCount() const {
    int count = 0;
    ReservationNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next; 
    }
    return count;
}
