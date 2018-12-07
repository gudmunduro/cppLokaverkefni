#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "includes.h"


class FlightBooking {
public:
    FlightBooking(int id, int reserved, int capacity);
	void printStatus();
    // bool reserveSeats(int number_ob_seats);
    // bool canceReservations(int number_ob_seats);
    int getReserved();
    int getCapacity();
	int getId();
    void addPassanger(string ssn);
    string *getPassangerSSNs();
private:
	bool isAllowedReservation(int reservation);
	int capacity;
	int reserved;
    int id;
    string *passangerSSNs;
    int passangerCount;
};

#endif
