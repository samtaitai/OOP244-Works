#include "Video.h"

namespace sdds {
	int sdds::Video::get() const
	{
		return m_length;
	}

	sdds::Video::Video()
	{
		m_length = 0;
	}

	sdds::Video::Video(int length)
	{
		//*this = Video(); wrong. cause Video is abstract, cannot be initiated
		m_length = 0;
		if (length > 0) m_length = length;
	}

	void sdds::Video::load(std::istream& istr)
	{
		istr >> m_length;
		if (!istr || m_length < 0) m_length = 0;
		istr.ignore();
	}
}


