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
float Student::get_gpa(vector<Grade>& grades)
{
	float grades_size = grades.size();
	float grade_total = 0.0f;
	for (Grade& x : grades)
	{
		grade_total += (float)x.get_grade();
	}
	return grade_total / grades_size;
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