#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid
Student& Registrar::getStudent(string pcwid) const {
	// First, check whether an invalid cwid exists.
	// If it does, then throw an exception with an error message.
	Student *ptr;
	ptr = head;
	bool found;
	found = false;

	while ((ptr != NULL) && (found == false))
	{
		if (ptr->getCWID() == pcwid)
		{
			found = true;
		}
		else
		{
			throw invalid_argument("Invalid CWID");
		}
	}
	if (found == true)
	{
		return *ptr;
	}
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {
	// Check whether the student's cwid does not exist.
	// If it doesn't, then create a new student object.
}

