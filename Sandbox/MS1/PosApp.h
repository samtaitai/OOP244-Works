/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include <fstream>
#include "Item.h"

namespace sdds {
	class PosApp {

		char m_filename[255];
		int m_noOfItems;
		Item* m_itemList;

		void setEmpty();
		PosApp& addItem();
		PosApp& removeItem();
		PosApp& stockItem();
		PosApp& listItems();
		PosApp& POS();
		PosApp& saveRecs();
		bool loadRecs(const char* filename);
		std::ostream& menu(std::ostream& ostr = std::cout);

	public:
		PosApp();
		PosApp(const char* filename);
		~PosApp();
		PosApp& run();
		//Can neither get copied nor assigned to another PosApp object. 
		//Your code must prevent such actions.
	};
}

#endif