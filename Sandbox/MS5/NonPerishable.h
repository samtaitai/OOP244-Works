/* Citation and Sources...
Final Project Milestone 4
Module: NonPerishable
Filename: NonPerishable.h
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
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include "Item.h"

namespace sdds {
	class NonPerishable:public Item
	{
	public:
		virtual ~NonPerishable() = default;
		char itemType() const;
		std::ostream& write(std::ostream&) const;

	};
}


#endif

