#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <vector>

#include "Employee.h"

using namespace std;

class Report {

public:

    // Display complete payroll report
    void generatePayrollReport(
        vector<Employee*>& employees
    ) {

        cout << "\n======================================";
        cout << "\n         PAYROLL REPORT";
        cout << "\n======================================\n";

        double totalPayroll = 0;

        for (int i = 0; i < employees.size(); i++) {

            employees[i]->displayEmployee();

            totalPayroll +=
                employees[i]->calculateSalary();
        }

        cout << "\n======================================";

        cout << "\nTotal Payroll Expense: "
             << totalPayroll;

        cout << "\n======================================\n";
    }
};

#endif