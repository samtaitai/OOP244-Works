#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include <iostream>
#include "Video.h"

namespace sdds {
	class Animation : public Video {
		int m_dimension;
	public:
		Animation();
		Animation(int length, int dimension);
		void load(std::istream& istr);
		std::ostream& play(std::ostream& ostr) const;
	};
}

#endif 