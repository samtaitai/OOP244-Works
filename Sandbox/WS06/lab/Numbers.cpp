/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 5 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Numbers.h"
//#include "Utils.h"
using namespace std;
namespace sdds {
   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   //private 
   unsigned int Numbers::countLines(const char* filename) { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

   void Numbers::setEmpty()
   {
       m_collection = nullptr;
       strcpy(m_filename, "\0");
       m_collectionSize = 0;
       m_originalFlag = false;
       m_addedFlag = false;
   }

   bool Numbers::load(const char* filename)
   {
       bool success = false;
       int numOfLines{};
       int i{};
       int read{};

       delete[] m_collection;                       //delete the current collection
       m_collection = nullptr;
       numOfLines = countLines(filename);           //get no of lines of file

       if (numOfLines > 0) {                        //if file is not empty
           m_collection = new double[numOfLines];   //aloc 
           ifstream fin(filename);
           if (fin.is_open()) {                     //if ifstream obj is good
               for (i = 0; i < numOfLines; i++) {
                   fin >> m_collection[i];
                   if (fin && m_collection[i] > -99) read++;
               }
               if (numOfLines == read) {            
                   m_collectionSize = numOfLines;
                   m_originalFlag = true;
               }
               else {
                   fin.close();
                   setEmpty();
                   read = 0;
               }
           }
       }
       if (read > 0) success = true;
       return success;
   }

   Numbers& Numbers::save(const char* filename)
   {
       //If the current object is an original and new values are added to it
       if (m_originalFlag == true && m_addedFlag == true) {
           ofstream fout(filename);
           fout.setf(ios::fixed);
           fout.precision(2);
           for (unsigned int i = 0; i < m_collectionSize; i++) {
               fout << m_collection[i] << endl;
           }
       }
       return *this;
   }

   double Numbers::max() const
   {
       Numbers temp;
       temp = *this;
       temp.sort(temp.m_collection, temp.m_collectionSize);
       return temp.m_collection[m_collectionSize - 1];
   }

   double Numbers::min() const
   {
       Numbers temp;
       temp = *this;
       temp.sort(temp.m_collection, temp.m_collectionSize);
       return temp.m_collection[0];
   }

   double Numbers::average() const
   {
       double temp{};
       for (unsigned int i = 0; i < m_collectionSize; i++) {
           temp += m_collection[i];
       }
       return temp / m_collectionSize;
   }

   //constructors
   Numbers::Numbers()
   {
       setEmpty();
   }
   Numbers::Numbers(const char* filename)
   {
       setEmpty();
       strcpy(m_filename, filename);
       load(m_filename);
   }

   //destructor
   Numbers::~Numbers()
   {
       save(m_filename);
       delete[] m_collection;
   }

   //copy constructor
   Numbers::Numbers(Numbers& N)
   {
       setEmpty();
       operator=(N);
   }

   //copy assignment
   Numbers& Numbers::operator=(const Numbers& N)
   {
       if (this != &N) {
           save(m_filename);                                
           delete[] m_collection;
           setEmpty();
           if (N.m_collectionSize > 0) {
               strcpy(m_filename, N.m_filename);
               m_originalFlag = false;                      
               m_collection = new double[N.m_collectionSize];
               for (unsigned int i = 0; i < N.m_collectionSize; i++) {
                   m_collection[i] = N.m_collection[i];
               }
               m_collectionSize = N.m_collectionSize;
           }
       }
       return *this;
   }

   Numbers::operator bool() const
   {
       return m_collectionSize > 0;
   }
   Numbers& Numbers::sort()
   {
       sort(m_collection, m_collectionSize);
       return *this;
   }
   Numbers& Numbers::operator+=(const double value)
   {
       if (m_collectionSize > 0) {
           double* temp{};
           temp = new double[m_collectionSize + 1];
           for (unsigned int i = 0; i < m_collectionSize; i++) {
               temp[i] = m_collection[i];
           }
           temp[m_collectionSize] = value;
           delete[] m_collection;
           m_collection = temp;
           m_collectionSize = m_collectionSize + 1;
           m_addedFlag = true;
       }
       save(m_filename);
       sort();
       return *this;
   }
   ostream& Numbers::display(ostream& ostr) const
   {
       if (bool(*this) == false) {
           ostr << "Empty list";
       }
       else {
           ostr.setf(ios::fixed);
           ostr.precision(2);
           if (m_originalFlag == false) {
               ostr << "Copy Of ";
           }
           ostr << m_filename << endl;
           for (unsigned int i = 0; i < m_collectionSize; i++) {
               if (i < m_collectionSize - 1) {
                   ostr << m_collection[i] << ", ";
               }
               else if (i == m_collectionSize - 1) {
                   ostr << m_collection[i] << endl;
               }
               
           }
           ostr.width(76);
           ostr.fill('-');
           ostr << '\n';
           ostr << "Total of " << m_collectionSize << " number(s), Largest: "
               << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
           ostr.width(76);
           ostr.fill('=');
           ostr << '\n';
       }
       return ostr;
   }

   //helpers
   ostream& operator<<(ostream& ostr, const Numbers& RoN)
   {
       return RoN.display(ostr);
   }
   istream& operator>>(istream& istr, Numbers& RoN)
   {
       double temp{};
       if (istr) {
           istr >> temp;
           RoN += temp;
       }
       
       return istr;
   }
}