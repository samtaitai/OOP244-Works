#include "Item.h"

using namespace std;

namespace sdds {
	void sdds::Item::setEmpty()
	{
		m_name = nullptr;
		m_quantity = 0;
		m_price = 0.0;
	}

	sdds::Item::Item()
	{
		setEmpty();
	}

	sdds::Item::~Item()
	{
		delete[] m_name;
	}
}


