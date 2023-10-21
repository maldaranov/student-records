#include "records.h"
using namespace std;

Student::Student(int the_id, string the_name)
{
	id = the_id;
	name = the_name;
}
int Student::get_id()
{
	return id;
}
string Student::get_name()
{
	return name;
}

Course::Course(int the_id, string the_name, unsigned char the_credits)
{
	id = the_id;
	name = the_name;
	credits = the_credits;
}
int Course::get_id()
{
	return id;
}
string Course::get_name()
{
	return name;
}
int Course::get_credits()
{
	return credits;
}

Grade::Grade(int the_student_id, int the_course_id, unsigned char the_grade)
{
	student_id = the_student_id;
	course_id = the_course_id;
	grade = the_grade;
}
int Grade::get_student_id()
{
	return student_id;
}
int Grade::get_course_id()
{
	return course_id;
}
unsigned char Grade::get_grade()
{
	return grade;
}

void StudentRecords::add_student(int student_id, string student_name)
{
	students.push_back(Student(student_id, student_name));
}
void StudentRecords::add_course(int course_id, string course_name, unsigned char credits)
{
	courses.push_back(Course(course_id, course_name, credits));
}
void StudentRecords::add_grade(int student_id, int course_id, unsigned char grade)
{
	grades.push_back(Grade(student_id, course_id, grade));
}
float StudentRecords::get_numeric_grade(unsigned char grade)
{
	switch (grade)
	{
	case 'A':
		return 4.0f;
		break;
	case 'B':
		return 3.0f;
		break;
	case 'C':
		return 2.0f;
		break;
	case 'D':
		return 1.0f;
		break;
	default:
		return 0.0f;
		break;
	};
}
string StudentRecords::get_student_name(int student_id)
{
	for (auto& x : students)
	{
		if (x.get_id() == student_id)
		{
			return x.get_name();
		}
	}
}
unsigned char StudentRecords::get_course_credits(int course_id)
{
	for (auto& x : courses)
	{
		if (x.get_id() == course_id)
		{
			return x.get_credits();
		}
	}
}