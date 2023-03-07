#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include <fstream>
#include "Item.h"

namespace sdds {
	class PosApp {

		char m_filename[255];
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
		PosApp(const char* filename);
		~PosApp();
		PosApp& run();
		//Can neither get copied nor assigned to another PosApp object. 
		//Your code must prevent such actions.
	};
}

#endif