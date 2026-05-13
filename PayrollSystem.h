#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include <iostream>
#include <vector>

#include "Report.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

class PayrollSystem {

private:
    vector<Employee*> employees;
    Report report;

public:
   
    void addEmployee();
    void displayAllEmployees();
    void searchEmployee();
    void deleteEmployee();
    void generateReport();
    
    void saveToFile();
    void loadFromFile();

    ~PayrollSystem();
};

#endif