/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 26 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"
using namespace sdds;

namespace sdds {

    // complete

    
    void EmptyRecord(Customers& c_rec) {
        strCpy(c_rec.user_name, "\0"); //because it was static memory cstring! 
        c_rec.retweets_count = 0;
        c_rec.likes_count = 0;
        c_rec.replies_count = 0;
        c_rec.share_videos = 0;

    }
    void EmptyRecord(CustomersRecord& t_rec) {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    // complete
    bool read(Customers& rec) {
        char name[21]{};
        bool check = true;

        cout << " Enter User name: ";
        read(name, 21);     //not 20
        strCpy(rec.user_name, name); //copy
        //cout << "Let's see.." << rec.user_name << endl; ok 

        if (rec.user_name[0] != 0) { //if receiving name successful, 
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }
        else {              //if name inputting goes wrong OR user enter to quit
            check = false;
        }
        
        return check;
    }
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) { //something's wrong here
        
        int i{};
        Customers* tempPtr = nullptr;
        tempPtr = new Customers[t_rec.noOfRecords + 1]; //+1 size

        for (i = 0; i < t_rec.noOfRecords; i++) {
            tempPtr[i] = t_rec.ptr_rec[i]; //copy previous records into temp 
        }

        tempPtr[i] = c_rec; //new c_rec into the last pos 

        delete[] t_rec.ptr_rec; 
        t_rec.noOfRecords++;
        t_rec.ptr_rec = tempPtr;

        //delete[] tempPtr; created error

    }
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count
            << ", " << c_rec.share_videos << endl;
    }
    void display(const CustomersRecord& t_rec) { //I suppose it's working 
        int i{};
        for (i = 0; i < t_rec.noOfRecords; i++) {
            cout << i+1 << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
    }
  }

