#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include <iostream>
#include "Pet.h"

namespace sdds {
	class Fish:public Pet {
	public:
		//Pet(const char* name, int age = 0, double incrBaseCharge = 0);
		Fish(const char* name, int age = 0, double increBaseCharge = 2.0);
		void feed();
		void reSpawn();
		Fish& operator++(int);
		Fish& operator=(const Fish& Ro);
	};
	std::ostream& operator<<(std::ostream& ostr, Fish& Ro);

}

#endif