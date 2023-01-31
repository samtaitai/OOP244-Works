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
            cout << "Budget: " << department.fetchBudget() //15347(15345.99+1)? 
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    void Department::updateName(const char* newname) {
        //see if dept name is already set, 
        if (name != nullptr) { //if set, deallocate
            delete[] name;
            if (strlen(newname) != 0) { //then if provided name exitst(not empty), override
                name = new char(strlen(newname) + 1);
                strcpy(name, newname);
            } //else, previous name stays
        }
        else {
            if (strlen(newname) != 0) { //provided name exitst(not empty), set
                name = new char(strlen(newname) + 1);
                strcpy(name, newname);
            } //else, it remains 0
        }
    }
    void Department::updateBudget(double change) {
        //update budget by +change(extra budget?) 
        budget += change; //15345.99+1 = 15347
    }
    bool Department::addProject(Project& newproject) {

        bool added = false;
        double totalCost{}; 

        if (projects != nullptr) { //see if existing project be

            totalCost = totalexpenses() + newproject.m_cost; //existing expenses + this new one

            if ( budget - totalCost > 0) { //if 15345.99 - (budget + this cost) > 0
                Project* temp{};
                temp = new Project[noOfprojects + 1]; //allocate temp array = old size + 1
                temp = projects; //copy old projects to temp
                temp[noOfprojects] = newproject; //temp[last] = new project
                delete[] projects; //delete old array
                noOfprojects++; //# of project + 1
                projects = new Project[noOfprojects]; //allocate new array
                projects = temp; //copy temp to new array
                delete[] temp; //delete temp & returns true 
                added = true;
            }
        }
        else { //else there's nothing, create a project & returns true
            noOfprojects++;
            projects = new Project[noOfprojects];
            projects[0] = newproject;
            added = true;
        }
        return added; 
    }
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        //create one by updateName, addProject, updateBudget
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project* Department::fetchProjects() const {
        return projects;
    }
    int Department::fetchNumProjects() const {
        return noOfprojects;
    }
    double Department::fetchBudget() const { //????
        return budget;
    }
    char* Department::fetchName() const {
        return name;
    }
    double Department::totalexpenses() {
        double totalExp{};
        if (projects != nullptr) {
            for (int i = 0; i < noOfprojects; i++) {
                totalExp += projects[i].m_cost;
            }
        }
        return totalExp;
    }
    double Department::remainingBudget() {
        if (projects == nullptr) { //initially, budget is: 
            budget = 15345.99;
        }
        return budget - totalexpenses(); //initially, totalexpenses() = 0;
    }
    void Department::clearDepartment() {
        delete[] name;
        delete[] projects;
    }

}