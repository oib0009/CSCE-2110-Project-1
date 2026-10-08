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

    Reservation();
    Reservation(int reservationId,
                int studentId,
                const string& studentName,
                int resourceId,
                const string& reservationDate);
    bool hasValidData() const;
};
#endif
