// Reservation manager and linked list
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Reservation.h"
#include "linked_list.h"

class ReservationManager{

private:
  ReservationNode* head;

public:
  ReservationManager(); //const
  ~ReservationManager(); //destructor
  bool addReservation(const Reservation& reservation); //create or add reservation
  bool cancelReservation(int reservationId); //cancel or remove reservation
  Reservation* findReservation(int reservationId); //find reservation by ID
  void displayActiveReservation() const; //display all active reservation
  bool validateReservation(const Reservation& reservation) const; //validate before adding it
  bool reservationExists(int reservationId)const; //check if reservation exists
  int getActiveReservationCount() const; //Number of active reservation
};
#endif
