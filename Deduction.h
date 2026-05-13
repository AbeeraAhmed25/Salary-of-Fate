#ifndef DEDUCTION_H
#define DEDUCTION_H

#include <iostream>
using namespace std;

class Deduction {

private:
    double deduction;

public:

    void setDeduction(double d) {
        deduction = d;
    }

    double getDeduction() {
        return deduction;
    }
};

#endif