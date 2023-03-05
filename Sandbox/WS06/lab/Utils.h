/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 5 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
	class Utils
	{
	public:
		void sort(double* nums, unsigned int size);
	};
	extern Utils U;		//prototype of variable
						//extern: file scope->global scope
						//anyone #include "Utils.h" access U
}


#endif