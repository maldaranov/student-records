#include <iostream>
#include <fstream>
#include "records.h"
using namespace std;

void read_records(StudentRecords &sr);
void read_courses(StudentRecords& sr);
StudentRecords sr;
int main()
{
	ifstream ifp;
	read_records(sr);
	sr.print_students();
	sr.print_courses();
	return (0);
}

void read_records(StudentRecords &sr)
{
	ifstream ifp;

	// read the student records
	ifp.open("students.txt");
	if (ifp.fail())
	{
		cout << "Failed to open the file!" << endl;
	}
	else
	{
		string student_id;
		string student_name;
		while (!ifp.eof())
		{
			getline(ifp, student_id);
			getline(ifp, student_name);
			sr.add_student(stoi(student_id), student_name);
		}
	}
	ifp.close();
	ifp.clear();

	// read the course records
	ifp.open("courses.txt");
	if (ifp.fail())
	{
		cout << "Failed to open the file!" << endl;
	}
	else
	{
		string course_id;
		string course_name;
		string credits;
		while (!ifp.eof())
		{
			getline(ifp, course_id);
			getline(ifp, course_name);
			getline(ifp, credits);
			sr.add_course(stoi(course_id), course_name, (unsigned char)(credits[0]));
		}
	}
	ifp.close();
	ifp.clear();

	// read the grade records
	ifp.open("grades.txt");
	if (ifp.fail())
	{
		cout << "Failed to open the file!" << endl;
	}
	else
	{
		string student_id;
		string course_id;
		string grade;
		while (!ifp.eof())
		{
			getline(ifp, student_id);
			getline(ifp, course_id);
			getline(ifp, grade);
			sr.add_grade(stoi(student_id), stoi(course_id), (unsigned char)(grade[0]));
		}
	}
	ifp.close();
	ifp.clear();
}
