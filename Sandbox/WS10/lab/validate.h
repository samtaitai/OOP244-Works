/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 6 Apr 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H

namespace sict {

	template <typename T>
	bool validate(const T& minVal, T* array, int arrSize, bool* resArr) {
		bool result = true;
		int i{};

		for (i = 0; i < arrSize; i++) {
			
			if (array[i] <= minVal) {		//will compare stno or empno 
				if (array[i] == minVal) {	//in order to exclue 'B'
					result = true;
					resArr[i] = result;
				}
				else {
					result = false;
					resArr[i] = result;
				}
			}
			else {
				result = true;
				resArr[i] = result;
			}
		}
		for (i = 0; i < arrSize && result; i++) {
			if (resArr[i] == false) result = false;
		}
		return result;
	}
	
}
#endif 