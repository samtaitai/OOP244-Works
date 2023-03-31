#include "NonPerishable.h"

using namespace std;

namespace sdds {
	char sdds::NonPerishable::itemType() const
	{
		return 'N';
	}
	std::ostream& NonPerishable::write(std::ostream& ostr) const
	{
		if (*this) {	//in a good state = not in errorous state?
			Item::write(ostr);
			if (m_displayType == POS_LIST) {
				ostr << "     N / A   |";
			}
			else if (m_displayType == POS_FORM) {
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
}

