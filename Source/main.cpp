#include <iostream>
#include "FlightBooking.h"
#include "Person.h"

using namespace std;

int main()
{
	Person *person = new Person("1005612358", "Nafn", 160);
	person->printInfo();
	while (true);
	return 0;
}