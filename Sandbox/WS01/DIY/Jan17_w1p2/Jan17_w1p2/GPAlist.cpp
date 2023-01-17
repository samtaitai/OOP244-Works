/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 17 2023
*/
#include <iostream>
#include "GPAlist.h"
#include "GPA.h"
#include "File.h"
using namespace sdds;
using namespace std;

namespace sdds {

	GPA gpas[86];

	bool gpaQuery(const char* filename) {
		//body
	}

    bool loadGPAs() {
        GPA gpa;
        int mnum = 0; // number of movies read
        bool ok = true;
        if (openFile("students.csv")) {
            while (ok && mnum < 86) {
                ok = readName(gpa.name) &&
                    readStudentNumber(&gpa.stno) &&
                    readGPA(&gpa.gpa);
                if (ok) gpas[mnum++] = gpa;
            }
            closeFile();
        }
        return mnum == 86;
    }

    //displays single record 
    //output 362030: 3.7 (Chazz Busby)
    void displayRecord(const GPA* gpa) {
        int i = 1;
        cout << gpa->stno << ": " << gpa->gpa << " (" << gpa->name << ")" << endl;
    }

    //display records which gpa bigger than mark? 
    void displayBigger(const double mark) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (gpas[i].gpa > mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpas[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

    void displaySmaller(const double mark) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (gpas[i].gpa < mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpas[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

    void displayEqual(const double mark) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (gpas[i].gpa == mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpas[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

}