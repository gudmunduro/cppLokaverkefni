#include "includes.h"

class Person {
private:
	string ssn;
	string name;
	int age;
public:
	Person(string ssn, string name, int age);

	void printInfo();
};