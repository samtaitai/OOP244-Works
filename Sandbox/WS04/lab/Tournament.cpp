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

	//By default a Tournament is initiated by setting all the member variable values to default values. 
	//You can do this by setting m_name, m_soccer to nullptr and m_num to a value like 0.
	Tournament::Tournament() {
		setEmpty();
	}
	//It works exactly like the setTournamnet()
	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		setTournament(name, noOfteam, soccer);
	}
	//Deallocate the memory allocated by m_name and m_soccer.
	Tournament::~Tournament() {
		delete[] m_name;
		delete[] m_soccer;
	}

	/*
	First, it will check the validity of all the received arguments. Tournament name should be valid and non-empty Cstring. 
	Number of teams should be greater than zero.

	It will set m_num to the corresponding argument value.
	
	Then it will dynamically allocate memory for tournament name in the tournament name pointer attribute 
	and then copies the content of the tournament name argument into the newly allocated memory.
	
	It will dynamically allocate an array of soccer team pointed by m_soccer member variable. The length of this array will be m_num.
	Lastly, add all the teams to the dynamically allocated array of m_soccer.

	If any of the arguments are not valid it will set the Tournament to an empty state.
	*/
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
	//Sets the Tournamnet object to an Empty State. Do this by setting the m_name and m_soccer to null and m_num to 0.
	void Tournament::setEmpty() {
		m_name = nullptr;
		m_num = 0;
		m_soccer = nullptr;
	}
	//Returns true if m_name and m_soccer is not null and m_num is grater than 0.
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
	Tournament& Tournament::match(const SoccerTeam* ls) {

		for (int i = 0; i < m_num; i++) {
			


		}
		return *this;
	}
	//If Tournament object is valid
	//otherwise prints, "Invalid Tournament".
	//At the end return the reference of the ostream object.
	ostream& Tournament::display() const {
	}

}
