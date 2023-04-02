/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.cpp
Version 1.1
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/25  MS3 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
sourced by outside of lecture codes: 
ifstream.peek() (source:https://cplusplus.com/reference/istream/istream/peek/)
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
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
		//m_errState = Error();
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
	Item* Item::operator=(const Item* Ro)
	{
		if (Ro->m_name && this != Ro) {
			delete[] m_name;
			m_name = new char[strlen(Ro->m_name) + 1];	//assume string length validation was checked?  
			strcpy(m_name, Ro->m_name);
			strcpy(m_SKU, Ro->m_SKU);
			m_price = Ro->m_price;
			m_taxed = Ro->m_taxed;
			m_quantity = Ro->m_quantity;
			m_displayType = Ro->m_displayType;
			m_errState = Ro->m_errState;

		}
		return nullptr;
	}
	Item::~Item()
	{
		delete[] m_name;
	}
	bool Item::operator==(const char* sku) const
	{
		bool result{};
		if (sku && strcmp(m_SKU,sku) == 0) result = true;
		return result;
	}
	bool Item::operator>(const Item& Ro) const
	{
		bool result = false;
		if (strcmp(m_name, Ro.m_name) > 0) result = true;
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
		return !m_errState;	
	}
	Item& Item::displayType(int form)
	{
		if (form == POS_LIST) m_displayType = 1;
		else if (form == POS_FORM) m_displayType = 2;
		return *this;
	}
	double Item::cost() const
	{
		double result{};
		if (m_taxed == true) result = m_price * (1 + TAX);
		else result = m_price;
		return result;
	}
	int Item::quantity() const
	{
		return m_quantity;
	}
	char* Item::name()
	{
		return m_name;
	}
	Item& Item::clear()
	{
		m_errState.clear();
		return *this;
	}
	std::ostream& Item::write(std::ostream& ostr) const
	{
		//when ostr.width(), default is right alignment
		unsigned int i{};

		if (*this) {
			if (m_displayType == 1) {
				ostr.fill(' ');		//why 0-padding from 2nd item?
				ostr.width(7);
				ostr.setf(ios::left);
				ostr << m_SKU;
				ostr << '|';
				ostr.width(20);
				if(strlen(m_name) <= 20) ostr << m_name;
				else {
					char temp[21]{};
					for (i = 0; i < 20; i++) {
						temp[i] = m_name[i];
					}
					temp[20] = '\0';	//this is it
					ostr << temp;
				}
				ostr.unsetf(ios::left);
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
				if(m_taxed == false) ostr << m_price * m_quantity << '|';
				else ostr << m_price * (1 + TAX) * m_quantity  << '|';
			}
			else if (m_displayType == 2) {
				ostr << "=============v" << endl;
				ostr << "Name:        " << m_name << endl;
				ostr << "Sku:         " << m_SKU << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Price:       " << m_price << endl;
				ostr << "Price + tax: ";
				if (m_taxed == true) {

					ostr << m_price * (TAX + 1) << endl;
				}
				else {
					ostr << "N/A" << endl;
				}
				ostr << "Stock Qty:   " << m_quantity << endl;

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
		char name[1024];
		strcpy(name, "\0");

		cout << "Sku" << endl;
		do {
			cout << "> ";
			istr.get(m_SKU,',');
			if (istr && strlen(m_SKU) <= MAX_SKU_LEN) done = true;
			else {
				istr.clear();
				istr.ignore(9999, '\n');
				cout << "SKU too long" << endl;
			}
		} while (!done);
		done = false;
		istr.ignore(9999, '\n');
		cout << "Name" << endl;
		do {
			cout << "> ";
			istr.get(name, ',');
			if (istr && strlen(name) <= MAX_NAME_LEN) {
				delete[] m_name;	//in case of update
				m_name = new char[strlen(name) + 1];
				strcpy(m_name, name);
				done = true;
			}
			else {
				istr.clear();
				istr.ignore(9999, '\n');
				cout << "Item name too long" << endl;
			}
		} while (!done);
		done = false;
		istr.ignore(9999, '\n');
		cout << "Price" << endl;
		do {
			cout << "> ";
			istr >> m_price;
			if (istr && m_price >= 0) done = true;
			else {
				istr.clear();
				istr.ignore(9999, '\n');
				cout << "Invalid price value" << endl;
			}
		} while (!done);
		done = false;
		istr.ignore(9999, '\n');
		cout << "Taxed?" << endl;
		cout << "(Y)es/(N)o: ";
		istr >> ch;
		if (!istr || (ch != 'y' && ch != 'n')) {
			while (!done) {
				istr.clear();
				istr.ignore(9999, '\n');
				cout << "Only 'y' and 'n' are acceptable: ";
				istr >> ch;
				if (istr && ch == 'y') {
					done = true;
						m_taxed = true;
				}
				else if (istr && ch == 'n') {
					done = true;
						m_taxed = false;
				}
			}
		}
		done = false;
		istr.ignore(9999, '\n');
		cout << "Quantity" << endl;
		do {
			cout << "> ";
			istr >> m_quantity;
			if (istr && m_quantity > 0 && m_quantity < MAX_STOCK_NUMBER) done = true;
			else {
				istr.clear();
				istr.ignore(9999, '\n');
				cout << "Invalid quantity value" << endl;
			}
		} while (!done);
		return istr;
	}
	std::ofstream& Item::save(std::ofstream& ostr) const
	{
		if (*this) {
			ostr << itemType() << ',' << m_SKU << ',' << m_name << ',';
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << m_price << ',' << int(m_taxed) << ',' << m_quantity;
		}
		
		return ostr;
	}
	std::ifstream& Item::load(std::ifstream& istr)
	{
		clear();

		char sku[1024];		//it should be way longer than max_sku_len
		char name[1024];
		strcpy(sku, "\0");
		strcpy(name, "\0");
		double price{};
		bool taxed{};
		int quantity{};

		if (istr.peek() != EOF) {				//!istr.eof() not working
			istr.get(sku, 1023, ',');
			if (!istr || strlen(sku) > MAX_SKU_LEN) m_errState = ERROR_POS_SKU;
			else {
				istr.ignore();
				istr.get(name, 1023, ',');
				if (!istr || strlen(name) > MAX_NAME_LEN) m_errState = ERROR_POS_NAME;
				else {
					istr.ignore();
					istr >> price;
					if (!istr || price < 0) m_errState = ERROR_POS_PRICE;
					else {
						istr.ignore();
						istr >> taxed;
						if (!istr || (taxed != 1 && taxed != 0)) m_errState = ERROR_POS_TAX;
						else {
							istr.ignore();
							istr >> quantity;
							if (!istr || quantity < 0 || quantity > MAX_STOCK_NUMBER) m_errState = ERROR_POS_QTY;
							else {
								strcpy(m_SKU, sku);
								if(m_name != nullptr) delete[] m_name;	//in case of update
								m_name = new char[strlen(name) + 1];
								strcpy(m_name, name);
								m_price = price;
								if (taxed == 1) m_taxed = true;
								else if (taxed == 0) m_taxed = false;
								m_quantity = quantity;
							}
						}
					}
				}
			}
			istr.clear();	//should be here. in line 349, it caused crash.
		}
		
		return istr;
	}
	std::ostream& Item::bprint(std::ostream& ostr) const
	{
		ostr << "| ";
		ostr.width(20);
		ostr.setf(ios::left);
		if (strlen(m_name) <= 20) ostr << m_name;
		else {
			char temp[21];
			for (int i = 0; i < 20; i++) {
				temp[i] = m_name[i];
			}
			temp[20] = '\0';	//this is it
			ostr << temp;
		}
		ostr.unsetf(ios::left);
		ostr << '|';
		ostr.width(10);
		if (m_taxed == true) ostr << m_price * (1 + TAX);
		else ostr << m_price;
		if (m_taxed == true) ostr << " |  T  |" << endl;
		else ostr << " |     |" << endl;

		return ostr;
	}
	double operator+=(double Lo, const Item& Ro)
	{
		return Lo + (Ro.cost() * Ro.quantity());
	}
}