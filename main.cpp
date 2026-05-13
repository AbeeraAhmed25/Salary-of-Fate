#include <iostream>

#include "Admin.h"
#include "User.h"
#include "PayrollSystem.h"

using namespace std;

void showAdminMenu() {

cout << R"(

==================================================================

   $$$$$$\   $$$$$$\  $$\        $$$$$$\  $$$$$$$\  $$\     $$\
  $$  __$$\ $$  __$$\ $$ |      $$  __$$\ $$  __$$\ \$$\   $$  |
  $$ /  \__|$$ /  $$ |$$ |      $$ /  $$ |$$ |  $$ | \$$\ $$  /
  \$$$$$$\  $$$$$$$$ |$$ |      $$$$$$$$ |$$$$$$$  |  \$$$$  /
   \____$$\ $$  __$$ |$$ |      $$  __$$ |$$  __$$<    \$$  /
  $$\   $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |    $$ |
  \$$$$$$  |$$ |  $$ |$$$$$$$$\ $$ |  $$ |$$ |  $$ |    $$ |
   \______/ \__|  \__|\________|\__|  \__|\__|  \__|    \__|

                 S A L A R Y   O F   F A T E

==================================================================
                    PAYROLL MANAGEMENT SYSTEM
==================================================================

)" << endl;
    cout << "\n\n========= ADMIN MENU =========";

    cout << "\n1. Add Employee";
    cout << "\n2. Display All Employees";
    cout << "\n3. Search Employee";
    cout << "\n4. Delete Employee";
    cout << "\n5. Save Data";
    cout << "\n6. Load Data";
    cout << "\n7. Generate Report";
    cout << "\n0. Logout";

    cout << "\n======================================\n";
}

void showUserMenu() {

    cout << R"(

==================================================================

   $$$$$$\   $$$$$$\  $$\        $$$$$$\  $$$$$$$\  $$\     $$\
  $$  __$$\ $$  __$$\ $$ |      $$  __$$\ $$  __$$\ \$$\   $$  |
  $$ /  \__|$$ /  $$ |$$ |      $$ /  $$ |$$ |  $$ | \$$\ $$  /
  \$$$$$$\  $$$$$$$$ |$$ |      $$$$$$$$ |$$$$$$$  |  \$$$$  /
   \____$$\ $$  __$$ |$$ |      $$  __$$ |$$  __$$<    \$$  /
  $$\   $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |    $$ |
  \$$$$$$  |$$ |  $$ |$$$$$$$$\ $$ |  $$ |$$ |  $$ |    $$ |
   \______/ \__|  \__|\________|\__|  \__|\__|  \__|    \__|

                 S A L A R Y   O F   F A T E

==================================================================
                    PAYROLL MANAGEMENT SYSTEM
==================================================================

)" << endl;
    cout << "\n\n========= USER MENU =========";

    cout << "\n1. Display All Employees";
    cout << "\n2. Search Employee";
    cout << "\n3. Load Data";
    cout << "\n4. Generate Report";
    cout << "\n0. Logout";

    cout << "\n======================================\n";
}

int main() {

    PayrollSystem system;

    Admin admin;

    User user("user", "123");

    int roleChoice;

    string username;
    string password;

    cout << "\n======================================";
    cout << "\n         SALARY OF FATE";
    cout << "\n======================================";

    cout << "\n\n1. Admin Login";
    cout << "\n2. User Login";

    cout << "\n\nEnter Choice: ";
    cin >> roleChoice;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // ================= ADMIN =================

    if (roleChoice == 1
        && admin.login(username, password)) {

        cout << "\n\nAdmin Login Successful!\n";

        int choice;

        showAdminMenu();

        do {

            cout << "\nSelect Option: ";
            cin >> choice;

            switch(choice) {

            case 1:
                system.addEmployee();
                break;

            case 2:
                system.displayAllEmployees();
                break;

            case 3:
                system.searchEmployee();
                break;

            case 4:
                system.deleteEmployee();
                break;
            
            case 5:
                system.saveToFile();
                break;

            case 6:
                system.loadFromFile();
                break;

            case 7:
                system.generateReport();
                break;

            case 0:
                cout << "\nLogging Out...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
            }

            if(choice != 0) {

                cout << "\n----------------------------------";
                cout << "\nSelect another option from menu.";
                cout << "\n----------------------------------\n";
            }

        } while(choice != 0);
    }

    // ================= USER =================

    else if (roleChoice == 2
             && user.login(username, password)) {

        cout << "\n\nUser Login Successful!\n";

        int choice;

        showUserMenu();

        do {

            cout << "\nSelect Option: ";
            cin >> choice;

            switch(choice) {

            case 1:
                system.displayAllEmployees();
                break;

            case 2:
                system.searchEmployee();
                break;

            case 3:
                system.loadFromFile();
                break;

            case 0:
                cout << "\nLogging Out...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
            }

            if(choice != 0) {

                cout << "\n----------------------------------";
                cout << "\nSelect another option from menu.";
                cout << "\n----------------------------------\n";
            }

        } while(choice != 0);
    }

    else {

        cout << "\nInvalid Username or Password!\n";
    }

    return 0;
}