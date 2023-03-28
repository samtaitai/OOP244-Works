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
		delete[] m_addr;
		delete[] m_city;
	}
	std::istream& Contact::read(std::istream& istr)
	{
		if (!istr.eof()) {
			~*this;				//clean up only Derived's
			Person::read(istr);	//this will clean up Base's 
			m_addr = dynRead(istr, ',');
			m_city = dynRead(istr, ',');
			istr.getline(m_province, 3, ',');
			istr.getline(m_postalCode, 7);
			if (istr.fail()) {
				~*this;
				//istr.clear();
			}
		}
		return istr;
	}
	std::ostream& Contact::write(std::ostream& ostr) const
	{
		if (*this) {
			Person::write(ostr);
			ostr << endl;
			ostr << m_addr << endl;
			ostr << m_city << ' ';
			for (unsigned int i = 0; i < 2; i++) {	//is it only way?
				ostr << m_province[i];
			}
			ostr << endl;
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
	void Contact::operator~()	//when you want to erase only Derived's part? 
	{
		//Person::operator~();
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