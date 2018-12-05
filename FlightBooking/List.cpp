#include "List.h"

PersonList::PersonList() {

}

void PersonList::add(Person *person) {
    PersonNode *node = new PersonNode();
    node->person = person;

    PersonNode *last = this->last();
    if (last == nullptr) {
        if (first == nullptr) {
            first == node;
            count++;
            return;
        }
        cout << "Failed to add user";
        return;
    }
    last->next = node;
    count++;
}

int PersonList::getCount() {
    return count;
}

PersonNode *PersonList::last() {
    PersonNode *current = first;
    for (int i = 0; i < count; i++) {
        if (current->next == nullptr) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

PersonNode* PersonList::get(string ssn) {
    PersonNode *current = first;
    for (int i = 0; i < count; i++) {
        if (current->person->getSsn() == ssn) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void PersonList::remove(string ssn) {
    PersonNode *current = first;
    PersonNode *previous = nullptr;
    for (int i = 0; i < count; i++) {
        if (current->person->getSsn() == ssn) {
            previous->next = current->next;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Flight

FlightList::FlightList() {

}

void FlightList::add(FlightBooking *flight) {
    FlightNode *node = new FlightNode();
    node->flight = flight;

    FlightNode *last = this->last();
    if (last == nullptr) {
        if (first == nullptr) {
            first == node;
            count++;
            return;
        }
        cout << "Failed to add flight";
        return;
    }
    last->next = node;
    count++;
}

int FlightList::getCount() {
    return count;
}

FlightNode* FlightList::last() {
    FlightNode *current = first;
    for (int i = 0; i < count; i++) {
        if (current->next == nullptr) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


FlightNode *FlightList::get(int id) {
    FlightNode *current = first;
    for (int i = 0; i < count; i++) {
        if (current->flight->getId() == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void FlightList::remove(int id) {
    FlightNode *current = first;
    FlightNode *previous = nullptr;
    for (int i = 0; i < count; i++) {
        if (current->flight->getId() == id) {
            previous->next = current->next;
            return;
        }
        previous = current;
        current = current->next;
    }
}
