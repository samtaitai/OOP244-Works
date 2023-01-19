#ifndef SDDS_FILE_H
#define SDDS_FILE_H

struct GPA;

namespace sdds {

	bool gpaQuery(const char* filename);
	bool loadGPAs(const char* filename)
	void displayRecord(const GPA* gpa);
	void displayBigger(const double mark);
	void displaySmaller(const double mark);
	void displayEqual(const double mark);

}

#endif
