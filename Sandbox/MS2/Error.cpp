#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds {
	void Error::clear()
	{
		m_errMsg = nullptr;
	}
	ostream& Error::getMsg(ostream& ostr) const
	{
		if (*this) ostr << m_errMsg;
		return ostr;
	}
	Error::Error()
	{
		clear();
	}
	Error::Error(const char* msg)
	{
		clear();
		if (msg) strcpy(m_errMsg, msg);
	}
	Error::Error(const Error& Ro)
	{
		clear();
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