#ifndef FULLTIMEEMPLOYEE_H 
#define FULLTIMEEMPLOYEE_H  

#include "Employee.h" // Include the Employee class header file

class FullTimeEmployee : public Employee { // FullTimeEmployee class inherits from Employee class

public:

    double calculateSalary() override { 

        double basic;

        // Salary according to designation
        if (designation.getDesignation() == "Manager") {

            basic = 100000;
        }

        else if (designation.getDesignation() == "Developer") {

            basic = 70000;
        }

        else if (designation.getDesignation() == "Accountant") {

            basic = 50000;
        }

        else {

            basic = 35000;
        }

        salary.setSalary(basic);

        // Attendance based salary
        double earnedSalary =
            (basic / 30)
            * attendance.getAttendance();

        // HRA = 20%
        double hra =
            earnedSalary * 0.20;

        // DA = 10%
        double da =
            earnedSalary * 0.10;

        // Bonus
        if (attendance.getAttendance() >= 28) {

            bonus.setBonus(5000);
        }

        else {

            bonus.setBonus(0);
        }

        // Gross Salary
        double grossSalary =
            earnedSalary
            + hra
            + da
            + bonus.getBonus();

        // Tax = 10%
        double tax =
            grossSalary * 0.10;

        // Provident Fund = 5%
        double providentFund =
            grossSalary * 0.05;

        deduction.setDeduction(
            tax + providentFund
        );

        // Net Salary
        return grossSalary
               - deduction.getDeduction();
    }

    void displayEmployee() override { 
        cout << "\n===== FULL TIME EMPLOYEE =====";

        Employee::displayEmployee();
    }

    void writeToFile(ofstream &outFile) override { 
        outFile << "F "
                << id << " "
                << name << " "
                << department.getDepartment() << " "
                << designation.getDesignation() << " "
                << attendance.getAttendance()
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
               >> att;

        department.setDepartment(dept);

        designation.setDesignation(desig);

        attendance.setAttendance(att);
    }
};

#endif