/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 17 2023
*/
#include <iostream>
#include <cstdio>
#include "File.h"

namespace sdds {

	FILE* fptr;           

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    //read student name(string)
    bool readName(char sname[]) {
    return fscanf(fptr, "%[^,],", sname) == 1;
    }

    //read student number(int)
    bool readStudentNumber(int* snumber) {
        return fscanf(fptr, "%d)", snumber) == 1;
    }

    //read student GPA(double)
    bool readGPA(double* GPA) {
        return fscanf(fptr, "%lf)", GPA) == 1;
    }

}