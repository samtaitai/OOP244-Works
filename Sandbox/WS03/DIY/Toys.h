#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_
#define MAX_TNAME 31

namespace sdds {
	class Toys
	{
		char m_tname[MAX_TNAME];
		int m_sku;
		double m_price;
		int m_age;
		bool m_onSale;

	public:
		Toys();
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display() const;
		int fetchSKU() const;

	};
}


#endif

