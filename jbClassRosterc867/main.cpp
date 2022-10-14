#include <iostream>
#include "roster.h"
#include "student.h"
using std::cout;
using std::endl;


int numStudents = 5;
static string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Black,Joel,jbla480@wgu.edu,28,8,17,23,SOFTWARE"
};

int main() {


	cout << "WGU C867: Programmng and Scripting Applications" << endl;
	cout << "Written in C++" << endl;
	cout << "WGU ID: 003122265" << endl;
	cout << "Joel Black" << endl;

	//new roster
	Roster* classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; i++){
		classRoster->parseAdd(studentData[i]);
	}

	cout << "Print all:" << endl;
	classRoster->print_All();

	//Printing invalid emails
	cout << "\n\n"; //new line
	classRoster->printInvalidEmail();

	//Printing the average days
	cout << "\n\n";
	cout << "Print all student's average days\n";


	for (int i = 1; i <= numStudents; i++){
		classRoster->printAverageDays("A" + std::to_string(i));
		cout << endl;
	}

	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing A3" << endl;
	if (classRoster->remove("A3")) {
		classRoster->print_All();
		numStudents--;
	}
	else cout << "Student not found" << endl;

	cout << "Remove A3" << endl;
	if (classRoster->remove("A3")) {
		classRoster->print_All();
	}
	else {
		cout << "Student not found" << endl;
	}

	classRoster->~Roster();

}

