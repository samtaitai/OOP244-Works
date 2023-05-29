/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 5 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Utils.h"

namespace sdds {
	Utils U;            //file scope variable

    void sdds::Utils::sort(double* nums, unsigned int size)
    {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
}


