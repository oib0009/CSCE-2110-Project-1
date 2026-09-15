#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Reservation.h"
#include "linked_list.h"

class ReservationManager {
private:
    ReservationNode* head;
public:
    ReservationManager(); //default constructor
    ~ReservationManager(); //destructor
    bool addReservation(const Reservation& reservation); //create/add reservation
    bool cancelReservation(int reservationId); //cancel/remove reservation
    Reservation* findReservation(int reservationId);  //find reservation by ID
    void displayActiveReservations() const; //display active reservations
    bool validateReservation(const Reservation& reservation) const; //validate reservation before adding
    bool reservationIdExists(int reservationId) const; //check if reservation ID already exists
    int getActiveReservationCount() const; //number of active reservations
};

#endif
