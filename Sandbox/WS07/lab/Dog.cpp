#include "Dog.h"

using namespace std;

namespace sdds {
	Dog::Dog(const char* thename, int theage, double thecharge): Pet(thename) //Pet(thename, 0, 4.0)
	{
		m_numWalks = 0;
	}
	Dog& Dog::operator++(int)
	{
		if (this->isAlive()) {
			//provided by the professor start
			double healthDelta = 0.0;
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			//end
			applyHealthDelta(healthDelta);
			Pet::operator++(1);			//why unary takes arg?
			m_numWalks = 0;
		}
		
		return *this;
	}
	Dog& Dog::operator=(const Dog& Ro)
	{
		Pet::operator=(*this);
		m_numWalks = Ro.m_numWalks;
		addCharge(8.0);
		return *this;
	}
	void Dog::feed()
	{
		Pet::feed();
		if (this->isAlive()) {
			addCharge(0.25);
		}
	}
	void Dog::walk()
	{
		if (this->isAlive()) {
			m_numWalks += 1;
		} 
	}
	void Dog::reSpawn()
	{
		Pet::reSpawn();
		m_numWalks = 0;
		addCharge(1.0);
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