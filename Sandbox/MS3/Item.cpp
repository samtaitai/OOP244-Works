#include <cstring>
#include "Item.h"
#include "Error.h"

namespace sdds {
	void Item::setEmpty()
	{
		strcpy(m_SKU, "\0");
		m_name = nullptr;
		m_price = 0.0;
		m_taxed = false;
		m_quantity = 0;
		m_displayType = 0;
		m_errState = Error();
	}
	Item::Item()
	{
		setEmpty();
	}
	Item::Item(Item& Ro)
	{
		setEmpty();
		if(Ro) *this = Ro;
	}
	Item& Item::operator=(const Item& Ro)
	{
		if (Ro.m_name && this != &Ro) {
			delete[] m_name;
			m_name = new char[strlen(Ro.m_name) + 1];	//assume string length validation was checked?  
			strcpy(m_name, Ro.m_name);
			strcpy(m_SKU, Ro.m_SKU);
			m_price = Ro.m_price;
			m_taxed = Ro.m_taxed;
			m_quantity = Ro.m_quantity;
			m_displayType = Ro.m_displayType;
			m_errState = Ro.m_errState;

		}
		return *this;
	}
	Item::~Item()
	{
		delete[] m_name;
	}
	bool Item::operator==(const Item& Ro) const
	{
		bool result{};
		if (Ro.m_name && m_SKU == Ro.m_SKU) result = true;
		return result;
	}
	bool Item::operator>(const Item& Ro) const
	{
		bool result{};
		int i{};

		if (strlen(m_name) < strlen(Ro.m_name)) {
			do {
				if (m_name[i] > Ro.m_name[i]) result = true;
				i++;
			} while (m_name[i] == Ro.m_name[i] && i < strlen(m_name));
		}
		else {
			do {
				if (m_name[i] > Ro.m_name[i]) result = true;
				i++;
			} while (m_name[i] == Ro.m_name[i] && i < strlen(Ro.m_name));
		}
		return result;
	}
	int Item::operator+=(const int quantity)
	{
		if (m_quantity + quantity > MAX_STOCK_NUMBER) {
			m_quantity = MAX_STOCK_NUMBER;
			m_errState = ERROR_POS_QTY;	
		}
		else {
			m_quantity = m_quantity + quantity;
		}
		return m_quantity;
	}
	int Item::operator-=(const int quantity)
	{
		if (m_quantity - quantity < 0) {
			m_quantity = 0;
			m_errState = ERROR_POS_STOCK;
		}
		else {
			m_quantity = m_quantity - quantity;
		}
		return m_quantity;
	}
	Item::operator bool() const
	{
		return !bool(m_errState);	//if error is true(exist), Item is false(errorous)
	}
}