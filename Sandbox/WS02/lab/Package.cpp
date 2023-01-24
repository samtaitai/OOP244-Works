/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Package.h"
#include "Tools.h"

using namespace std;
namespace sdds {
    int no_of_traces;
    Customers* users;
    bool ok = true;
    
    // Add: Complete the implementation of the no argument [int loadTraces()] function
    int loadTraces() {       // Do: complete the missing parts as guided (6 parts)
        bool check = true;
        int i{};
        Customers user{};
        if (openFile_r(filename_r)) {

            // Add [1]: Set the noOfTraces to the number of records found in the file.
            no_of_traces = noOfTraces();
                                   
            // Add [2]: Dynamically allocate an array of Customers into the global Customers' pointer (users) with the size of no_of_traces.
            users = new Customers[no_of_traces];

            // Add [3]: Load the Customers' records from the file into the dynamically created array (use a loop).
            if (users == nullptr) {
                cout << "Not enough memory" << endl;
            }
            else {
                while (ok && i < no_of_traces) {
                    ok = read(user.Package_Name)
                        && read(user.user_id)
                        && read(user.timeinhours)
                        && read(user.dayofyear)
                        && read(user.Fwifitime)
                        && read(user.Fctime)
                        && read(user.dayofweek);
                    if (ok) users[i++] = user;
                }

                // Add [4]: If th number of the records does not match the number of read ones, print an error message
                if (i != no_of_traces) {
                    cout << "Error reading the records, Check the data file " << endl;
                    check = false;
                }
                else {
                    // Add [5]: set  check to true 
                    check = true;
                }

                // Add [6]: close the file; call closefile() function
                closefile();
            }
            delete[] users;

        }
        else {
            cout << "Could not open the"<< filename_r <<" data file"<< endl;
        }
        return check;
    }  




    // Add: Complete the implementation of the one argument [int loadTraces(Customers& user_info)] function that does the following:
                                                  // (1). reads one student record from the file
                                                  // (2). loads the record into the customers' reference
   
    int loadTraces(Customers& user_info) {    // Do: complete the missing parts as guided (3 parts)
        bool check = false;
        char read_Package_name[50];
        char* strSize{};

        if (read(user_info.dayofweek)&& read(user_info.user_id) && read(user_info.timeinhours) && read(user_info.dayofyear) && read(user_info.Fwifitime)  
            && read(user_info.Fctime) && read(read_Package_name)) { // if reading of data

           // Add [1]: allocate memory to the size of the Package_name + 1, keep its address in the name of the customers reference (user_info.Package_Name)
            
            strSize = new char[strlen(read_Package_name) + 1];
            if (strSize != nullptr) {
                // Add [2]:  copy the name into the newly allocated memory, use provided strCpy function
                strcpy(strSize, read_Package_name);

                // Add [3]: set  check to true if the previous process is successfully completed
                check = true;
            }
            else {
                cout << "Not enough memory";
                check = false;
            }
        }
        delete[] strSize;
        return check; 
    }

    
    void grouptTraces() {  // Fully provided
        int i, j;
        Customers temp_record;
        for (i = no_of_traces - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (users[j].user_id > users[j + 1].user_id) {
                    temp_record = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp_record;
                }
            }
        }
    } 


    // ADD [1]: implement the display function based on the following condition: (timeinhours > 1.0 and dayofweek == 'F') 


         
    
    // ADD [2]: implement the deallocateMemory function  

        

}


