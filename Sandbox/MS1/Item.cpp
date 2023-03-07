/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.cpp
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/7  MS1 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Item.h"

using namespace std;

namespace sdds {
	void sdds::Item::setEmpty()
	{
		strcpy(m_name, "\0");
		/*m_quantity = 0;
		m_price = 0.0;*/
	}

	sdds::Item::Item()
	{
		//cout << "Item created";
		setEmpty();
	}

	sdds::Item::~Item()
	{
		//delete[] m_name;
		//cout << "Item is dying";
	}
}


