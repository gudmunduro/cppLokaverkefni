#include "List.h"



PersonList::PersonList() {
    first = nullptr;
    count = 0;
}

void PersonList::add(Person *person) {
    if (exists(person->getSsn())) return;

    PersonNode *node = new PersonNode();
    node->person = person;

    PersonNode *last = this->last();
    if (last == nullptr) {
        if (first == nullptr) {
            first = node;
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

bool PersonList::exists(string ssn) {
    return get(ssn) != nullptr;
}

void PersonList::loop(function< void(Person *person) > forEach) {
    PersonNode *current = first;
    while (current != nullptr) {
        forEach(current->person);
        current = current->next;
    }
}

void PersonList::remove(string ssn) {
    if (!exists(ssn)) return;
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




//---------------------------------\\
//---------FlightList--------------\\
//---------------------------------\\



FlightList::FlightList() {
    first = nullptr;
    count = 0;
}

void FlightList::add(FlightBooking *flight) {
    if (exists(flight->getId())) return;

    FlightNode *node = new FlightNode();
    node->flight = flight;

    FlightNode *last = this->last();
    if (last == nullptr) {
        if (first == nullptr) {
            first = node;
            count++;
            return;
        }
        cout << "Failed to add flight" << endl;
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

bool FlightList::exists(int id) {
    return get(id) != nullptr;
}

void FlightList::loop(function< void(FlightBooking *flight) > forEach) {
    FlightNode *current = first;
    while (current != nullptr) {
        forEach(current->flight);
        current = current->next;
    }
}

void FlightList::remove(int id) {
    if (!exists(id)) return;
    FlightNode *current = first;
    FlightNode *previous = nullptr;
    for (int i = 0; i < count; i++) {
        if (current->flight->getId() == id) {
            if (previous == nullptr) {
                first = current->next;
                return;
            }
            previous->next = (current == nullptr) ? nullptr : current->next;
            return;
        }
        previous = current;
        current = current->next;
    }
}
