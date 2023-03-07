#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {
	Utils U;

	//code from Fardad *citation needed*
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

	//code from Fardad *citation needed*
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