/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 28 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds {
	Contact::Contact(const Contact& Ro):Person(Ro)
	{
		operator=(Ro);
	}
	Contact& Contact::operator=(const Contact& Ro)
	{
		if (this != &Ro) {
			Person::operator=(Ro);
			delAlloCopy(m_addr, Ro.m_addr);
			delAlloCopy(m_city, Ro.m_city);
			strCpy(m_province, Ro.m_province);
			strCpy(m_postalCode, Ro.m_postalCode);
		}
		return *this;
	}
	Contact::~Contact()			//erase everything because of virtual
	{
		//call Person's destructor automatically
		~*this;
	}
	std::istream& Contact::read(std::istream& istr)
	{
		//istr.clear();
		if (!istr.eof()) {
			~*this;
			Person::read(istr);	
			m_addr = dynRead(istr, ',');
			m_city = dynRead(istr, ',');
			istr.getline(m_province, 3, ',');
			istr.getline(m_postalCode, 7);
			if (istr.fail() || strLen(m_postalCode) != 6) ~*this;
		}
		return istr;
	}
	std::ostream& Contact::write(std::ostream& ostr) const
	{
		char temp[8]{};
		char tempPt1[4]{};
		char tempPt2[4]{};

		if (*this) {
			Person::write(ostr);
			ostr << endl;
			ostr << m_addr << endl;
			ostr << m_city << ' ' << m_province << endl;
			for (unsigned int i = 0; i < 3; i++) {
				tempPt1[i] = m_postalCode[i];
				tempPt2[i] = m_postalCode[i+3];
			}
			strCat(temp, tempPt1);
			strCat(temp, " ");
			strCat(temp, tempPt2);
			ostr << temp;
			ostr << endl;
		}
		return ostr;
	}
	Contact::operator bool() const
	{
		//return m_addr && m_addr[0] && m_city && m_city[0] && m_province[0] && m_postalCode[0];
		return m_addr && m_addr[0] != '\0' && m_city && m_city[0] != '\0' 
			&& m_province[0] != '\0' && m_postalCode[0] != '\0';
	}
	void Contact::operator~()	 
	{
		Person::operator~(); //should do this manually
		delete[] m_addr;
		delete[] m_city;
		m_addr = m_city = nullptr;
	}
	std::istream& operator>>(std::istream& leftOperand, Contact& rightOperand)
	{
		rightOperand.read(leftOperand);
		return leftOperand;
	}

	std::istream& operator>>(std::ifstream& leftOperand, Contact& rightOperand)
	{
		if (leftOperand) rightOperand.read(leftOperand);
		return leftOperand;
	}

	std::ostream& operator<<(std::ostream& leftOperand, const Contact& rightOperand)
	{
		rightOperand.write(leftOperand);
		return leftOperand;
	}
}