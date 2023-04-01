/* Citation and Sources...
Final Project Milestone 4
Module: NonPerishable
Filename: NonPerishable.cpp
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
#include "NonPerishable.h"

using namespace std;

namespace sdds {
	char sdds::NonPerishable::itemType() const
	{
		return 'N';
	}
	std::ostream& NonPerishable::write(std::ostream& ostr) const
	{
		if (*this) {	//in a good state = not in errorous state?
			Item::write(ostr);
			if (m_displayType == POS_LIST) {
				ostr << "     N / A   |";
			}
			else if (m_displayType == POS_FORM) {
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
}

