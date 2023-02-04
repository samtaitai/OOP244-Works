/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 3 Feb 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_
#define MAX_NUM_TOYS 10 
#define MAX_SNAME 31   
#include "Toys.h"

namespace sdds {
	
	class Store
	{
		char m_sName[MAX_SNAME];
		int m_noOfToys;
		int m_addToys;
		Toys m_toy[MAX_NUM_TOYS];

	public:
		Store();
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display() const;
		void find(int sku);
		void setEmpty();
	};

}


#endif
