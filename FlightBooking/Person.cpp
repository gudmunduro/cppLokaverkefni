#include "Person.h"

Person::Person(string ssn, string name, int age)
{
	this->ssn = ssn;
	this->name = name;
	this->age = age;
}

string Person::getInfo()
{
    return name + " " + ssn + "  " + to_string(age);
}

string Person::getSsn() {
	return ssn;
}

string Person::getName() {
	return name;
}

int Person::getAge() {
    return age;
}
