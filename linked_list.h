#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
using namespace std;

// Reservation structure (matches project requirements)
struct Reservation {
    int reservationId;      // Unique reservation ID
    int studentId;          // Student ID
    string studentName;     // Student name
    int resourceId;         // Resource being reserved
    string reservationDate; // Date of reservation
};

// Linked list node
struct ReservationNode {
    Reservation data;
    ReservationNode* next;

    ReservationNode(const Reservation& r) : data(r), next(nullptr) {}
};

// Function prototypes
void printList(ReservationNode* head);
void insertAtEnd(ReservationNode** head, const Reservation& value);
void insertAtBeginning(ReservationNode** head, const Reservation& value);
bool deleteNode(ReservationNode** head, const int reservationId);
ReservationNode* findReservationNode(ReservationNode* head, int reservationId);
void printReservations(ReservationNode* head);

#endif
