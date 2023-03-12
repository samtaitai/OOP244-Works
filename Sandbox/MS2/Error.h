#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
	class Error {
		char* m_errMsg;
		void clear();
		

	public:
		Error();
		Error(const char* msg);
		Error(const Error& Ro);
		Error& operator=(const Error& Ro);
		~Error();
		Error& operator=(const char* msg);
		operator bool() const;
		std::ostream& getMsg(std::ostream& ostr = std::cout) const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& Ro);
}
#endif