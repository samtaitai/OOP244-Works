/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 1 Feb 2023
I was advised by the professor for the function 'updateName' 'addProjects' 'clearDeparment'.
Detailed takeouts will be noted in the reflect when I submit DIY.
*/
#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	class Department {
		char* m_name{}; //dma
		Project* m_projects{}; //dma array of Project 
		int m_noOfprojects{};
		double m_budget{ 15345.99 };

	public:
		void updateName(const char* newname);
		void updateBudget(double change);
		bool addProject(Project& newproject);
		void createDepartment(const char* newname, Project& newproject, double change);
		Project* fetchProjects() const;
		int fetchNumProjects() const;
		double fetchBudget() const;
		char* fetchName() const; //Department::fetchname? 
		double totalexpenses();
		double remainingBudget();
		void clearDepartment();

	};
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_