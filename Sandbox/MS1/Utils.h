/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
-----------------------------------------------------------
Provided by the professor:
getInt();
getInt(int min, int max, const char* prompt);
-----------------------------------------------------------*/
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