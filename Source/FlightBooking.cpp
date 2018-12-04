#include "FlightBooking.h"

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (!isAllowedReservation(reserved))
	{
		throw invalid_argument("Reserved value above capacity");
	}
	if (reserved < 0) reserved = 0; // Ef �a� er � m�nus breytist �a� � n�ll
	this->reserved = reserved;
}
void FlightBooking::printStatus()
{
	const float seatsReserved = ((float)reserved) / ((float)capacity) * 100.0f;
	cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << seatsReserved << "%) seats reserved" << endl;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (isAllowedReservation(number_ob_seats + reserved) && number_ob_seats >= 0) // Ef ni�ursta�an eftir breytingar er leyfileg og talan sem var sett inn er ekki � m�nus
	{
		reserved += number_ob_seats;
		return true;
	}
	return false;
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
	if (reserved - number_ob_seats >= 0 && number_ob_seats >= 0) // Ef ni�ursta�an eftir breytingu ver�ur h�rri en n�ll og talan sem var sett inn er ekki � m�nus
	{
		reserved -= number_ob_seats;
		return true;
	}
	return false;
}
bool FlightBooking::isAllowedReservation(int reservation)
{
	return ((float)reservation) / ((float)capacity) < 1.05; // Skilar true e�a false eftir �v� hvort �a� s� yfir leyfilega magninu sem er 105%
}

int FlightBooking::getReserved() {
	return reserved;
}

int FlightBooking::getCapacity() {
	return capacity;
}
int FlightBooking::getId() {
    return id;
}