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
#include "UI.h"

using namespace std;
using namespace sdds;

namespace sdds {

	GPA gpaData[86];

	bool gpaQuery(const char* filename) {
		/*
        load data function{
            //open file
            //fill data
            //close file
        }         
        */
        loadGPAs();

        //enter query
        queryEntry();

        //compare query
        /*if matching,
            display query
        */
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
                if (ok) gpaData[mnum++] = gpa;
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
            if (gpaData[i].gpa > mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpaData[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

    void displaySmaller(const double mark) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (gpaData[i].gpa < mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpaData[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

    void displayEqual(const double mark) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (gpaData[i].gpa == mark) {
                cout << "[" << j++ << "] ";
                displayRecord(&gpaData[i]);
            }
        }
        if (j == 1) {
            cout << "No data" << endl;
        }
    }

}