/* Citation and Sources...
Final Project Milestone 4
Module: Error
Filename: Error.h
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/19  MS2 submission
2023/3/25  MS3 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
	class Error {
		char* m_errMsg;

	public:
		void setEmpty();
		void clear();
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