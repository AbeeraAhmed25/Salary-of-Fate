#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {

public:

    Admin(string u = "admin", string p = "123")
        : User(u, p) {
    }
};

#endif