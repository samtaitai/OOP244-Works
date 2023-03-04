#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Numbers.h"
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
       int numOfReads{};

       delete[] m_collection;
       m_collection = nullptr;
       numOfLines = countLines(filename);

       if (numOfLines > 0) {                        //if file is not empty
           m_collection = new double[numOfLines];
           ifstream fin(filename);
           if (fin.is_open()) {                     //if ifstream obj is good
               while (fin) {
                   fin >> m_collection[numOfReads];
                   numOfReads++;
               }
               if (numOfLines == numOfReads) {      //if read success
                   m_collectionSize = numOfLines;
                   m_originalFlag = true;
                   success = true;
               }
               else {
                   //discard all the read? 
                   fin.close();
                   setEmpty();
               }
           }
       }

       return success;
   }

   Numbers& Numbers::save(const char* filename)
   {
       //If the current object is an original and new values are added to it
       if (m_originalFlag == true) {
           ofstream fout(filename);
           fout.setf(ios::fixed);
           fout.precision(2);
           for (int i = 0; i < m_collectionSize; i++) {
               fout << m_collection[i] << endl;
           }
       }
       return *this;
   }

   double Numbers::max() const
   {
       return m_collection[m_collectionSize - 1];
   }

   double Numbers::min() const
   {
       return m_collection[0];
   }

   double Numbers::average() const
   {
       double temp{};
       for (int i = 0; i < m_collectionSize; i++) {
           temp += m_collection[i];
       }
       return temp / m_collectionSize;
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }
   Numbers::Numbers()
   {
       setEmpty();
   }
   Numbers::Numbers(const char* filename)
   {
       setEmpty();
       if (filename) {
           strcpy(m_filename, filename);
       }
       load(filename);
   }
   Numbers::~Numbers()
   {
       delete[] m_collection;
       setEmpty();
   }
   Numbers::Numbers(Numbers& N)
   {
       setEmpty();
       operator=(N);
   }
   Numbers& Numbers::operator=(const Numbers& N)
   {
       if (this != &N) {
           //save(filename); ??
           delete[] m_collection;
           setEmpty();
           if (N.m_collectionSize > 0) {
               m_originalFlag = false;
               m_collection = new double[N.m_collectionSize];
               for (int i = 0; i < N.m_collectionSize; i++) {
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
       sort();
       return *this;
   }
   Numbers& Numbers::operator+=(const double value)
   {
       if (m_collectionSize > 0) {
           double* temp{};
           temp = new double[m_collectionSize + 1];
           for (int i = 0; i < m_collectionSize; i++) {
               temp[i] = m_collection[i];
           }
           temp[m_collectionSize] = value;
           delete[] m_collection;
           m_collection = temp;
           m_collectionSize = m_collectionSize + 1;
       }
       return *this;
   }
   std::ostream& Numbers::display(std::ostream& ostr) const
   {
       if (m_collectionSize == 0) {
           ostr << "Empty list";
       }
       else {
           ostr.setf(ios::fixed);
           ostr.precision(2);
           if (m_originalFlag == false) {
               ostr << "Copy Of";
           }
           //insert the filename?
           ostr << endl;
           for (int i = 0; i < m_collectionSize; i++) {
               ostr << m_collection[i] << ", ";
           }
           ostr << endl;
           ostr.width(76);
           ostr.fill('-');
           ostr << "Total of " << m_collectionSize << " number(s), Largest: "
               << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
           ostr.width(76);
           ostr.fill('=');
       }
       return ostr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Numbers& RoN)
   {
       return RoN.display(ostr);
   }
   std::istream& operator>>(std::istream& istr, Numbers& RoN)
   {
       //RoN += istr;
       return istr;
   }
}