/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

//#define filename_r "Filtered_Dataset.csv"

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)
	int read(char* pkgName);
	int read(int intType);
	int read(double timeInHours);
	int read(char dayOfWeek);

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
