#include <iostream>
#include "records.h"
using namespace std;

void test_1();

int main()
{
	test_1();
}

void test_1()
{
	Student s1(1, "Maxim Aldaranov");
	Course c1(15, "C++ 101", 3);
	Grade g1(1, 15, 'A');
	cout << "Student Name: " << s1.get_name() << endl;
	cout << "Course: " << c1.get_name() << endl;
	cout << "Credits: " << c1.get_credits() << endl;
	cout << "Grade: " << g1.get_grade() << endl;
}
