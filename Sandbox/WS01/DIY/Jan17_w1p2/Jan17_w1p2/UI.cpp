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

	void menu() {
		//get user input
		char operation;
		double value;
		bool keepgo = true;
		cout << "Enter GPA Query..." << endl;
		while (keepgo) {
			cout << "? ";
			cin >> operation;
			if (operation != '!') { //if not want to exit
				cin >> value;

				if (operation != '<' && operation != '>' && operation != '~') {
					cout << "Syntax error: ? [Op][value]<Enter>\n";
					cout << "Op: [>,<,~,!]\n";
					cout << "value: GPA value\n";
					cout << endl;
				}
				else {
					
					//cout << "let's go working" << endl;
					if (operation == '<') {
						cin >> value;
						displaySmaller(value);
					}
					else if (operation == '>') {
						cin >> value;
						displayBigger(value);
					}
					else if (operation == '~') {
						cin >> value;
						displayEqual(value);
					}
				}
			} else { //want to exit 
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