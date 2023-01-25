#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

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
    
       
    void read(char* str, int len);
   
    // to be completed
    bool read(Customers& rec);
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
    void display(const Customers& c_rec);
    void display(const CustomersRecord& t_rec);
    void EmptyRecord(Customers& c_rec);
    void EmptyRecord(CustomersRecord& t_rec);





              
}

#endif 
