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
unsigned char Course::get_credits()
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
string StudentRecords::get_course_name(int course_id)
{
	for (auto& x : courses)
	{
		if (x.get_id() == course_id)
		{
			return x.get_name();
		}
	}
}
float StudentRecords::get_gpa(int student_id)
{
	float points = 0.0f, credits = 0.0f;
	for (auto& x : grades)
	{
		if (x.get_student_id() == student_id)
		{
			unsigned char tmp_credits = get_course_credits(x.get_course_id());
			credits += tmp_credits;
			points += get_numeric_grade(x.get_grade()) * tmp_credits;
		}
	}
	return points / credits;
}
void StudentRecords::print_report(int student_id)
{
	cout << endl << "Report card for " << get_student_name(student_id) << "." << endl;
	for (auto& x : grades)
	{
		if (x.get_student_id() == student_id)
		{
			cout << get_course_name(x.get_course_id()) << ": " << x.get_grade() << endl;
		}
	}
	cout << "GPA: " << get_gpa(student_id) << endl;
}
void StudentRecords::print_students()
{
	cout << endl << "Student List: " << endl;
	for (auto& x : students)
	{
		cout << x.get_name() << endl;
	}
	cout << endl;
}
void StudentRecords::print_courses()
{
	cout << endl << "Course List: " << endl;
	cout << setw(5) << left << "ID" <<
			setw(25) << left << "Course Name" <<
			setw(15) << left << "Course Credits" << endl;
	for (auto& x : courses)
	{
		cout << setw(5) << left << x.get_id() <<
				setw(25) << left << x.get_name() <<
				setw(15) << left << x.get_credits() << endl;
	}
}
void StudentRecords::print_grades()
{
	cout << endl << "Grades: " << endl;
	cout << setw(15) << left << "Student ID" <<
			setw(15) << left << "Course ID" <<
			setw(15) << left << "Letter Grade" << endl;
	for (auto& x : grades)
	{
		cout << setw(15) << left << x.get_student_id() <<
				setw(15) << left << x.get_course_id() <<
				setw(15) << left << x.get_grade() << endl;
	}
}