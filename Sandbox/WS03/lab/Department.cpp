#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    void Department::updateName(const char* newname) {
        //see if dept name is already set, 

        //if set, deallocate
            //then if provided name exitst(not empty), override

            //else, previous name stays

        //else
            //provided name exitst(not empty), set

            //else, it remains 0
    }
    void Department::updateBudget(double change) {
        //
    }
    bool Department::addProject(Project& newproject) {
    }
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
    }
    Project* Department::fetchProjects() const {
    }
    int Department::fetchNumProjects() const {
    }
    double Department::fetchBudget() const {
    }
    char* Department::fetchName() const {
    }
    double Department::totalexpenses() {
    }
    double Department::remainingBudget() {
    }
    void Department::clearDepartment() {
    }

}