/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 15 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include <iostream>
#include "Pet.h"

namespace sdds {
	class Dog :public Pet {
		int m_numWalks;

	public:
		Dog(const char* thename, int theage = 0, double thecharge = 0);
		Dog& operator++(int);
		Dog& operator=(const Dog& Ro);
		void feed();
		void walk();
		void reSpawn();
		int getWalks();
	};
	std::ostream& operator<<(std::ostream& ostr, Dog& Ro);
	

}

#endif