#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee {

private:
    int hoursWorked;

public:

    void inputEmployee() override {

        Employee::inputEmployee();

        cout << "Enter Hours Worked: ";
        cin >> hoursWorked;
    }
    
    double calculateSalary() override {

    double hourlyRate = 500;

    // Basic Salary
    double basic =
        hoursWorked * hourlyRate;

    // Set salary object
    salary.setSalary(basic);

    // HRA = 10%
    double hra =
        basic * 0.10;

    // DA = 5%
    double da =
        basic * 0.05;

    // Bonus
    if (hoursWorked > 100) {

        bonus.setBonus(2000);
    }

    else {

        bonus.setBonus(0);
    }

    // Gross Salary
    double grossSalary =
        basic
        + hra
        + da
        + bonus.getBonus();

    // Tax = 5%
    double tax =
        grossSalary * 0.05;

    deduction.setDeduction(tax);

    // Final Salary
    return grossSalary
           - deduction.getDeduction();
}
    
    void displayEmployee() override {

        cout << "\n===== PART TIME EMPLOYEE =====";

        Employee::displayEmployee();

        cout << "Hours Worked: "
             << hoursWorked << endl;
    }

    void writeToFile(ofstream &outFile) override {

        outFile << "P "
                << id << " "
                << name << " "
                << department.getDepartment() << " "
                << designation.getDesignation() << " "
                << attendance.getAttendance() << " "
                << hoursWorked
                << endl;
    }

    void readFromFile(ifstream &inFile) override {

        string dept;
        string desig;
        int att;

        inFile >> id
               >> name
               >> dept
               >> desig
               >> att
               >> hoursWorked;

        department.setDepartment(dept);

        designation.setDesignation(desig);

        attendance.setAttendance(att);
    }
};

#endif