/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.cpp
Version 1.1
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
2023/4/1  MS51 submission
-----------------------------------------------------------
Provided by the lecture material:
void swap(Item** array, int size);
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PosApp.h"
#include "Item.h"	
#include "Utils.h"
#include "POS.h"
#include "NonPerishable.h"
#include "Perishable.h"

using namespace std;

namespace sdds {
	void PosApp::setEmpty()
	{
		unsigned int i{};

		strcpy(m_filename, "\0");
		for (i = 0; i < MAX_NO_ITEMS; i++) {
			m_iptr[i] = nullptr;
		}
		m_nptr = 0;
	}
	PosApp& PosApp::addItem()
	{
		actionTitle("Adding Item to the store");
		cout.unsetf(ios::left);
		cout << "Running addItem()" << endl;
		return *this;
	}
	PosApp& PosApp::removeItem()
	{
		actionTitle("Remove Item");
		cout.unsetf(ios::left);
		cout << "Running removeItem()" << endl;
		return *this;
	}
	PosApp& PosApp::stockItem()
	{
		actionTitle("Select an item to stock");
		cout.unsetf(ios::left);
		cout << "Running stockItem()" << endl;
		return *this;
	}
	PosApp& PosApp::listItems() 
	{
		int i{};
		double totalAsset{};
		actionTitle("Listing Items");
		cout.unsetf(ios::left);
		sort(m_iptr, m_nptr);	

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
		for (i = 0; i < m_nptr; i++) {
			cout.fill(' ');
			cout.width(4);
			cout << i + 1;
			cout << " | " << m_iptr[i]->displayType(POS_LIST) << endl;
			//cost() already takes care of taxed
			totalAsset += m_iptr[i]->cost() * m_iptr[i]->quantity();
		}
		//later, if(sth == true), print totalAsset; otherwise not
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "                               Total Asset: $  |       ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << totalAsset << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
		cout << endl;

		return *this;
	}
	PosApp& PosApp::POS()
	{
		actionTitle("Starting Point of Sale");
		cout.unsetf(ios::left);
		cout << "Running POS()" << endl;
		return *this;
	}
	void PosApp::saveRecs()
	{
		int i{};

		actionTitle("Saving Data");

		ofstream output(m_filename);
		for (i = 0; i < m_nptr; i++) {
			output << *(m_iptr[i]) << endl;
		}
	}
	void PosApp::loadRecs(const char* filename)
	{
		char ch{};

		//like this?
		actionTitle("Loading Items");

		ifstream input(filename);
		if (!input) {
			ofstream emptyFile(filename);
			emptyFile.close();
			strcpy(m_filename, "\0");
			m_nptr = 0;
			//delete[] m_iptr;
			//m_iptr = nullptr;
		}
		else if (input) {
			
			while (input.peek() != EOF && m_nptr < MAX_NO_ITEMS) {
				input.get(ch);
				input.ignore();
				if (ch == 'N') {
					Item* itemPtr = new NonPerishable;
					input >> *itemPtr;
					m_iptr[m_nptr] = itemPtr;
				}
				else if (ch == 'P') {
					Item* itemPtr = new Perishable;
					input >> *itemPtr;
					m_iptr[m_nptr] = itemPtr; //not a copy assignment?
				}
				m_nptr++;
				input.ignore(); //remove \n
			}
		}
	}
	ostream& PosApp::menu(ostream& ostr)  
	{
		bool done = false;
		int select{};
		
		while (!done) {
			ostr << "The Sene-Store" << endl;
			ostr << "1- List items" << endl;
			ostr << "2- Add item" << endl;
			ostr << "3- Remove item" << endl;
			ostr << "4- Stock item" << endl;
			ostr << "5- POS" << endl;
			ostr << "0- exit program" << endl;
			select = 
				U.getInt(0, 5, "> ");

			switch (select) {
			case 1:
				listItems();
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				POS();
				break;
			case 0:
				done = true;
				break;
			}
		};
		return ostr;
	}
	void PosApp::actionTitle(const char* title)
	{
		
		cout << ">>>> ";
		cout.width(72);
		cout.fill('.');
		cout.setf(ios::left);
		cout << title;
		cout << endl;
	}
	PosApp::PosApp(const char* filename)
	{
		setEmpty();
		if (filename) strcpy(m_filename, filename);
	}
	PosApp::~PosApp()
	{
		unsigned int i{};
		for (i = 0; i < m_nptr; i++) {
			delete[] m_iptr[i];		//call item destructor
		}
	}
	PosApp& PosApp::run () 
	{
		loadRecs(m_filename);
		menu();
		saveRecs();
		cout << "Goodbye!" << endl;
		return *this;
	}

	void PosApp::sort(Item** array, int size)
	{
		int i, j;
		Item* temp;

		for (i = 0; i < size - 1; i++) {
			for (j = 0; j < size - i - 1; j++) {
				if (*(array[j]) > *(array[j + 1])) {	//should be Item::operator>
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
}