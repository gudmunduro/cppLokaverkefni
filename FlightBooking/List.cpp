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
            if (previous == nullptr) {
                first = current->next;
                count--;
                return;
            }
            previous->next = current->next;
            count--;
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
                count--;
                return;
            }
            previous->next = (current == nullptr) ? nullptr : current->next;
            count--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void FlightList::save()
{
    ifstream file("data.json");
    json data;
    if (file.peek() == std::ifstream::traits_type::eof()) data = json::object();
    else file >> data;
    data["flights"] = json::array();

    FlightNode* current = first;
    while (current != nullptr)
    {
        json passengerArray = json::array();
        for (string passenger : current->flight->getPassangerSSNs())
        {
            passengerArray.push_back(passenger);
        }
        json currentFlight = {
            {"id", current->flight->getId()},
            {"reserved", current->flight->getReserved()},
            {"capacity", current->flight->getCapacity()},
            {"passengers", passengerArray}};

        data["flights"].push_back(currentFlight);

        current = current->next;
    }

    ofstream fileOut("data.json");
    fileOut << data;
}

void FlightList::load()
{
    ifstream file("data.json");
    if (file.peek() == std::ifstream::traits_type::eof()) return;
    json data;
    file >> data;
    if (data.empty() || data.is_null()) return;
    if (!data["flights"].is_array()) return;
    for (auto& el : data["flights"]) {
        int id = el["id"];
        int reserved = el["reserved"];
        int capacity = el["capacity"];
        QList<string> passengers = QList<string>();
        for (auto& passenger : el["passengers"]) {
            passengers.push_back(passenger);
        }
        add(new FlightBooking(id, reserved, capacity, passengers));
    }
}
