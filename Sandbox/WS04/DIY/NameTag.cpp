/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "NameTag.h"
using namespace std;

namespace sdds {

	NameTag::NameTag() {
		setEmpty();
	}
	NameTag::NameTag(const char* name) {
		setName(name);
		m_ext = 0;
	}
	NameTag::NameTag(const char* name, int ext) {
		setName(name);
		setExt(ext);
	}
	NameTag::~NameTag() {
		delete[] m_name;
	}

	void NameTag::setName(const char* name) {

		if (name) {
			m_name = new char[strlen(name) + 1] {};
			//strcpy(m_name, "\0");
			strncpy(m_name, name, 40);
		}
		else {
			m_name = nullptr;
		}
	}
	void NameTag::setExt(int ext) {
		if (ext >= 10000 && ext <= 99999) {
			m_ext = ext;
		}
		else {
			m_ext = -1;
		}
	}
	void NameTag::setEmpty() {

		m_name = nullptr;
		m_ext = -1;
	}

	//A function called read that receives the name and then the extension number from console and 
	//returns the reference of the current object (NameTag&).
	//should read the name up to the maximum of 40 characters and 
	//ignore the rest and then set the name of the NameTag to the entered name. 
	//should give an option to the user to enter the extension number or not.
	//If the user chooses to enter the extension it should enforce the user to enter a 5 digit integer and 
	//if user does not comply, it should print one of the following messages based on the type of the error:
	NameTag& NameTag::read() {
		char tempName[41];
		strcpy(tempName, "\0");
		int tempExt{};
		char choice{};
		bool done = false; 

		cout << "Please enter the name: ";	//tempName validation
		do {
			done = false;
			cin.getline(tempName, 40, '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(9999, '\n');
			}
			else {
				done = true;
			}
		} while (cin.fail() && !done);

		delete[] m_name;
		m_name = new char[strlen(tempName) + 1];
		strcpy(m_name, tempName);
		done = false;

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		while (!done) {
			done = false;
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				this->m_ext = getInt(10000, 99999, "Please enter a 5 digit phone extension: "); //validation and assign
				done = true;
			}
			else if (choice == 'N' || choice == 'n') {
				this->m_ext = 0;					//display will detect 0 then print "N/A" instead
				done = true;
			}
			else {
				cout << "Only (Y) or (N) are acceptable, try again: ";
			}
		}
		return *this;
	}
	void NameTag::print() {

		char case1[] = "Extension: N/A";
		char case2[] = "Extension: 12345";

		if (m_name != nullptr && m_ext != -1) {	//not 'safe invalid' 

			int width{};
			if (strlen(m_name) < 20) {
				width = 20 + 2; 
			}
			else {
				width = 40 + 2;
			}

			cout.fill('-');

			cout.setf(ios::left);		//+------
			cout.width(width);			
			cout << '+';

			cout.unsetf(ios::left);		//space-+
			cout << "-+" << endl;		
					
			cout.fill(' ');

			cout.setf(ios::left);		//|space
			cout.width(width);			
			cout << '|';

			cout.unsetf(ios::left);
			cout << " |" << endl;		//space |

			cout.setf(ios::left);
			cout << "| " << m_name;		//| m_name space

			cout.unsetf(ios::left);
			cout.width(width - strlen(m_name));
			cout << " |" << endl;		//space |
			
			cout.setf(ios::left);		//|space
			cout.width(width);
			cout << '|';

			cout.unsetf(ios::left);
			cout << " |" << endl;		//space |

			cout.setf(ios::left);		//|space
			cout << "| ";
			if (m_ext == 0) {
				cout << "Extension: N/A";
				cout.width(width - strlen(case1));
			}
			else {
				cout << "Extension: " << m_ext;	//issue! 
				cout.width(width - strlen(case2));
			}
			cout.unsetf(ios::left);
			cout << " |" << endl;		//space | should fix here

			cout.setf(ios::left);		//|space
			cout.width(width);
			cout << '|';

			cout.unsetf(ios::left);
			cout << " |" << endl;		//space |

			cout.fill('-');

			cout.setf(ios::left);		//+------
			cout.width(width);
			cout << '+';

			cout.unsetf(ios::left);		//space-+
			cout << "-+" << endl;
			
		}
		else {
			cout << "EMPTY NAMETAG!";
		}
	}

	int getInt() {
		int value{};
		bool done{};
		do {
			done = false;
			cin >> value;
			if (cin) {						// if(!cin.fail()){
				if (cin.get() != '\n') {	// cin not fail, but input isn't int 
					cout << "Bad integer value, try again: ";
				}
				else {
					done = true;
				}
			}
			else {
				cin.clear();				// cin.fail
				cout << "Bad integer value, try again: ";
			}
			//if (!done) cin.ignore(10000, '\n');
			(!done) && cin.ignore(10000, '\n'); // same but quicker
		} while (!done);
		return value;
	}

	int getInt(int min, int max, const char* prompt) {
		int value{};
		if (prompt) cout << prompt;
		do {
			value = getInt();
		} while ((value < min || value > max) &&
			cout << "Invalid value" << "[" << min << "<=value<=" << max << "]: ");
		return value;
	}
}
