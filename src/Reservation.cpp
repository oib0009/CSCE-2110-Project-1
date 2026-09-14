#include "../include/Reservation.h"

//Default cont
Reservation::Reservation() {
  reservationId = 0;
  studentId = 0;
  studentName = "";
  resourceId = 0;
  reservationDate = "";
}
//const reservation information
Reservation::Reservation(int reservationId, int studentId, const string& studentName, 
                         int resourceId, const string& reservationDate){
this->reservationId = reservationId;
this->studentId = studentId;
this->studentName = studentName;
this->resourceId = resourceId;
this->reservationDate = reservationDate; 
}

//to validate the basic reservation information
bool Reservation::hasValidDate() const {
  if (reservation <= 0){
    return false;
  }
  if (studentId <=0){
    return false;
  }
  if (studentName.empty() {
    return false;
  }
  if (resource <=0) {
    return false;
  }
  if (reservation.empty()){
    return false;
  }
  return true;
}
