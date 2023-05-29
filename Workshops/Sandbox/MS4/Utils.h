/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.h
Version 1.1
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
2023/3/19  MS2 submission
2023/3/25  MS3 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
Provided by the professor:
getInt();
getInt(int min, int max, const char* prompt);
void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
int uniqueDateValue(int year, int mon, int day, int hour, int min);
int daysOfMonth(int year, int month);
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
	class Utils {
	public:
		int getInt();
		int getInt(int min, int max, const char* prompt);
		void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
		int uniqueDateValue(int year, int mon, int day, int hour, int min);
		int daysOfMonth(int year, int month);
	};
	extern Utils U;
}

#endif