#include "Person.h"

Person::Person(string ssn, string name, int age)
{
	this->ssn = ssn;
	this->name = name;
	this->age = age;
}

void Person::printInfo()
{
	cout << name << endl << ssn << endl << age << endl;
}