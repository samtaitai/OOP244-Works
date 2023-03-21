#include "Media.h"

namespace sdds {
	std::ostream& sdds::operator<<(std::ostream& ostr, const Media& m)
	{
		m.play(ostr);
		return ostr;
	}

	std::istream& sdds::operator>>(std::istream& istr, Media& m)
	{
		m.load(istr);
		return istr;
	}
}


