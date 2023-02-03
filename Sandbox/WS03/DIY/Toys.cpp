#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Toys.h"

using namespace std;
using namespace sdds;

namespace sdds {

	//default constructor
	Toys::Toys() {
		strcpy(m_tname, "\0");
		m_sku = 0;
		m_price = 0.0;
		m_age = 0;
	}

	//After checking the validity, this method will set the received values to the appropriate data members. 
	//Otherwise will be set to an empty state.
	void Toys::addToys(const char* tname, int sku, double price, int age) {
		if (tname && sku && price && age) {
			strcpy(m_tname, tname);
			m_sku = sku;
			m_price = price;
			m_age = age;
		}
		
	}
	//I made it
	int Toys::fetchSKU() const{
		return m_sku;
	}

	//It will assign the received value to the data member m_onSale.
	void Toys::isSale(bool sale) {
		m_onSale = sale;
	}
	//It will decrease the toys price to 20% then the original price.
	void Toys::calSale() {
		m_price = 0.8 * m_price;
	}
	void Toys::display() const {
		
		if (this) {					//If a Toy object is valid??? 
			cout.setf(ios::left);
			cout.width(15);
			cout << m_tname;
			cout.width(10);
			cout << m_sku;
			cout.width(6);
			cout << m_age;
			cout.width(12);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;

			if (m_onSale == true) {
				cout.width(10);
				cout << "On Sale" << endl;;
			}
			else {
				cout.width(8);
				cout << endl;
			}
		}
		else {
			cout << "Invalid Toy" << endl;
		}
	}
}
