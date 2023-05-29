/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 15 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Dog.h"

using namespace std;

namespace sdds {
	Dog::Dog(const char* thename, int theage, double thecharge): Pet(thename, 0, COST_BASE) //Pet(thename, 0, 4.0)
	{
		m_numWalks = 0;
	}
	Dog& Dog::operator++(int)
	{
		if (isAlive()) {
			//provided by the professor start
			double healthDelta = 0.0;
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			//end
			applyHealthDelta(healthDelta);
			Pet::operator++(1);			
			m_numWalks = 0;
		}
		
		return *this;
	}
	Dog& Dog::operator=(const Dog& Ro)
	{
		Pet::operator=(Ro);
		m_numWalks = Ro.m_numWalks;
		addCharge(COST_BASE * 2);
		return *this;
	}
	void Dog::feed()
	{
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}
	}
	void Dog::walk()
	{
		if (isAlive()) {
			m_numWalks += 1;
		} 
	}
	void Dog::reSpawn()
	{
		Pet::reSpawn();
		m_numWalks = 0;
		addCharge(COST_REVIVE);
	}
	int Dog::getWalks()
	{
		return m_numWalks;
	}
	std::ostream& operator<<(std::ostream& ostr, Dog& Ro)
	{
		ostr << "** Generic Dog **" << endl;
		ostr << "   Walks: " << Ro.getWalks() << endl;
		Ro.outputData(ostr);
		return ostr;
	}
}