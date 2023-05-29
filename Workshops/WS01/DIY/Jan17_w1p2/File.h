/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 21 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
and assignments.
*/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {
	
	bool openFile(const char* filename);
	void closeFile();
	bool readName(char sname[]);
	bool readStudentNumber(int* snumber);
	bool readGPA(double* GPA);
}

#endif
