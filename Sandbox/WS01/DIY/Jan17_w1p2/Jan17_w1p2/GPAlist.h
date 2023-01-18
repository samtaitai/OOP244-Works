#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {

	bool gpaQuery(const char* filename);
	bool loadGPAs();
	void displayRecord(const GPA* gpa);
	void displayBigger(const double mark);
	void displaySmaller(const double mark);
	void displayEqual(const double mark);

}

#endif
