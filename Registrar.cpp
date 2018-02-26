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

// destructor
Registrar::~Registrar()
{
	deleteRegistrar();
}

// Destroy the Registrar
void Registrar::deleteRegistrar()
{
	Student *nodePtr;

	// Destroy the list while the nodePtr is not at the end of the list
	while (head != nullptr)
	{
		// Let nodePtr be the head
		nodePtr = head;

		// Position the pointer to the next node
		head = nodePtr->getNext();

		// Delete the current node
		delete nodePtr;
	}
	numStudents = 0;
}

// copy constructor
Registrar::Registrar(const Registrar& r2)
{
	head = nullptr;
	Student *p2 = r2.head;
	// As long as p2 is not pointing to null,
	while (p2 != nullptr)
	{
		// Allocate p1 pointer's memory
		Student *p1 = new Student(*p2);
		// And copy the contents of the pointer
		p1->setNext(head);
		head = p1;
		p2 = p2->getNext();
	}
}

// assignment operator
Registrar& Registrar::operator=(const Registrar& r2)
{
	if (this != &r2)
	{
		deleteRegistrar();
		head = nullptr;
		Student *p2 = r2.head;
		// As long as p2 is not pointing to null,
		while (p2 != nullptr)
		{
			// Allocate p1 pointer's memory
			Student *p1 = new Student(*p2);
			// And copy the contents of the pointer
			p1->setNext(head);
			head = p1;
			p2 = p2->getNext();
		}
	}
	return *this;
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
	// Use the try/catch block to check if the student does not exist.
	// If it does not, then create a new student object and call the
	// addCourseGrade function. Otherwise, just call the getStudent
	// and the addCourseGrade functions.
	try {
		Student &s = getStudent(pcwid);
		s.addCourseGrade(courseName, grade);
	}
	catch (exception &e)
	{
		Student *s0 = new Student(pcwid);
		s0->setNext(head);
		head = s0;
		numStudents++;
		s0->addCourseGrade(courseName, grade);
	}
}
