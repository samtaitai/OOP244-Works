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
-----------------------------------------------------------*/
#include <iostream>
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
}