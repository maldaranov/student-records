#include <iostream>
#include "records.h"
using namespace std;

void initialize_records();
StudentRecords record_1;

int main()
{
	return 0;
}

void initialize_records()
{
	record_1.add_student(1, "John Smith");
	record_1.add_student(2, "Peter Parker");

	record_1.add_course(1, "Algebra", 5);
	record_1.add_course(2, "Physics", 4);
	record_1.add_course(3, "English", 3);
	record_1.add_course(4, "Economics", 4);

	record_1.add_grade(1, 1, 'B');
	record_1.add_grade(1, 2, 'A');
	record_1.add_grade(1, 3, 'C');
	record_1.add_grade(2, 1, 'A');
	record_1.add_grade(2, 2, 'A');
	record_1.add_grade(2, 4, 'B');
}
