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
		//otherwise, do nothing
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
	//This function will find out the winner between 2 soccer teams by having matches. It will loop through all the teams.
	/*
	First it will check which team is having more no of fouls.
	If first team is having less fouls then second team then, second team`s no of foul will increase by double 
	and fine will be increased by 20%

	First team`s goal will be increased by 1.

	If seconds team`s no of foul exceed the MAX_FOUL then this team will become a invalid team. 
	You can do this by setting the number to foul to an invalid value.

	At the end it will return the reference of the current object.
	*/
	Tournament& Tournament::match(const SoccerTeam* ls) { //it takes soccerteam's array = two teams 
														//single match result should change team itself
		/*
		char m_teamName[41];	
		int m_noFouls;			
		double m_fines;			
		int m_goals;
		*/

		SoccerTeam temp;
		int foul = 0;

		for (int i = 0; i < m_num - 1; i++) {
			if (ls[i].fouls() < ls[i + 1].fouls()) {			//compare [0] and [1] just one cycle 

				foul = this->m_soccer[i + 1].fouls() * 2;		//update foul 
				//this->m_soccer[i + 1].calFines();				//update fine inside ?? how to *1.2 fine?
				this->m_soccer[i + 1].setFine(-1, foul);		//only update foul, not fine
				//this->m_soccer[i + 1].setTeam(ls[i]);
				//how to +goal?
				
			}

			if (this->m_soccer[i + 1].fouls() > MAX_FOUL) {		//if exceed max foul,
				this->m_soccer[i + 1].setEmpty();				//goes invalid ok 
			}
		}

		return *this;
	}

	ostream& Tournament::display() const {

		if (this->m_name != nullptr && this->m_num > 0 && this->m_soccer != nullptr) {
			cout << "Tournament name: " << this->m_name << endl;
			cout << "list of the teams" << endl;
			cout << endl;
			cout.setf(ios::left);
			cout.width(30);
			cout << ' ';
			cout.width(6);
			cout << "Fines";
			cout.width(6);
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
