/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
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
void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
int uniqueDateValue(int year, int mon, int day, int hour, int min);
int daysOfMonth(int year, int month);
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"

using namespace std;

namespace sdds {
	Utils U;

	int Utils::getInt() {
		int value{};
		bool done{};
		do {
			done = false;
			cin >> value;
			if (cin) {
				if (cin.get() != '\n') {				//if not integer	
					cout << "Invalid Integer, try again: ";
				}
				else {
					done = true;
				}
			}
			else {										//if cin fail
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}

			(!done) && cin.ignore(10000, '\n');
		} while (!done);
		return value;
	}

	int Utils::getInt(int min, int max, const char* prompt) {
		int value{};
		if (prompt) cout << prompt;
		do {
			value = getInt();
		} while ((value < min || value > max) &&
			cout << "[" << min << "<=value<=" << max << "], retry: " << prompt);
		return value;
	}

	void Utils::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		day = lt.tm_mday;
		mon = lt.tm_mon + 1;
		year = lt.tm_year + 1900;
		if (dateOnly) {
			hour = min = 0;
		}
		else {
			hour = lt.tm_hour;
			min = lt.tm_min;
		}
	}
	int Utils::uniqueDateValue(int year, int mon, int day, int hour, int min)
	{
		return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
	}
	int Utils::daysOfMonth(int year, int month)
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = month >= 1 && month <= 12 ? month : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
}