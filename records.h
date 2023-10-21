#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student;
class Course;
class Grade;

class Student
{
private:
	int id;
	std::string name;

public:
	Student(int the_id, std::string the_name);
	int get_id();
	std::string get_name();
	float get_gpa(std::vector<Grade>& grades, std::vector<Course>& courses);
};

class Course
{
private:
	int id;
	std::string name;
	unsigned char credits;
public:
	Course(int the_id, std::string the_name, unsigned char the_credits);
	int get_id();
	std::string get_name();
	int get_credits();
};

class Grade
{
private:
	int student_id;
	int course_id;
	unsigned char grade;
public:
	Grade(int the_student_id, int the_course_id, unsigned char the_grade);
	int get_student_id();
	int get_course_id();
	unsigned char get_grade();
};