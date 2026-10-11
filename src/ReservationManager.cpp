// Reservation manager implementation
#include "../include/ReservationManager.h"
#include "../include/Resource.h"
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace {
struct ResourceUsage {
    int resourceId;
    string resourceName;
    int reservationCount;
};

bool appearsBefore(const ResourceUsage& left, const ResourceUsage& right) {
    if (left.reservationCount != right.reservationCount) {
        return left.reservationCount > right.reservationCount;
    }
    return left.resourceId < right.resourceId;
}

void merge(vector<ResourceUsage>& rows, vector<ResourceUsage>& buffer,
           size_t first, size_t middle, size_t last) {
    size_t left = first;
    size_t right = middle;
    size_t output = first;

    while (left < middle && right < last) {
        if (appearsBefore(rows[right], rows[left])) {
            buffer[output++] = rows[right++];
        } else {
            buffer[output++] = rows[left++];
        }
    }

    while (left < middle) {
        buffer[output++] = rows[left++];
    }
    while (right < last) {
        buffer[output++] = rows[right++];
    }

    for (size_t index = first; index < last; ++index) {
        rows[index] = buffer[index];
    }
}

void mergeSort(vector<ResourceUsage>& rows, vector<ResourceUsage>& buffer,
               size_t first, size_t last) {
    if (last - first < 2) {
        return;
    }

    const size_t middle = first + (last - first) / 2;
    mergeSort(rows, buffer, first, middle);
    mergeSort(rows, buffer, middle, last);
    merge(rows, buffer, first, middle, last);
}
}

//default const
ReservationManager::ReservationManager() {
    head = nullptr;
}
//destructor
ReservationManager::~ReservationManager() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
//to check if reservtion Id exists
bool ReservationManager::reservationIdExists(
    int reservationId) const {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    return found != nullptr;
}
//validate reservation
bool ReservationManager::validateReservation(
    const Reservation& reservation) const {
    if (!reservation.hasValidData()) {
        cout << "Invalid reservation data." << endl;
        return false;
    }
    if (reservationIdExists(reservation.reservationId)) { //prevents duplicate id
        cout << "Reservation ID already exists." << endl;
        return false;
    }
    return true;
}
//add new reservation
bool ReservationManager::addReservation(
    const Reservation& reservation) {
    if (!validateReservation(reservation)) { //validate before adding
        return false;
    }
    insertAtEnd(&head, reservation);
    cout << "Reservation created successfully." << endl;
    return true;
}
//cancel reservation
bool ReservationManager::cancelReservation(
    int reservationId) {
    ReservationNode* found =                           //find reservation firsr
        findReservationNode(head, reservationId);
    if (found == nullptr) {
        cout << "Reservation not found." << endl;

        return false;
    }
    
    bool removed =
        deleteNode(&head, reservationId);
    if (removed) {
        cout << "Reservation cancelled successfully." << endl;
        return true;
    }
    return false;
}
//to find reservation by id
Reservation* ReservationManager::findReservation(
    int reservationId) {
    ReservationNode* found =
        findReservationNode(head, reservationId);
    if (found == nullptr) {
        return nullptr;
    }
    return &(found->data);
}
//display all active reservations
void ReservationManager::displayActiveReservations() const {
    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }
    printReservations(head);
}
//couunt active reservations
int ReservationManager::getActiveReservationCount() const {
    int count = 0;
    ReservationNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void ReservationManager::displayResourceUtilization() const {
    const vector<Resource>& resources = Resource::getResources();
    unordered_map<int, int> reservationCounts;

    for (ReservationNode* current = head; current != nullptr;
         current = current->next) {
        ++reservationCounts[current->data.resourceId];
    }

    vector<ResourceUsage> rows;
    rows.reserve(resources.size());
    for (const Resource& resource : resources) {
        rows.push_back({resource.getResourceId(), resource.getResourceName(),
                        reservationCounts[resource.getResourceId()]});
    }

    vector<ResourceUsage> buffer(rows.size());
    mergeSort(rows, buffer, 0, rows.size());

    cout << left << setw(14) << "Resource ID"
         << setw(28) << "Resource Name"
         << "Reservations\n";
    cout << string(55, '-') << '\n';
    for (const ResourceUsage& row : rows) {
        cout << left << setw(14) << row.resourceId
             << setw(28) << row.resourceName
             << row.reservationCount << '\n';
    }
}
