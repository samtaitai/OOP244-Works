#include "Utils.h"

namespace sdds {
	Utils U;

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


