#include <linked_list.h>
#include <iostream>
#include <string>

using namespace std;
//Initializing the linked list structure//
struct ReservationNode {
    int data;
    ReservationNode* next;

    ReservationNode(int value) : data(value), next(nullptr) {}
};

// Creating a linked list to store active reservations.

void printList(ReservationNode* head) {
    ReservationNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertAtEnd(ReservationNode** head, int value) {
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

void insertAtBeginning(ReservationNode** head, int value) {
    ReservationNode* newNode = new ReservationNode(value);
    newNode->next = *head;
    *head = newNode;
}

bool deleteNode(ReservationNode** head, int value) {
    if (*head == nullptr) return false;

    ReservationNode* current = *head;
    ReservationNode* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return false; // Value not found

    if (previous == nullptr) {
        *head = current->next; // Deleting the head node
    } else {
        previous->next = current->next; // Bypass the node to delete
    }
    delete current;
}

void findNode(ReservationNode* head, int value) {
    ReservationNode* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Found: " << value << endl;
            return;
        }
        current = current->next;
    }
    cout << "Not Found: " << value << endl;
}
// create a loop that prints all reservation items in linked list//

void printReservations(ReservationNode* head) {
    ReservationNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



int main() {
    return 0;
}