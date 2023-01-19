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
			if (operation == '!') {
				char ch;
				cout << "Exit the program? (Y)es/(N)o: ";
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					keepgo = false;
				}
			}
			else if (operation == '<') {
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
			else {
				cout << "Syntax error: ? [Op][value]<Enter>\n";
				cout << "Op: [>,<,~,!]\n";
				cout << "value: GPA value\n";
				cout << endl;
			}
		}
		
	}

	//bool queryEntry() {
	//	
	//	char operation; 
	//	double GPAvalue; 
	//	bool done = false;

	//	cout << "Enter GPA Query..." << endl;

	//	while (!done) {
	//		cout << "? ";
	//		cin >> operation;
	//		if (operation == '!') {
	//			//char ch = cin.get();
	//			char ch;
	//			cout << "Exit the program? (Y)es/(N)o: ";
	//			cin >> ch;
	//			if (ch == 'Y' || ch == 'y')
	//			{
	//				done = true;
	//			}
	//		}
	//		else {
	//			cin >> GPAvalue;
	//			if (operation == '>') {
	//				displayBigger(GPAvalue);
	//			}
	//			else if (operation == '<') {
	//				displaySmaller(GPAvalue);
	//			}
	//			else if (operation == '~') {
	//				displayEqual(GPAvalue);
	//			}
	//			else {
	//				cout << "Syntax error: ? [Op][value]<Enter>" << endl;
	//				cout << "Op: [>,<,~,!]" << endl;
	//				cout << "value: GPA value" << endl;
	//			}
	//		}
	//	}
	//	return done; //upon '!' it's true
	//}

}