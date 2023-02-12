/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
#include <iostream>
using namespace std;

namespace sdds {

	class NameTag
	{
		char* m_name;
		int m_ext; 

	public: 
		NameTag();
		NameTag(const char* name);
		NameTag(const char* name, int ext);
		~NameTag();

		NameTag& setName(const char* name);
		NameTag& setExt(int ext);
		NameTag& setEmpty();

		NameTag& read();
		ostream& print();
	};

	int getInt();
	int getInt(int min, int max, const char* prompt);

}

#endif


