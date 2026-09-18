// Cancellation history stack
#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H
#include <stack>               //Enables using stacks
#include "Reservation.h"       //Included Reservation.h since cancellation history needs reservation info
using namespace std;

class CancellationHistory {
private:
    stack<Reservation> cancellationHistory; //This creates a stack named cancellationHistory that holds reservation objects
public:
    void addCancellation(const Reservation& cancelledReservation); //Adds a cancellation to cancellation hisory
    bool restoreLastCancellation(Reservation& restoredReservation); //Restores and removes the last cancellation from the history, return either true or false
    void displayCancellationHistory() const; //Diplays the cancellation history
};

#endif