/*
Soyon Lee
slee550@myseneca.ca
179142211
Jan 17 2023
*/
#include <iostream>
#include <stdlib.h>
#include "GPAlist.h"
#include "UI.h"

using namespace std;
using namespace sdds;

namespace sdds {

	//welcome messeage
	//based on operation, invoke different function

	void flushkeys() {
		while (cin.get() != '\n');
	}

	void menu() {
		//get user input
		char operation;
		double value;
		bool keepgo = true;
		cout << "Enter GPA query..." << endl;
		while (keepgo) {	//while for 'syntax error'
			
			cout << "? ";
			cin >> operation;

			if (operation != '!' && operation != '<' && operation != '>' && operation != '~') {
				cout << "Syntax error: ? [Op][value]<ENTER>\n";
				cout << "Op: [>,<,~,!]\n";
				cout << "value: GPA value\n";
				cout << endl;
				flushkeys(); //need 
			}
			else {
				if (operation != '!') {
					cin >> value;
					if (operation == '<') {
						displaySmaller(value);
					}
					else if (operation == '>') {
						displayBigger(value);
					}
					else if (operation == '~') {
						displayEqual(value);
					}
				}
				else {
					char ch;
					cout << "Exit the program? (Y)es/(N)o: ";
					cin >> ch;
					if (ch == 'Y' || ch == 'y')
					{
						keepgo = false;
					}
				}
				
			}
		}
	}
}
