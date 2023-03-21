/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 21 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include <iostream>
#include "Video.h"

namespace sdds {
	class VRVideo: public Video {
		char* m_equipment;
	public:
		VRVideo();
		VRVideo(int length, const char* name);
		virtual ~VRVideo();
		void load(std::istream& istr);
		std::ostream& play(std::ostream& ostr) const;
	};
}

#endif 