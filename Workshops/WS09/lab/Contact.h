/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 28 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"

namespace sdds {
	class Contact :public Person {
		char* m_addr{};
		char* m_city{};
		char m_province[3]{};	//srsly???? 2 + 1!!
		char m_postalCode[7]{};
	public:
		Contact() = default;
		Contact(const Contact& Ro);
		Contact& operator=(const Contact& Ro);
		virtual ~Contact();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		operator bool()const;
		void operator~();
	};
	std::istream& operator>>(std::istream& leftOperand, Contact& rightOperand);
	std::istream& operator>>(std::ifstream& leftOperand, Contact& rightOperand);
	std::ostream& operator<<(std::ostream& leftOperand, const Contact& rightOperand);
}

#endif // !SDDS_CONTACT_H
