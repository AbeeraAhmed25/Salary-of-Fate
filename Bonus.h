#ifndef BONUS_H
#define BONUS_H

#include <iostream>
using namespace std;

class Bonus {

private:
    double bonus;

public:

    void setBonus(double b) {
        bonus = b;
    }

    double getBonus() {
        return bonus;
    }
};

#endif