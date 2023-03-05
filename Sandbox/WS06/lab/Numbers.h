/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 6 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <cstring>
namespace sdds {
   class Numbers {

       double* m_collection;
       char m_filename[255];
       unsigned int m_collectionSize;
       bool m_originalFlag;
       bool m_addedFlag;

       unsigned int countLines(const char* filename);
       //void sort(double* nums, unsigned int size);
       void setEmpty();
       bool load(const char* filename);
       Numbers& save(const char* filename);
       double max() const;
       double min() const;
       double average() const;

   public:
       Numbers();
       Numbers(const char* filename);
       ~Numbers();
       Numbers(Numbers& N);
       Numbers& operator=(const Numbers& N);
       operator bool() const;
       Numbers& sort();
       Numbers& operator+=(const double value);
       std::ostream& display(std::ostream& ostr = std::cout) const;
   };

   std::ostream& operator<<(std::ostream& ostr, const Numbers& RoN);
   std::istream& operator>>(std::istream& istr, Numbers& RoN);

}
#endif // !SDDS_NUMBERS_H_

