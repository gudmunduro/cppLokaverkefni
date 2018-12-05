#include "includes.h"
#include "Person.h"
#include "FlightBooking.h"

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
    PersonNode *last();
    PersonNode *get(string ssn);
};

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
    FlightNode *last();
    FlightNode *get(int id);
};
