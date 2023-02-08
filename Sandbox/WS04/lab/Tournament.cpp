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
#include "Tournament.h"
using namespace std;

namespace sdds {

	Tournament::Tournament() {
		setEmpty();
	}

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		setTournament(name, noOfteam, soccer);
	}

	Tournament::~Tournament() {
		delete[] m_name;
		delete[] m_soccer;
	}

	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		if (name && noOfteam > 0 && soccer != nullptr) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_num = noOfteam;
			m_soccer = new SoccerTeam[m_num];
			for (int i = 0; i < m_num; i++) {
				m_soccer[i] = soccer[i];
			}
		}
		else {
			setEmpty();				//fixed delete[] issue
		}
	}

	void Tournament::setEmpty() {
		m_name = nullptr;
		m_num = 0;
		m_soccer = nullptr;
	}

	bool Tournament::isEmpty() const {
		bool isEmpty = false;
		if (m_name != nullptr && m_soccer != nullptr && m_num > 0) {
			isEmpty = true;
		}
		return isEmpty;
	}

	Tournament& Tournament::match(const SoccerTeam* ls) { 

		for (int i = 0; i < m_num - 1; i++) {
			if (ls[i].fouls() < ls[i + 1].fouls()) {			//compare [0] and [1] just one cycle 

				this->m_soccer[i + 1].m_noFouls *= 2;
				this->m_soccer[i + 1].calFines();
				this->m_soccer[i].m_goals++;
			}

			if (this->m_soccer[i + 1].fouls() > MAX_FOUL) {		//if exceed max foul,
				this->m_soccer[i + 1].setEmpty();				//goes invalid ok 
				//this->m_soccer[i + 1].m_noFouls = -1;
			}
		}

		return *this;
	}

	ostream& Tournament::display() const {

		if (this->m_name != nullptr && this->m_num > 0 && this->m_soccer != nullptr) {
			cout << "Tournament name: " << this->m_name << endl;
			cout << "list of the teams" << endl;
			//cout << endl;
			cout.fill(' ');
			cout.width(45);
			cout << "Fines";
			cout.width(10);
			cout << "Fouls";
			cout.width(10);
			cout << "Goals" << endl;
			
			for (int i = 0; i < this->m_num; i++) {
				cout << "Team[" << i + 1 << "] :";
				this->m_soccer[i].display() << endl;
			}
		}
		else {
			cout << "Invalid Tournament";
		}

		return cout;
	}
}
