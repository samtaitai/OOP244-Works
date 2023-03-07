#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

namespace sdds {
	class Item {
		char* m_name;
		int m_quantity;
		double m_price;

		void setEmpty();

	public:
		Item();
		~Item();
	};
}

#endif

