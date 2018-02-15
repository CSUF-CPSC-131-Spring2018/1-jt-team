#include "Student.h"

#include <iostream>

Student::Student() {
	cwid = " "; // Initialize string cwid to blank
	nCourses = 0; // Set int nCourses to 0
}

Student::Student(const string &pcwid) {
	cwid = pcwid; // Initialize the reference input to cwid
	nCourses = 0; // Set int nCourses to 0
}

string Student::getCWID() {
	return cwid;
}

void Student::addCourseGrade (const string &courseName, char grade) {
	// TO BE COMPLETED

}

double Student::getGPA() {
	// Calculate the GPA by doing the following:
	// 1. Multiply each numeric grade by number of credits worth.
	// 2. Add all the numbers to get the total sum and recast it to double.
	// 3. Divide the sum by number of classes taken to get the GPA.

}

// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121		C
// CS 253		B
// CS 131		B
// GPA = 2.6667
void Student::printTranscript() {
	for (int j = 0; j < nCourses; j++)
	{
		// Display the student's transcript containing
		// the courses taken, grade, and the GPA.
	}
}

