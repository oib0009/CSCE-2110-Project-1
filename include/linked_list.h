#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Reservation.h"

using namespace std;

// Linked list node
struct ReservationNode {
    Reservation data;
    ReservationNode* next;
    ReservationNode(const Reservation& r)
        : data(r), next(nullptr) {}
};

// Function prototypes
void printList(ReservationNode* head);
void insertAtEnd(ReservationNode** head, const Reservation& value);
void insertAtBeginning(ReservationNode** head, const Reservation& value);
bool deleteNode(ReservationNode** head, const int reservationId);
ReservationNode* findReservationNode(ReservationNode* head, int reservationId);
void printReservations(ReservationNode* head);

#endif
