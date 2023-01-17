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

namespace sdds {

	void queryEntry() {
		
		char operation; 
		double GPAvalue; 

		cout << "Enter GPA query..." << endl;
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
			exitProgram();
		}
		else {
			cout << "Syntax error: ? [Op][value]<Enter>" << endl;
			cout << "Op: [>,<,~,!]" << endl;
			cout << "value: GPA value" << endl;
		}

	}

	//if Op value == '!', invoke this 
	void exitProgram() {

		char choice;

		cout << "Exit the program? (Y)es/(N)o: ";
		cin >> choice;

		if (choice != 'y') {
			//stay with the program
		}
		else if (choice == 'y') {
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else {
			cout << "Invalid command" << endl;
		}
		
	}

}