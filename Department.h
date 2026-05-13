#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
using namespace std;

class Department {

private:
    string departmentName;

public:

    void setDepartment(string d) {
        departmentName = d;
    }

    string getDepartment() {
        return departmentName;
    }
};

#endif