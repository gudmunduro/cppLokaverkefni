#include "includes.h"


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