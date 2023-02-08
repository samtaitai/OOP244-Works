/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 8 Feb 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Soccer.h"
using namespace std;

namespace sdds {

	SoccerTeam::SoccerTeam() {
		setEmpty();
	}

	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
		setName(tname);
		setFine(fines, foul);
		m_goals = 0;
	}

	void SoccerTeam::setTeam(const SoccerTeam& team) {
		setName(team.m_teamName);
		setFine(team.m_fines, team.m_noFouls);
	}

	void SoccerTeam::setName(const char* tname) {
		if (tname) {
			strcpy(m_teamName, tname);
		}
		else {
			setEmpty();
		}
	}

	void SoccerTeam::setFine(double fines, int foul) {
		if (foul >= 0 && fines >= 0.0) {
			m_noFouls = foul;
			m_fines = fines;
		}
		else {
			setEmpty();
		}
	}

	void SoccerTeam::setEmpty() {
		strcpy(m_teamName, "\0");
		m_noFouls = -1;
		m_fines = -1.0;
		m_goals = 0;
	}

	bool SoccerTeam::isEmpty() const {
		bool isEmpty = false;
		if (m_teamName && m_fines > 0.0 && m_noFouls > 0) {
			isEmpty = true;
		}
		return isEmpty;
	}

	void SoccerTeam::calFines() { //original 
		m_fines = m_fines * 1.2; 
	}

	int SoccerTeam::fouls() const {
		return m_noFouls;
	}

	ostream& SoccerTeam::display()const {
		
		if (m_teamName[0] != '\0' && m_noFouls > -1) {
			cout.setf(ios::left);		//this one!
			cout.width(30);
			cout << m_teamName;
			cout.unsetf(ios::left);		//alignment fixed!!
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
		return cout; 
	}
}
