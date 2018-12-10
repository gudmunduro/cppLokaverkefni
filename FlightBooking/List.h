#ifndef LIST_H
#define LIST_H

#include "includes.h"
#include "Person.h"
#include "FlightBooking.h"
#include <functional>
#include <fstream>
#include <QList>
#include "json.hpp"

using namespace nlohmann;

struct PersonNode {
    Person *person;
    PersonNode *next;
};

class PersonList {
private:
    PersonNode *first;
    int count;
public:
    PersonList();
    void add(Person *person);
    void remove(string ssn);
    int getCount();
    void loop(function< void(Person *person) > forEach);
    PersonNode *last();
    PersonNode *get(string ssn);
    bool exists(string ssn);
};

//---------------------------------//
//---------FlightList--------------//
//---------------------------------//




struct FlightNode {
    FlightBooking *flight;
    FlightNode *next;
};

class FlightList {
private:
    FlightNode *first;
    int count;
public:
    FlightList();
    void add(FlightBooking *flight);
    void remove(int id);
    int getCount();
    void loop(function< void(FlightBooking *flight) > forEach);
    FlightNode *last();
    FlightNode *get(int id);
    bool exists(int id);
    void save();
    void load();
};

#endif
