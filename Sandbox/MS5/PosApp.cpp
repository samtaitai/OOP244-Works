/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.cpp
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
-----------------------------------------------------------
Provided by the professor:
void swap( type* a, type* b );
void sort( T* array, int size )
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
#include "sort.h"

using namespace std;

namespace sdds {
	//void PosApp::setEmpty()
	//{
	//	strcpy(m_filename, "\0");
	//	//how to initialize array of Item?
	//	m_nptr = 0;
	//}
	PosApp& PosApp::addItem()
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Adding Item to the store";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Running addItem()" << endl;
		return *this;
	}
	PosApp& PosApp::removeItem()
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Remove Item";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Running removeItem()" << endl;
		return *this;
	}
	PosApp& PosApp::stockItem()
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Select an item to stock";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Running stockItem()" << endl;
		return *this;
	}
	PosApp& PosApp::listItems() 
	{
		unsigned int i{};
		int totalAsset{};
		actionTitle("Listing Items");

		/*implementation*/
		//Sort all the Items in Iptr array based on their name in ascending order.
		//Print the Title/Header of the list:
		//Loop through the items up to nptr and display the row and \
		the Items in POS_LIST format, calculating the total asset value of the Items.
		//Print the footer and the total asset as follows:
		sort(m_iptr, m_nptr);
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
		for (i = 0; i < m_nptr; i++) {
			cout << m_iptr[i].displayType(POS_LIST) << endl;
			if (m_iptr[i].isTaxed() == true) {
				totalAsset += m_iptr[i].cost() * (1 + TAX) * m_iptr[i].quantity();
			}
			else {
				totalAsset += m_iptr[i].cost() * m_iptr[i].quantity();
			}
		}
		//later, if(sth == true), print totalAsset; otherwise not
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "                               Total Asset: $  |       ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << totalAsset << "| " << endl;
		cout << "-----------------------------------------------^--------------^";

		return *this;
	}
	PosApp& PosApp::POS()
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Starting Point of Sale";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Running POS()" << endl;
		return *this;
	}
	PosApp& PosApp::saveRecs()
	{
		unsigned int i{};

		actionTitle("Saving Data");

		/*implementation*/
		//Create an instance of ofstream using the data filename.
		//loop through the Items pointed by the Iptr pointers and \
		insert them into the ofstream instance up to nptr.
		ofstream output(m_filename);
		for (i = 0; i < m_nptr; i++) {
			output << m_iptr[i];
		}

		return *this;
	}
	bool PosApp::loadRecs(const char* filename)
	{
		char ch{};
		bool success = false;

		//like this?
		actionTitle("Loading Items");

		/*implementation*/
		//open the data file in an ifstream object (we will call this input here).
		//if opening the file was not successful create the file by opening \
		and closing it using an ofstream object.
		//Empty the PosApp class (make sure there are no Items in the Iptr)
		//while the input is in a good state and the Iptr array is not full
		//read one character
		//create a dynamic Item (either Perishable, or NonPershable) based on \
		the character being P or N and keep the address in the next available \
		Iptr pointer
		//extract the Item from the input and add one to the nptr
		ifstream input(filename);
		if (!input) {
			ofstream emptyFile(filename);
			emptyFile.close();
			strcpy(m_filename, "\0");
			m_nptr = 0;
			delete[] m_iptr;
			m_iptr = nullptr;
		}
		else if (input && m_nptr < MAX_NO_ITEMS) {
			input.get(ch);
			if (ch == 'N') {
				NonPerishable np;
				np.load(input);
				m_iptr[m_nptr] = np;
				m_nptr++;
				success = true;
			}
			else if (ch == 'P') {
				Perishable ps;
				ps.load(input);
				m_iptr[m_nptr] = ps;
				m_nptr++;
				success = true;
			}
		}
		return success;
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
			ostr << "5- Point of Sale" << endl;
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
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> " << title;
		cout << endl;
		cout.unsetf(ios::left);
	}
	PosApp::PosApp(const char* filename)
	{
		if (filename) strcpy(m_filename, filename);
	}
	PosApp::~PosApp()
	{
		delete[] m_iptr;
	}
	PosApp& PosApp::run () 
	{
		loadRecs(m_filename);
		if(loadRecs(m_filename)) menu();
		saveRecs();
		cout << "Goodbye!" << endl;
		return *this;
	}
}