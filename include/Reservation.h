// Reservation class
#ifndef RESERVATION_H
#define RESERVATION_H

/stores information of one reservaation
#include <string>
using namespace std;

struct Reservation {
  int reservationId;
  int studentID;
  string studentName;
  int resourceId;
  string reservationDate;

Reservation(); //defult const
Reservation(int reservationId, int studentID, string studentName, int resourceId, 
            string reservationDate); //const with reservation infomation
bool hasValidData() const; //to check is reservation data is valid

};
#endif
