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
		cout << "Contact destructor\n";
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
		if (*this) {
			Person::write(ostr);
			ostr << endl;
			ostr << m_addr << endl;
			ostr << m_city << ' ' << m_province << endl;
			for (unsigned int i = 0; i < 3; i++) {
				ostr << m_postalCode[i];
			}
			ostr << ' ';
			for (unsigned int i = 3; i < 6; i++) {
				ostr << m_postalCode[i];
			}
			ostr << endl;
		}
		return ostr;
	}
	Contact::operator bool() const
	{
		return m_addr && m_addr[0] && m_city && m_city[0] && m_province[0] && m_postalCode[0];
	}
	void Contact::operator~()	 
	{
		Person::operator~(); 
		delete[] m_addr;
		delete[] m_city;
		m_addr = m_city = nullptr;
		cout << "Contact ~ working...\n";
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