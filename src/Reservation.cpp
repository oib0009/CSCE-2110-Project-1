// Reservation implementation
#include "../include/Reservation.h"

Reservation::Reservation(){
  reservationId = 0;
  studentId = 0;
  studentName = "";
  resourceId = 0;
  reservationDate = "";
} //default const
Reservation::Reservation(int reservationId, int studentId, string& studentName, int resourceId,
            string& reservationDate){
  this->reservationId = reservationId;
  this->studentId = studentId;
  this->studentName = studentName;
  this->resourceId = resourceId;
  this->reservationDate = reservationDate;
  
  } //const with reservation info

//to check if the reservation data is valid
bool Reservation::hasValiData() const{
  if (reservation <= 0){
    return false;
  }
  if(studentId <= 0){
    return false;
  }
  if (studentName.empty()){
    return false;
  }
  if (resourceId <= 0){
    return false;
  }
  if (reservationDate.empty()){
    return false
  }
  return true; 
} 
