/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 
*/
#ifndef SDDS_SOCCERTEAM_H_
#define SDDS_SOCCERTEAM_H_
#include <iostream>

namespace sdds {

	const int MAX_FOUL = 4; //maximum number of fouls

	class SoccerTeam
	{
		char m_teamName[41];	
		int m_noFouls;			
		double m_fines;			
		int m_goals;			

	public:
		SoccerTeam();
		SoccerTeam(const char* tname, double fines, int foul);

		void setTeam(const SoccerTeam& team);
		void setName(const char* tname);
		void setFine(double fines, int foul);
		void setGoal(int goal);		//my addition
		void setEmpty();
		bool isEmpty() const;
		double calFines();			//my addition-return type change
		int fouls() const;
		int goals() const;			//my addition
		std::ostream& display()const; //??
	};

}

#endif


