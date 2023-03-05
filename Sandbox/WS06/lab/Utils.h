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