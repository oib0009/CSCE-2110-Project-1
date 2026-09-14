// Reservation class
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

struct Reservation {
  int reservationId;
  int studentId;
  string studentName;
  int resourceId;
  string reservationDate;

Reservation(); //default const
Reservation(int reservationId, int studentId, string studentName, int resourceId,
            string reservationDate); //const with reservation info
bool hasValiData() const; //to check if the reservation data is valid

};
#endif
