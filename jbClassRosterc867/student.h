#pragma once
#include "degree.h"
#include <string>
using std::string;

/*For the Student class, do the following:

1.  In files student.h and student.cpp create the Student class, which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
2. Create each of the following functions in the Student class:
a. an accessor (i.e., getter) for each instance variable from part D1
b. mutator (i.e., setter) for each instance variable from part D1
c. All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d. constructor using all of the input parameters provided in the table
e. print() to print specific student data*/

class Student
{
public:
	const static int numCourses = 3;

protected:
	string ID;
	string firstName;
	string lastName;
	string email;
	string studentAge;
	int daysToComplete[numCourses];
	DegreeProgram degreeProgram;

public:

	//empty constructor
	Student();

	//constructor
	Student(string ID, string firstName, string lastName, string emailAddress, string studentAge, int daysToComplete[], DegreeProgram program);

	//getters / accessors
	string getID();
	string getfirstName();
	string getlastName();
	string getemail();
	string getstudentAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//stters / mutators
	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setstudentAge(string studentAge);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degree);

	void print();

	//deconstructor
	~Student();
};