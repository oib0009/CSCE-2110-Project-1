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

Reservation(); // Default constructor
Reservation(int reservationId,
                int studentId,
                const string& studentName,
                int resourceId,
                const string& reservationDate); // Constructor with reservation information
bool hasValidData() const; // Check if reservation data is valid
};
#endif
