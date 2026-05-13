#include "PayrollSystem.h"
#include <fstream>

void PayrollSystem::addEmployee() {

    int type;

    cout << "\n1. Full Time Employee";
    cout << "\n2. Part Time Employee";
    cout << "\nChoose Employee Type: ";

    cin >> type;

    Employee* emp;

    if (type == 1) {

        emp = new FullTimeEmployee();
    }

    else {

        emp = new PartTimeEmployee();
    }

    emp->inputEmployee();

    employees.push_back(emp);

    cout << "Employee Added Successfully!\n";
}

void PayrollSystem::displayAllEmployees() {

    if (employees.empty()) {

        cout << "No Employees Found!\n";
        return;
    }

    for (int i = 0; i < employees.size(); i++) {

        employees[i]->displayEmployee();
    }
}

void PayrollSystem::searchEmployee() {

    int id;

    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < employees.size(); i++) {

        if (employees[i]->getID() == id) {

            employees[i]->displayEmployee();
            return;
        }
    }

    cout << "Employee Not Found!\n";
}

void PayrollSystem::deleteEmployee() {

    int id;

    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < employees.size(); i++) {

        if (employees[i]->getID() == id) {

            delete employees[i];

            employees.erase(employees.begin() + i);

            cout << "Employee Deleted!\n";
            return;
        }
    }

    cout << "Employee Not Found!\n";
}

void PayrollSystem::generateReport() {

    if (employees.empty()) {

        cout << "\nNo Employee Data Available!\n";
        return;
    }

    report.generatePayrollReport(employees);
}

void PayrollSystem::saveToFile() {

    ofstream outFile("employees.txt");

    for (int i = 0; i < employees.size(); i++) {

        employees[i]->writeToFile(outFile);
    }

    outFile.close();

    cout << "Data Saved Successfully!\n";
}

void PayrollSystem::loadFromFile() {

    ifstream inFile("employees.txt");

    if (!inFile) {

        cout << "No File Found!\n";
        return;
    }

    for (int i = 0; i < employees.size(); i++) {

        delete employees[i];
    }

    employees.clear();

    while (!inFile.eof()) {

        char type;

        inFile >> type;

        Employee* emp;

        if (type == 'F') {

            emp = new FullTimeEmployee();
        }

        else if (type == 'P') {

            emp = new PartTimeEmployee();
        }

        else {

            break;
        }

        emp->readFromFile(inFile);

        employees.push_back(emp);
    }

    inFile.close();

    cout << "Data Loaded Successfully!\n";
}

PayrollSystem::~PayrollSystem() {

    for (int i = 0; i < employees.size(); i++) {

        delete employees[i];
    }
}