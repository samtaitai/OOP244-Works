/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.h
Version 1.1
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/25  MS3 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include <fstream>
#include "PosIO.h"
#include "POS.h"
#include "Error.h"


namespace sdds {
	class Item: public PosIO {
		char m_SKU[MAX_SKU_LEN + 1];
		char* m_name;	//up to MAX_NAME_LEN characters
		double m_price;
		bool m_taxed; 
		int m_quantity;
		void setEmpty();

	protected:
		int m_displayType;
		Error m_errState;	//it calls default constructor & initailization(setEmpty)

	public:
		//construct & rule of three
		Item();
		Item(Item& Ro);
		virtual Item& operator=(const Item& Ro);
		virtual Item* operator=(const Item* Ro); //do i need this?
		virtual ~Item();

		//operator
		virtual bool operator==(const char* sku) const;
		virtual bool operator>(const Item& Ro) const;
		virtual int operator+=(const int quantity);
		virtual int operator-=(const int quantity);
		virtual operator bool() const;

		//pure virtual methods??
		virtual Item& displayType(int form);
		virtual double cost() const;
		virtual int quantity() const;
		virtual char* name() const;	
		virtual const char* sku() const;
		virtual Error error() const;
		virtual Item& clear();

		//io
		virtual std::ostream& write(std::ostream&) const;
		virtual std::istream& read(std::istream&);
		virtual std::ofstream& save(std::ofstream&) const;
		virtual std::ifstream& load(std::ifstream&);
		virtual std::ostream& bprint(std::ostream&) const;

		virtual char itemType() const = 0;

	};
	double operator+=(double Lo, const Item& Ro);
}

#endif 