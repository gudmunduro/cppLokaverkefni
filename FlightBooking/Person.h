#ifndef PERSON_H
#define PERSON_H

#include "includes.h"

class Person {
private:
	string ssn;
	string name;
	int age;
public:
	Person(string ssn, string name, int age);
	string getSsn();
	string getName();
    int getAge();
    string getInfo();
};

#endif
