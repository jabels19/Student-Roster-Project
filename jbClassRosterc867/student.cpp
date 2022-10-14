#include "student.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

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

Student::Student()
{
	this->ID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->studentAge = "";
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = DegreeProgram::UNDECIDED;
};

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, string studentAge, int daysToComplete[], DegreeProgram program)
{
	this->ID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = program;
}


//get student data
string Student::getID(){
	return ID;
}
string Student::getfirstName(){
	return firstName;
}
string Student::getlastName(){
	return lastName;
}
string Student::getemail(){
	return email;
}
string Student::getstudentAge(){
	return studentAge;
}
int* Student::getDaysToComplete(){
	return daysToComplete;
}
DegreeProgram Student::getDegreeProgram(){
	return degreeProgram;
}

//set student data
void Student::setStudentID(string ID){
	this->ID = ID;
}
void Student::setFirstName(string firstName){
	this->firstName = firstName;
}
void Student::setLastName(string lastName){
	this->lastName = lastName;
}

void Student::setEmailAddress(string email){
	this->email = email;
}
void Student::setstudentAge(string studentAge){
	this->studentAge = studentAge;
}
void Student::setDaysToComplete(int daysToComplete[]){

	for (int i = 0; i < numCourses; i++) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegreeProgram(DegreeProgram degree){
	this->degreeProgram = degree;
}

void Student::print(){

	//\t = tab
	cout << "Student ID: " << ID <<  "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tEmail: " << email << "Age: " << studentAge << "\tDays In Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}";
	cout << "\tDegree Program: " << DegreeProgramStrings[getDegreeProgram()] << endl;
}

Student::~Student(){

};