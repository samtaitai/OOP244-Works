/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 21 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
and assignments.
*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "File.h"
#include "UI.h"
#include "GPAlist.h"
#include "GPA.h"
#define AMPLESIZE 512


using namespace std;
using namespace sdds;

namespace sdds {

	GPA gpaData[AMPLESIZE];

    /*void flushkeys() {
        while (cin.get() != '\n');
    }*/

    //open file, if success, fill gpaData, then close file
    //only if all filled successful, returns true
    bool loadGPAs(const char* filename) {
        GPA gpa;
        int mnum = 0; // number of movies read
        bool ok = true;
        if (openFile(filename)) {
            while (ok && mnum < 86) {
                ok = readName(gpa.name) &&
                    readStudentNumber(&gpa.stno) &&
                    readGPA(&gpa.gpa);
                if (ok) gpaData[mnum++] = gpa;
            }
            closeFile();
        }
        /*else {
            cout << "Opening a file failed" << endl;
        }*/
        return mnum == 86; //if something goes wrong, it won't be 86; hence false 
    }

    void sort(struct GPA data[], int list[], int count) {

        int i, j, minIdx = 0;
        int temp = 0;
        struct GPA tempGPA;

        for (i = 0; i < count; i++)
        {
            minIdx = i;

            for (j = i + 1; j < count; j++)
            {
                if (list[j] < list[minIdx])
                {
                    minIdx = j;
                }
            }

            if (minIdx != i)
            {
                temp = list[i];
                list[i] = list[minIdx];
                list[minIdx] = temp;

                tempGPA = data[i];
                data[i] = data[minIdx];
                data[minIdx] = tempGPA;
            }
        }
    }

    //call loadGPAs(open file, fill data, close file)
    //if loadGPAs success, receive input 
	bool gpaQuery(const char* filename) {
		
        bool result = true;

        //open file, fill data, close file successful for all 86 cases, 
        //call queryEntry        
        if (loadGPAs(filename)) {
            //gpaData is filled and accessible
            //generate int array for sorting 
            int stNumbers[AMPLESIZE]; 
            int dataCount = 0;
            for (int i = 0; i < AMPLESIZE; i++) {
                if (gpaData[i].stno != 0) {
                    stNumbers[i] = gpaData[i].stno;
                    dataCount++;
                }
            }
            sort(gpaData, stNumbers, dataCount);
            menu();
        }
        else {
            result = false;
        }
        return result; 
	}



    //displays single record; nested inside of others 
    //output 362030: 3.7 (Chazz Busby)
    void displayRecord(const GPA* gpa) {
        //int i = 1;
        //cout << gpa->stno << ": " << gpa->gpa << " (" << gpa->name << ")" << endl;
        printf("%d: %.1lf", gpa->stno, gpa->gpa);
        printf(" (");
        printf("%s", gpa->name);
        printf(")\n");
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