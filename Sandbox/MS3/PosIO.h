/* Citation and Sources...
Final Project Milestone 3
Module: PosIO
Filename: PosIO.h
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/25  MS3 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>

namespace sdds {
	class PosIO {
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual std::ofstream& save(std::ofstream&) const = 0;
		virtual std::ifstream& load(std::ifstream&) = 0;
		virtual ~PosIO() = default;
	};
	std::ostream& operator <<(std::ostream&, const PosIO& Ro);
	std::ofstream& operator <<(std::ofstream&, const PosIO& Ro);
	std::istream& operator >>(std::istream&, PosIO& Ro);
	std::ifstream& operator >>(std::ifstream&, PosIO& Ro);
}

#endif 