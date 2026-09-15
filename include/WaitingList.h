//Waiting List using Queue
#ifndef WAITING_LIST_H
#define WAITING_LIST_H
#include <queue>                //To enable queues
#include "Reservation.h"        //Included Reservation.h since waiting list needs reservation info
using namespace std;

class WaitingList {
private:
    queue<Reservation> waitingList; //This creates a queue named waitingList that holds Reservation objects
public:
    void addStudent (const Reservation& reservation); //Adds student to the waiting list
    bool removeStudent (Reservation& removedStudent); //Removes student from the waiting list, bool states if removal worked or not
    void displayWaitingList() const; //Displays the waiting list
};

#endif