#ifndef DESIGNATION_H
#define DESIGNATION_H

#include <iostream>
using namespace std;

class Designation {

private:
    string designation;

public:

    void setDesignation(string d) {
        designation = d;
    }

    string getDesignation() {
        return designation;
    }
};

#endif