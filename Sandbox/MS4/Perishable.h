#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable :public Item
	{
		Date m_expiryDate;
	public:
		char itemType() const;
		std::ostream& write(std::ostream&) const;
		std::istream& read(std::istream&);
		std::ofstream& save(std::ofstream&) const;
		std::ifstream& load(std::ifstream&);

	};
}


#endif
