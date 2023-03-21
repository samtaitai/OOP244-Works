/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 21 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Media.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const Media& m)
	{
		m.play(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Media& m)
	{
		m.load(istr);
		return istr;
	}
}


