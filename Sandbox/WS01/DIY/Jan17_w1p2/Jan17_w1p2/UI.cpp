/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 17 2023
*/
#include <iostream>
#include <stdlib.h>
#include "UI.h"
#include "GPAlist.h"
using namespace std;
using namespace sdds;

namespace sdds {

	//welcome messeage
	//based on operation, invoke different function
	void queryEntry() {
		
		char operation; 
		double GPAvalue; 
		bool done = false;

		cout << "Enter GPA Query..." << endl;

		while (!done) {
			cout << "?";
			cin >> operation >> GPAvalue;

			if (operation == '>') {
				displayBigger(GPAvalue);
			}
			else if (operation == '<') {
				displaySmaller(GPAvalue);
			}
			else if (operation == '~') {
				displayEqual(GPAvalue);
			}
			else if (operation == '!') {
				char ch = cin.get();
				cout << "Exit the program? (Y)es/(N)o: ";
				if (ch == 'Y' || ch == 'y')
				{
					done = true;
				}
			}
			else {
				cout << "Syntax error: ? [Op][value]<Enter>" << endl;
				cout << "Op: [>,<,~,!]" << endl;
				cout << "value: GPA value" << endl;
			}
		}
	}

}