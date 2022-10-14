#include "roster.h"
using std::cout;
using std::cerr; //standard error stream
using std::endl;

const int numStudents = 5;
string studentData[numStudents] =
{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Black,Joel,jbla480@wgu.edu,28,8,17,23,SOFTWARE"
};

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::parseAdd(string row)
{
	if (lastIndex < capacity)
	{
		lastIndex++;

		int dArray[Student::numCourses];

		if (row.back() == 'Y')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::SECURITY);
		}
		else if (row.back() == 'K')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::NETWORK);
		}
		else if (row.back() == 'E')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::SOFTWARE);
		}
		else if (row.back() == 'D')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::UNDECIDED);
		}
		else
		{
			cerr << "Invalid" << endl;
			exit(-1);
		}
		

		//all code below finds certain char and subtracts to gets remaining 
		//get ID, finds ',' and takes from right hand side
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//get first name, finds next ',' and subtracts left hand side
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//get last name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//get email address
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//get age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setstudentAge(studentData[lastIndex].substr(lhs, rhs - lhs));

		//get days to complete
		//stoi converts to integer
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//get all days
		classRosterArray[lastIndex]->setDaysToComplete(dArray);

	}
	else{
		cerr << "Error" << endl;
		exit(-1);
	}

}

void Roster::print_All(){
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

//for loop looks for ID, if found = studentID
bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++){
		if (this->classRosterArray[i]->getID() == studentID){    //if getID = studentID return found
			found = true;
			//if ID not found it deletes it
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printAverageDays(string studentID){
	bool found = false;
	for (int i = 0; i <= lastIndex; i++){
		if (this->classRosterArray[i]->getID() == studentID){
		
			found = true;
			int* days = classRosterArray[i]->getDaysToComplete();
			//gets avg number of days by adding 3 days it took to complete and divide by 3
			cout << "Average number of days: " << studentID  << (days[0] + days[1] + days[2]) / 3 << "." << endl;
		}
	}
	//if studentID not found print ou message
	if (!found) cout << "Student not found" << endl;
}

void Roster::printInvalidEmail(){
	cout << "Invalid email addresses: " << endl;

	//imail = invalid email
	for (int i = 0; i <= lastIndex; i++){
		bool any = false;
		string imail = classRosterArray[i]->getemail();

		//looking for blank space in email address
		for (int j = 0; j < classRosterArray[i]->getemail().length(); j++){
			if (imail[j] == ' '){
				cout << '"' << imail << '"' << " is an invalid, cannot have a blank space" << endl;
			}
		}
		//looking for @ symbol in address
		if (imail.find("@") == string::npos){
			cout << '"' << classRosterArray[i]->getemail() << '"' << " is an invalid, missing '@'";
		}
		//looing for period in address
		else if (imail.find(".") == string::npos){
			cout << '"' << classRosterArray[i]->getemail() << '"' << " is an invalid, missing a '.'";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram d){
	cout << "Students with degree type: " << DegreeProgramStrings[d] << endl;
	for (int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->getDegreeProgram() == d){
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster(){
}