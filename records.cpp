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