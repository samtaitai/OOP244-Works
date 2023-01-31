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

        if (newname) {
            if (m_name != nullptr) {
                //delete[] m_name; //error fixed by not delete[]?? 
                m_name = nullptr;
                delete[] m_name; //nullptr first then delete to prevent memory leak?
                m_name = new char(strlen(newname) + 1);
                strcpy(m_name, newname);
            }
            else {
                m_name = new char(strlen(newname) + 1);
                strcpy(m_name, newname);
            }
        }
        
    }
    void Department::updateBudget(double change) {
        //update budget by +change(extra budget?) 
        m_budget += change; //15345.99+1 = 15347
    }
    bool Department::addProject(Project& newproject) {

        bool added = false;
        double totalCost{}; 

        if (m_projects != nullptr) { //see if existing project be

            totalCost = totalexpenses() + newproject.m_cost; //existing expenses + this new one

            if (m_budget - totalCost > 0) { //if 15345.99 - (budget + this cost) > 0
                Project* temp{};
                temp = new Project[m_noOfprojects + 1]; //allocate temp array = old size + 1
                temp = m_projects; //copy old projects to temp
                temp[m_noOfprojects] = newproject; //temp[last] = new project
                //delete[] m_projects; //delete old array error again? 
                m_projects = nullptr; //make it nullptr
                delete[] m_projects; //then free memory? 
                m_noOfprojects++; //# of project + 1
                m_projects = new Project[m_noOfprojects]; //allocate new array
                m_projects = temp; //copy temp to new array
                temp = nullptr;
                delete[] temp; //delete temp & returns true //error!
                added = true;
            }
        }
        else { //else there's nothing, create a project & returns true
            m_noOfprojects++;
            m_projects = new Project[m_noOfprojects];
            m_projects[0] = newproject;
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
        return m_projects;
    }
    int Department::fetchNumProjects() const {
        return m_noOfprojects;
    }
    double Department::fetchBudget() const { //????
        return m_budget;
    }
    char* Department::fetchName() const {
        return m_name;
    }
    double Department::totalexpenses() {
        double totalExp{};
        if (m_projects != nullptr) {
            for (int i = 0; i < m_noOfprojects; i++) {
                totalExp += m_projects[i].m_cost;
            }
        }
        return totalExp;
    }
    double Department::remainingBudget() {

        return m_budget - totalexpenses(); //initially, totalexpenses() = 0;
    }
    void Department::clearDepartment() {
        delete[] m_name;
        delete[] m_projects;
    }

}