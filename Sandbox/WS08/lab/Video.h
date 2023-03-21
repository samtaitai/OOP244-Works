#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include <iostream>
#include "Media.h"

namespace sdds {
	class Video: public Media {
		int m_length;

	protected:
		int get() const;

	public:
		Video();
		Video(int length);
		Video(Video& v) = delete;
		Video& operator=(Video& Ro) = delete;
		void load(std::istream& istr);

	};
}

#endif