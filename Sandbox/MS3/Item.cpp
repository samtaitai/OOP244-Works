#include <cstring>
#include <iostream>
#include "Item.h"
#include "Error.h"

using namespace std;

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
	std::ostream& Item::write(std::ostream& ostr) const
	{
		//when ostr.width(), default is right alignment

		if (*this) {
			if (m_displayType == POS_LIST) {
				ostr.width(7);
				ostr.setf(ios::left);
				ostr << m_SKU;
				ostr.unsetf(ios::left);
				ostr << '|';
				ostr.width(20);
				ostr << m_name;
				ostr << '|';
				ostr.width(7);
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_price;
				ostr << '|';
				if (m_taxed == true) {
					ostr << " X ";
				}
				else {
					ostr << "   ";
				}
				ostr << '|';
				ostr.width(4);
				ostr << m_quantity;
				ostr << '|';
				ostr.width(9);
				ostr << m_price * m_quantity << '|';

			}
			else if (m_displayType == POS_FORM) {
				ostr << "=============v" << endl;
				ostr << "Name:        " << m_name << endl;
				ostr << "Sku:         " << m_SKU << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Price        " << m_price << endl;
				ostr << "Price + tax: ";
				if (m_taxed == true) {

					ostr << m_price * m_quantity << endl;
				}
				else {
					ostr << "N/A" << endl;
				}
				ostr << "Stock Qty:   " << m_quantity;

			}
		}
		else {	//Item is in error state
			m_errState.getMsg();
		}
		
		return ostr;
	}
	std::istream& Item::read(std::istream& istr)
	{
		bool done = false;
		char ch{};

		cout << "Sku" << endl;
		do {
			cout << "> ";
			istr >> m_SKU;
			if (istr && strlen(m_SKU) <= MAX_SKU_LEN) done = true;
			else cout << "SKU too long" << endl;
		} while (!done);
		done = false;
		cout << "Name" << endl;
		do {
			cout << "> ";
			istr >> m_name;
			if (istr && strlen(m_name) <= MAX_NAME_LEN) done = true;
			else cout << "Item name too long" << endl;
		} while (!done);
		done = false;
		cout << "Price" << endl;
		do {
			cout << "> ";
			istr >> m_price;
			if (istr && strlen(m_name) >= 0) done = true;
			else cout << "Invalid price value" << endl;
		} while (!done);
		done = false;
		cout << "Taxed?" << endl;
		do {
			cout << "(Y)es/(N)o: ";
			istr >> ch;
			if (istr && (ch == 'Y' || ch == 'y')) {
				done = true;
				m_taxed = true;
			}
			else if (istr && (ch == 'N' || ch == 'n')) {
				done = true;
				m_taxed = false;
			}
			else cout << "Invalid price value" << endl;
		} while (!done);
		
		return istr;
	}
	std::ofstream& Item::save(std::ofstream& ostr) const
	{
		//T will be taken care in main.cpp? 
		ostr << ',' << m_SKU << ',' << m_name << ',';
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << m_price << ',' << int(m_taxed) << ',' << m_quantity << endl;
		return ostr;
	}
}