/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 3 Feb 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Store.h"
#include "Toys.h"

using namespace std;
using namespace sdds;

namespace sdds {

	//default constructor
	Store::Store() {
		setEmpty();
	}

	//This will set the store name and the number of toys that could be added to the store. 
	//For invalid value, it will set the values to an empty state.
	void Store::setStore(const char* sName, int no) {
		if (sName && no) {
			strcpy(m_sName, sName);
			m_noOfToys = no;
		}
		
	}
	//This will add the toys one at a time to the m_toy array and will keep track of the number of toys added. 
	//Toys will be added until num of added toys is less than m_noOfToys
	void Store::setToys(const char* tname, int sku, double price, int age) {
		Toys toy;								//option1: pointer of Toys option2: Toys + constructor + Toys.h included

		if (m_addToys < m_noOfToys) {			//m_noOfToys is constant. 
			toy.addToys(tname, sku, price, age);
			
			if (toy.fetchSKU() != 0) {			//if invalid->stay zero->not added to the array
				m_toy[m_addToys] = toy;
				m_addToys++;
			}
		}

	}
	void Store::display() const{

		if (this != nullptr) {				//If a Store object is valid???
			cout.fill('*');					//fill first
			cout.setf(ios::left);			//align
			cout.width(60);					//set width
			cout << "*" << endl;			//fill space between * and endl; with +
			cout << m_sName << endl;		
			cout.width(60);					//set width
			cout << "*" << endl;
			cout.fill(' ');
			cout << "list of the toys" << endl;
			cout.unsetf(ios::left);
			cout.width(30);
			//right
			cout << "SKU";
			cout.width(10);
			cout << "Age";
			cout.width(11);
			cout << "Price";
			cout.width(10);
			cout << "Sale" << endl;

			for (int i = 0; i < m_noOfToys; i++) {
				
				cout << "Toy[" << i + 1 << "] :";
				
				m_toy[i].display();					//since 2nd round, ****Toy[2]

				//cout << "*";
			}
		}
		else {
			cout << "Invalid Store" << endl;
		}
	}
	//This method will go through the arrays of toys. 
	//It will match the received SKU number with the stored toys' SKU number to find out 
	//if the toys are on sale or not. If the number matches then it will pass true to the appropriate Toys method. 
	//After that, it will call the calSale() of the toys class to know the sale value.
	void Store::find(int sku) {
		
		for (int i = 0; i < m_noOfToys; i++) {
			if (sku == m_toy[i].fetchSKU()) {
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
		}

	}
	//set the store to an empty state
	void Store::setEmpty() {

		strcpy(m_sName, "\0");
		m_noOfToys = 0;
		m_addToys = 0;

		for (int i = 0; i < MAX_NUM_TOYS; i++) {	//init??
			Toys toy;
			m_toy[i] = toy;
		}

	}

}
