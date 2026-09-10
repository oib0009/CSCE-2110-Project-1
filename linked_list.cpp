#include "linked_list.h"
#include <iostream>
using namespace std;

// Insert at end of list
void insertAtEnd(ReservationNode** head, const Reservation& value) {
    ReservationNode* newNode = new ReservationNode(value);

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    ReservationNode* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert at beginning of list
void insertAtBeginning(ReservationNode** head, const Reservation& value) {
    ReservationNode* newNode = new ReservationNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Delete a reservation by ID
bool deleteNode(ReservationNode** head, const int reservationId) {
    if (*head == nullptr) return false;

    ReservationNode* current = *head;
    ReservationNode* previous = nullptr;

    while (current != nullptr && current->data.reservationId != reservationId) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return false; // Not found

    if (previous == nullptr) {
        *head = current->next; // deleting head
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}

// Find a reservation node by ID
ReservationNode* findReservationNode(ReservationNode* head, int reservationId) {
    ReservationNode* current = head;

    while (current != nullptr) {
        if (current->data.reservationId == reservationId) {
            return current;
        }
        current = current->next;
    }

    return nullptr; // Not found
}

// Print full reservation details
void printReservations(ReservationNode* head) {
    ReservationNode* current = head;

    while (current != nullptr) {
        cout << "Reservation ID: " << current->data.reservationId << endl;
        cout << "Student ID: " << current->data.studentId << endl;
        cout << "Student Name: " << current->data.studentName << endl;
        cout << "Resource ID: " << current->data.resourceId << endl;
        cout << "Date: " << current->data.reservationDate << endl;
        cout << "-----------------------------\n";

        current = current->next;
    }
}

// Optional simple print (IDs only)
void printList(ReservationNode* head) {
    ReservationNode* current = head;

    while (current != nullptr) {
        cout << current->data.reservationId << " ";
        current = current->next;
    }
    cout << endl;
}
