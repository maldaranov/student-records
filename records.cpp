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
float Student::get_gpa(vector<Grade>& grades, vector<Course>& courses)
{
	float credits = 0.0f;
	float points = 0.0f;
	for (auto& x : grades)
	{
		if (x.get_student_id() == id)
		{
			float numeric_grade;
			// extract the numeric grade
			switch (x.get_grade())
			{
			case 'A':
				numeric_grade = 4.0f;
				break;
			case 'B':
				numeric_grade = 3.0f;
				break;
			case 'C':
				numeric_grade = 2.0f;
				break;
			case 'D':
				numeric_grade = 1.0f;
				break;
			default:
				numeric_grade = 0.0f;
				break;
			};
			
			for (auto& y : courses)
			{
				if (y.get_id() == x.get_course_id())
				{
					credits += y.get_credits();
					points += numeric_grade * y.get_credits();
				}
			}
		}
	}
	return points / credits;
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