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