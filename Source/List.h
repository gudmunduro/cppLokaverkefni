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
public:
    PersonList();
    void add();
    void remove();
    int count();
    PersonNode *get(int id);
};

struct FlightNode {
    FlightBooking *flight;
    FlightNode *next;
};

class FlightList {
private:
    FlightNode *first;
public:
    FlightList();
    void add();
    void remove();
    int count();
    FlightNode *get(int id);
};