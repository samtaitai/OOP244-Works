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
		
	};
}

#endif