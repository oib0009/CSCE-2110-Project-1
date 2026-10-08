
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Reservation.h"
#include "linked_list.h"

class ReservationManager {
private:
    ReservationNode* head;

public:
    ReservationManager();
    ~ReservationManager();

    bool addReservation(const Reservation& reservation);
    bool cancelReservation(int reservationId);
    Reservation* findReservation(int reservationId);
    void displayActiveReservations() const;
    bool validateReservation(const Reservation& reservation) const;
    bool reservationIdExists(int reservationId) const;
    int getActiveReservationCount() const;

    //final project
    void displayMostRequestedResources() const;
};

#endif
