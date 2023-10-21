#include <iostream>
#include "records.h"
using namespace std;

void test_1();
void test_2();

int main()
{
	// test_1();
	test_2();
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

void test_2()
{
	vector<Student> students = { Student(1,"George P. Burdell"), Student(2,"Nancy Rhodes") };
	vector<Course> courses = { Course(1,"Algebra",5), Course(2,"Physics",4), Course(3,"English",3), Course(4,"Economics",4) };
	vector<Grade> grades = { Grade(1,1,'B'), Grade(1,2,'A'), Grade(1,3,'C'), Grade(2,1,'A'), Grade(2,2,'A'), Grade(2,4,'B') };

	int id;
	string student_name;
	float student_gpa;
	cout << "Enter a student ID: ";
	cin >> id;
	for (auto& x : students)
	{
		if (x.get_id() == id)
		{
			student_name = x.get_name();
			student_gpa = x.get_gpa(grades, courses);
		}
	}
	cout << "The GPA for " << student_name << " is " << student_gpa << endl;
}
