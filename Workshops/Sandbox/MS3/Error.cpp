/* Citation and Sources...
Final Project Milestone 3
Module: Error
Filename: Error.cpp
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/19  MS2 submission
2023/3/25  MS3 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds {
	void Error::setEmpty()
	{
		m_errMsg = nullptr;
	}
	void Error::clear()	//not for creation, for update
	{
		if (*this) {
			delete[] m_errMsg;
			m_errMsg = nullptr;
		}
	}
	ostream& Error::getMsg(ostream& ostr) const
	{
		if (*this) ostr << m_errMsg;
		return ostr;
	}
	Error::Error()
	{
		setEmpty();
	}
	Error::Error(const char* msg)
	{
		setEmpty();
		if (msg) {
			m_errMsg = new char[strlen(msg) + 1];
			strcpy(m_errMsg, msg);
		}
	}
	//copy constructor
	Error::Error(const Error& Ro)
	{
		setEmpty();
		operator=(Ro);
	}
	Error& Error::operator=(const Error& Ro)
	{
		if (this != &Ro && Ro.m_errMsg) {
			delete[] m_errMsg;
			m_errMsg = new char[strlen(Ro.m_errMsg) + 1];
			strcpy(m_errMsg, Ro.m_errMsg);
		}
		return *this;
	}
	Error::~Error()
	{
		delete[] m_errMsg;
	}
	Error& Error::operator=(const char* msg)
	{
		if (msg) {
			*this = Error(msg);
		}
		return *this;
	}
	Error::operator bool() const
	{
		return m_errMsg != nullptr;
	}
	ostream& operator<<(ostream& ostr, const Error& Ro)
	{
		if (Ro) {
			Ro.getMsg(ostr);
		}
		return ostr;
	}
}