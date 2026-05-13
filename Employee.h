#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>

#include "Department.h"
#include "Designation.h"
#include "Attendance.h"
#include "Salary.h"
#include "Bonus.h"
#include "Deduction.h"

using namespace std;

class Employee {

protected:

    int id;
    string name;

    Department department;
    Designation designation;
    Attendance attendance;

    Salary salary;
    Bonus bonus;
    Deduction deduction;

public:

    virtual void inputEmployee() {

        string dept;
        string desig;
        int att;

        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Department: ";
        cin >> dept;

        department.setDepartment(dept);

        cout << "Enter Designation: ";
        cin >> desig;

        designation.setDesignation(desig);

        cout << "Enter Attendance Days: ";
        cin >> att;

        attendance.setAttendance(att);
    }

    virtual double calculateSalary() = 0;
    virtual void displayEmployee() {

    // Calculate first
    double finalSalary = calculateSalary();

    cout << "\n========================";

    cout << "\nEmployee ID: "
         << id;

    cout << "\nEmployee Name: "
         << name;

    cout << "\nDepartment: "
         << department.getDepartment();

    cout << "\nDesignation: "
         << designation.getDesignation();

    cout << "\nAttendance: "
         << attendance.getAttendance();

    cout << "\nBasic Salary: "
         << salary.getSalary();

    cout << "\nBonus: "
         << bonus.getBonus();

    cout << "\nDeduction: "
         << deduction.getDeduction();

    cout << "\nFinal Salary: "
         << finalSalary;

    cout << "\n========================\n";
}
    int getID() {
        return id;
    }

    virtual void writeToFile(ofstream &outFile) = 0;
    virtual void readFromFile(ifstream &inFile) = 0;

    virtual ~Employee() {}
};

#endif