#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete

    
    void EmptyRecord(Customers& c_rec) {
        c_rec.user_name; //???
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

    /*
    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    */
    // complete
    bool read(Customers& rec) {
        char name[21];
        int retweet{};
        int likes{};
        int replies{};
        char shareV{};
        bool done = true;

        cout << "Enter User name: ";
        read(name, 21);
        cout << "Enter likes_count: ";
        cin >> retweet;
        cout << "Enter retweets_count: ";
        cin >> likes;
        cout << "Enter User replies_count: ";
        cin >> replies;
        cout << "Enter User share videos (y/n): ";
        cin >> shareV;

    }
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        //t_rec = new Customers[]; how to know? 
    }
    void display(const Customers& c_rec) {
        
    }
    void display(const CustomersRecord& t_rec) {
    }
    
   

  }

