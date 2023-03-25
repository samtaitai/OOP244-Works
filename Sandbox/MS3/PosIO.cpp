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