/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 21 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Animation.h"

using namespace std;

namespace sdds {
	Animation::Animation() :Video{} {
		m_dimension = 0;
	}
	Animation::Animation(int length, int dimension) :Video{ length } {
		m_dimension = 0;
		if (dimension == 2 || dimension == 3) m_dimension = dimension;
	}

	void sdds::Animation::load(std::istream& istr)
	{
		Video::load(istr);
		istr >> m_dimension;
		if (!istr || (m_dimension != 2 && m_dimension != 3)) m_dimension = 0;
		istr.ignore(9999, '\n'); 
	}

	std::ostream& Animation::play(std::ostream& ostr) const
	{
		if (Video::get() != 0 && m_dimension != 0) {
			ostr << "Animation is in " << m_dimension << "-D" << endl;
			ostr << "Video length = " << Video::get();
		}
		return ostr;
	}

}