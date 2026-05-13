#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <iostream>
using namespace std;

class Attendance {

private:
    int attendanceDays;

public:

    void setAttendance(int a) {
        attendanceDays = a;
    }

    int getAttendance() {
        return attendanceDays;
    }
};

#endif