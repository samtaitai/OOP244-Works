/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
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
#include "Perishable.h"

using namespace std;

char sdds::Perishable::itemType() const
{
	return 'P';
}

std::ostream& sdds::Perishable::write(std::ostream& ostr) const
{
	if (*this) {
		Item::write(ostr);
		if (m_displayType == POS_LIST) {
			ostr << "  " << m_expiryDate << " |";
		}
		else if (m_displayType == POS_FORM) {
			ostr << "Expiry date: " << m_expiryDate << endl;
			ostr << "=============^" << endl;
		}
	}
	return ostr;
}

std::istream& sdds::Perishable::read(std::istream& istr)
{
	Item::read(istr);
	if (*this && !istr.fail()) {
		int year{};
		int month{};
		int day{};
		Date temp;

		cout << "Expiry date (YYYY/MM/DD)" << endl;
		cout << "> ";
		istr >> year;
		istr.ignore();
		istr >> month;
		istr.ignore();
		istr >> day;
		
		temp = Date(year, month, day);	//dateonly is set up internally
		if (temp) {						//not in a errorous state,
			m_expiryDate = temp;
		}
		else {
			m_errState = m_expiryDate.error();	//set the error object of the Item to the error of the Date.
		}
	}
	return istr;
}

std::ofstream& sdds::Perishable::save(std::ofstream& ostr) const
{
	if (*this) {
		Item::save(ostr);
		ostr << ',' << m_expiryDate;
	}
	
	return ostr;
}

std::ifstream& sdds::Perishable::load(std::ifstream& istr)
{
	Item::load(istr);
	if (*this && !istr.fail()) {
		int year{};
		int month{};
		int day{};

		istr.ignore();	//ignore first ,
		istr >> year;
		istr.ignore();
		istr >> month;
		istr.ignore();
		istr >> day;

		Date temp = Date(year, month, day);	//dateonly is set up internally
		if (temp) {							//not in a errorous state,
			m_expiryDate = temp;
		}
		else {
			m_errState = m_expiryDate.error();	//set the error object of the Item to the error of the Date.
		}

	}
	return istr;
}
