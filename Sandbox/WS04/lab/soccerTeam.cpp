/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "soccerTeam.h"
using namespace std;

namespace sdds {

	SoccerTeam::SoccerTeam() {
		setEmpty();
	}

	/*
	SoccerTeam(),				//default constructor
	SoccerTeam("",100.0,0),		//3 argumnet constructor
	SoccerTeam("Bad1",200,-1)	
	*/
	
	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
		setName(tname);
		setFine(fines, foul);
		m_goals = 0;
	}

	//It will set the team name, fine and fouls of the team. ??????
	void SoccerTeam::setTeam(const SoccerTeam& team) {
		setName(team.m_teamName);
		setFine(team.m_fines, team.m_noFouls);
	}
	//If the received name pointer is valid and not null 
	//it will copy the received name to the data member m_teamName
	void SoccerTeam::setName(const char* tname) {
		if (tname) {
			strcpy(m_teamName, tname);
		}
		//otherwise, do nothing
	}
	//It will receive the information about fines and no of foul. 
	//After checking the validity it will set the values to the appropriate data members. 
	//Fine and foul should be grater than and equal to zero. 
	//Otherwise, it will set the soccerTeam object to an empty state.
	void SoccerTeam::setFine(double fines, int foul) {
		if (fines >= 0.0 && foul >= 0) {
			m_noFouls = foul;
			m_fines = fines;
		}
		//otherwise, do nothing
	}
	////Sets the soccerTeam object to an Empty State. 
	//Do this by setting the m_teamName to an empty Cstring, m_noFoul and m_fines to a negative number 
	//and m_goals to 0.
	void SoccerTeam::setEmpty() {
		strcpy(m_teamName, "\0");
		m_noFouls = -1;
		m_fines = -1.0;
		m_goals = 0;
	}
	//Returns true if m_teamName is not null, m_fines and m_noFouls is grater than 0.
	bool SoccerTeam::isEmpty() const {
		bool isEmpty = false;
		if (m_teamName && m_fines > 0.0 && m_noFouls > 0) {
			isEmpty = true;
		}
		return isEmpty;
	}
	//If this function is called it will increases the fine by 20% of the old fine value.
	void SoccerTeam::calFines() {
		m_fines = m_fines * 1.2; 
	}
	//It will return the m_noFoul
	int SoccerTeam::fouls() const {
		return m_noFouls;
	}
	//If a soccerTeam object is valid
	//otherwise prints, "Invalid Team".
	//At the end return the reference of the ostream object.
	ostream& SoccerTeam::display()const {
		
		//ostream& ostr;

		/*
		a) prints m_teamName with width 30, left justified and fill with empty spaces.
		b) prints m_fines with width 6 and after the decimal point 2 digits.
		c) prints m_noFoul with width 6
		d) prints m_fines with width 6
		e) prints m_golas with width 10. If number of goals are greater than zero then it will print "w" besides the number.
		*/

		if (m_teamName[0] != '\0' && m_noFouls > -1) {
			cout.setf(ios::left);
			cout.width(30);
			cout << m_teamName;
			cout.width(6);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_fines;
			cout.unsetf(ios::fixed);
			cout.width(6);
			cout << m_noFouls;
			cout.width(10);
			if (m_goals > 0) {
				cout << m_goals << "w";
			}
			else {
				cout << m_goals;
			}
		}
		else {
			cout << "Invalid Team";
		}
		return cout; //?????
	}
}
