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