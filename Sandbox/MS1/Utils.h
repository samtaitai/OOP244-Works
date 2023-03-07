#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
	class Utils {
	public:
		int getInt();
		int getInt(int min, int max, const char* prompt);

	};
	extern Utils U;
}



#endif