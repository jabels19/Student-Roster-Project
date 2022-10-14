#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster
{
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
public:
	
	Roster();
	Roster(int capacity);

	void parseAdd(string datarow);
	void print_All();
	bool remove(string studentID);
	void printAverageDays(string studentID);
	void printInvalidEmail();
	void printByDegreeProgram(DegreeProgram d);

	//Deconstructor
	~Roster();
};