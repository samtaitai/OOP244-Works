/* Citation and Sources...
Final Project Milestone 5
Module: PosIO
Filename: PosIO.cpp
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/25  MS3 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include "PosIO.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const PosIO& Ro)
	{
		Ro.write(ostr);
		return ostr;
	}
	std::ofstream& operator<<(std::ofstream& ostr, const PosIO& Ro)
	{
		Ro.save(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, PosIO& Ro)
	{
		Ro.read(istr);
		return istr;
	}
	std::ifstream& operator>>(std::ifstream& istr, PosIO& Ro)
	{
		Ro.load(istr);
		return istr;
	}
}