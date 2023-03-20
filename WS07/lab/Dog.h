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
		const double COST_BASE = 4.00;		// Fee: Initial purchase
		const double COST_FEED = 0.25;		// Fee: For each feeding
		const double COST_REVIVE = 1.00;		// Fee: Respawn if perished
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