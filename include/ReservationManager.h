#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H
#include "Reservation.h"
#include "linked_list.h"

class ReservationManager {
private:
    ReservationNode* head;
public:
    ReservationManager(); // Constructor
    ~ReservationManager(); // Destructor
    bool addReservation(const Reservation& reservation); // Create/add reservation
    bool cancelReservation(int reservationId); // Cancel/remove reservation
    Reservation* findReservation(int reservationId); // Find reservation by ID
    void displayActiveReservations() const;  // Display active reservations
    bool validateReservation(const Reservation& reservation) const; // Validate reservation before adding
    bool reservationIdExists(int reservationId) const; // Check if reservation ID already exists
    int getActiveReservationCount() const;// Number of active reservations

};
#endif
