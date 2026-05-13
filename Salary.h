#ifndef SALARY_H
#define SALARY_H

#include <iostream>
using namespace std;

class Salary {

private:
    double basicSalary;

public:

    void setSalary(double s) {
        basicSalary = s;
    }

    double getSalary() {
        return basicSalary;
    }
};

#endif