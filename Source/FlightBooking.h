#include "includes.h"

#ifndef SKILAVERKEFNI4_FLIGHTBOOKING_H
#define SKILAVERKEFNI4_FLIGHTBOOKING_H


class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	int id;
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
	int getReserved();
	int getCapacity();
private:
	bool isAllowedReservation(int reservation);
	int capacity;
	int reserved;
};