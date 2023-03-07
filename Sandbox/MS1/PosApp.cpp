#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
//#include "Item.h"
#include "PosApp.h"
#include "Utils.h"


using namespace std;

namespace sdds {
	void PosApp::setEmpty()
	{
		strcpy(m_filename, "\0");
		m_itemList = nullptr;
		m_noOfItems = 0;
	}
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
	PosApp& PosApp::listItems () 
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Listing Items";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Running listItems()" << endl;
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
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Saving Data";
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Saving data in " << m_filename << endl;
		return *this;
	}
	bool PosApp::loadRecs(const char* filename)
	{
		cout.setf(ios::left);
		cout.width(77);
		cout.fill('.');
		cout << ">>>> Loading Items"; 
		cout << endl;
		cout.unsetf(ios::left);
		cout << "Loading data from " << filename << endl;
		return true;
	}
	std::ostream& PosApp::menu(std::ostream& ostr) 
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
	PosApp::PosApp(const char* filename)
	{
		setEmpty();
		if (filename) strcpy(m_filename, filename);
	}
	PosApp::~PosApp()
	{
		delete[] m_itemList;
	}
	PosApp& PosApp::run () 
	{
		loadRecs(m_filename);
		menu();
		saveRecs();
		cout << "Goodbye!" << endl;
		return *this;
	}
}