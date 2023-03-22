#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "PosIO.h"
#include "POS.h"
#include "Error.h"


namespace sdds {
	class Item: public PosIO {
		char m_SKU[MAX_SKU_LEN];
		char* m_name;	//up to MAX_NAME_LEN characters
		double m_price;
		bool m_taxed; 
		int m_quantity;
		void setEmpty();

	protected:
		int m_displayType;
		Error m_errState;

	public:
		//construct & rule of three
		Item();
		Item(Item& Ro);
		Item& operator=(const Item& Ro);
		virtual ~Item();

		//operator
		bool operator==(const Item& Ro) const;
		bool operator>(const Item& Ro) const;
		int operator+=(const int quantity);
		int operator-=(const int quantity);
		operator bool() const;

		//pure virtual methods
		virtual Item& displayType(int form) const = 0;
		virtual double cost() const = 0;
		virtual int quantity() const = 0;
		virtual Item& clear() = 0;

		//io
		std::ostream& write(std::ostream&) const;
		std::istream& read(std::istream&);
		std::ofstream& save(std::ofstream&) const;
		std::ifstream& load(std::ifstream&);
		std::ostream& bPrint(std::ostream&) const;

	};
	double operator+=(Item& Lo, const Item& Ro);
}

#endif 