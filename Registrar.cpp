#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

Registrar::Registrar()
{
	numStudents = 0;	// set numStudents to 0
	head = nullptr;		// set head to nullptr
}

Registrar::~Registrar()
{
}

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
	// First, use the bool found to check whether an invalid cwid exists.
	// If it does, then throw an exception with an error message.
	// Otherwise, return the pointer and set the bool found to true.
	Student *ptr;
	ptr = head;
	bool found;
	found = false;

	// Check while the node pointer is not pointing to null
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
	// Assume the text files being read are valid.
	// As long as the pointer is not pointing to the end of file or NULL,
	// process each line with the courseName, cwid, and grade.
	Student &s = getStudent(pcwid);
	if (s.getCWID() == pcwid)
	{
		s.addCourseGrade(courseName, grade);
	}
	else
	{
		Student *s0 = new Student(pcwid);
		s0->setNext(head);
		head = s0;
		s0->addCourseGrade(courseName, grade);
	}
}
