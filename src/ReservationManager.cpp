// Reservation manager implementation
#include "../include/ReservationManager.h"
#include <iostream>

using namespace std;

 //default constructor
ReservationManager::ReservationManager() {}

//destructor
ReservationManager::~ReservationManager() {} 

//create/add reservation
bool ReservationManager::addReservation(const Reservation& reservation) {}

//cancel/remove reservation
bool ReservationManager::cancelReservation(int reservationId) {} 

//find reservation by ID
Reservation* ReservationManager::findReservation(int reservationId) {}  

//display active reservations
void ReservationManager::displayActiveReservations() const {}

//validate reservation before adding
bool ReservationManager::validateReservation(const Reservation& reservation) const{} 

//check if reservation ID already exists
bool ReservationManager::reservationIdExists(int reservationId) const{} 

//number of active reservations
int ReservationManager::getActiveReservationCount() const{} 




