//Reservation class
#ifndef RESERVATION_H
#define RESERVATION_H

//stores information for one reserevation
#include <string>
using namespace std;

struct Reservation {
    int reservationId;
    int studentId;
    string studentName;
    int resourceId;
    string reservationDate;

    Reservation(); //defult const
    Reservation(int reservationId, int studentId, const string& studentName, int resourceId, const string& reservationDate); //const with reservation information
    bool hasValidData() const; //to check is the reservation data valid
};
#endif
