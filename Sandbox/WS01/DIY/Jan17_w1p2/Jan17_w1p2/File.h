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
