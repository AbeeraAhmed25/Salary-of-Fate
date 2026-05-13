#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {

protected:
    string username;
    string password;

public:

    User(string u = "", string p = "") {

        username = u;
        password = p;
    }

    bool login(string u, string p) {

        return (u == username && p == password);
    }
};
#endif