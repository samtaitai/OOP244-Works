/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 21 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>

namespace sdds {
	class Media {
	public:
		virtual ~Media() = default;
		virtual void load(std::istream&) = 0;
		virtual std::ostream& play(std::ostream&) const = 0; 
	};
	std::ostream& operator <<(std::ostream& ostr, const Media& m);
	std::istream& operator >>(std::istream& istr, Media& m);
}

#endif