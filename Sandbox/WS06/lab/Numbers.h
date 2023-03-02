#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {

       double* m_collection;
       char m_filename[255];
       int m_collectionSize;
       bool m_originalFlag;
       bool m_addedFlag;

       unsigned int countLines(const char* filename);
       void sort(double* collectionPtr, unsigned int size);
       void setEmpty();
       bool load();
       Numbers& save();
       double max() const;
       double min() const;
       double average() const;

   public:
       Numbers();
       Numbers(char* filename);
       ~Numbers();
       Numbers(Numbers& N);
       Numbers& operator=(Numbers& N);
       operator bool() const;
       Numbers& sort();
       Numbers& operator+=(Numbers& RoN);
       std::ostream& display(std::ostream& ostr = std::cout) const;
   };

   std::ostream& operator<<(std::ostream& ostr, Numbers& RoN);
   std::istream& operator>>(std::istream& istr, Numbers& RoN);

}
#endif // !SDDS_NUMBERS_H_

