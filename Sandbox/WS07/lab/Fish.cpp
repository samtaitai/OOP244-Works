/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 15 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Fish.h"

using namespace std;

namespace sdds {
	//Pet(const char* name, int age = 0, double incrBaseCharge = 0);
	Fish::Fish(const char* thename, int theage, double thecharge): Pet(thename) //Pet(thename, 0, 2.0)
	{
		//do nothing
	}
	void Fish::feed()
	{
		Pet::feed();
		if (this->isAlive()) {
			addCharge(0.1);
		}
	}
	void Fish::reSpawn()
	{
		Pet::reSpawn();
		addCharge(0.5);
	}
	Fish& Fish::operator++(int)
	{
		if (this->isAlive()) {
			//provided by the professor start
			double healthDelta = 0.0;
			healthDelta += 0.20 * (getFeeds() - 1);
			//end
			applyHealthDelta(healthDelta);
			Pet::operator++(1);			//why unary takes arg?
		}
		return *this;
	}
	Fish& Fish::operator=(const Fish& Ro)
	{
		Pet::operator=(Ro);
		addCharge(4.0);
		return *this;
	}
	ostream& operator<<(ostream& ostr, Fish& Ro) {
		
		ostr << "** Generic Fish **" << endl;
		Ro.outputData(ostr);
		
		return ostr;
	}
}