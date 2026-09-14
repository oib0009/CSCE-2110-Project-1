// Reservation implementation
#include "../include/Reservation.h"

// Default const
Reservation::Reservation() {
    reservationId = 0;
    studentId = 0;
    studentName = "";
    resourceId = 0;
    reservationDate = "";
}

// Constructor with reservation information
Reservation::Reservation(int reservationId,
                         int studentId,
                         const string& studentName,
                         int resourceId,
                         const string& reservationDate) {

    this->reservationId = reservationId;
    this->studentId = studentId;
    this->studentName = studentName;
    this->resourceId = resourceId;
    this->reservationDate = reservationDate;
}

// Check if reservation data is valid
bool Reservation::hasValidData() const {
    if (reservationId <= 0) {
        return false;
    }
    if (studentId <= 0) {
        return false;
    }
    if (studentName.empty()) {
        return false;
    }
    if (resourceId <= 0) {
        return false;
    }
    if (reservationDate.empty()) {
        return false;
    }
    return true;
}
