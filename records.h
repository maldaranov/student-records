#pragma once

#include <string>

class Student
{
private:
	int id;
	std::string name;

public:
	Student(int the_id, std::string the_name);
	int get_id();
	std::string get_name();
};

class Course
{
private:
	int id;
	std::string name;
	unsigned char credits;
};