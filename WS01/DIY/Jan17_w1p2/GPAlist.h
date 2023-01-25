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

	struct GPA;

	/*void flushkeys();*/
	bool loadGPAs(const char* filename);
	bool gpaQuery(const char* filename);
	void displayRecord(const GPA* gpa);
	void displayBigger(const double mark);
	void displaySmaller(const double mark);
	void displayEqual(const double mark);
	void sort(struct GPA data[], int list[], int count);

}

#endif
