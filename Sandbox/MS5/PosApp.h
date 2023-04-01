/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
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

#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include <fstream>
#include "POS.h";
#include "Item.h"

namespace sdds {
	class PosApp {

		char m_filename[128 + 1]{};
		Item* m_iptr[MAX_NO_ITEMS]; //how to initialize? 
		int m_nptr{};
		//action title?

		//void setEmpty();
		PosApp& addItem();
		PosApp& removeItem();
		PosApp& stockItem();
		PosApp& listItems();					
		void saveRecs();						
		void loadRecs(const char* filename);	
		PosApp& POS();
		std::ostream& menu(std::ostream& ostr = std::cout);
		void actionTitle(const char* title);

	public:
		PosApp(const char* filename);
		virtual ~PosApp();

		//Can neither get copied nor assigned to another PosApp object. 
		//Your code must prevent such actions.
		PosApp(PosApp& R) = delete;
		PosApp& operator=(const PosApp& R) = delete;
		PosApp& run();
		void sort(Item** array, int size);
		
	};
}

#endif