/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/31  MS4 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable :public Item
	{
		Date m_expiryDate;
	public:
		virtual ~Perishable() = default;
		char itemType() const;
		std::ostream& write(std::ostream&) const;
		std::istream& read(std::istream&);
		std::ofstream& save(std::ofstream&) const;
		std::ifstream& load(std::ifstream&);

	};
}


#endif
