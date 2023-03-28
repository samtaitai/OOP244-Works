#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"

namespace sdds {
	class Contact :public Person {
		char* m_addr = nullptr;
		char* m_city = nullptr;
		char m_province[2]{};
		char m_postalCode[6]{};
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
