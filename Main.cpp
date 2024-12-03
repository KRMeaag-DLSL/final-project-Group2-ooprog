#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Database.h"
#include "Faculty.h"
#include "Global-Functions.h"
#include "Users.h"
#include "Admin.h"
#include "Students.h"

using namespace std;

Database* Database::instance = nullptr;

void adminHandler();

void facultyHandler(string accountID);

void studentHandler(string accountID);

int main() {
    Account user;
    int accountType; // Used to get account type after log-in for the switch case
    string accountID; // Used to get account ID after log-in, used to search subject 
                      // assigned to account for faculty acc and student information for students

    while (true) {
        clearScreen();

        cout << "\nWelcome to the International State College of the Philippines - Integrated School Student Management System!\n" << endl;
        cout << "Would you like to log-in or exit the program?" << endl;
        cout << "[1] Log-in" << endl;
        cout << "[2] Exit Program" << endl;
        cout << "\nType your choice: ";
        switch(inputMenu(2)) {
            case -1: 
                continue; // Loop Back
            case 1:
                // Continues Program
                break;
            case 2:
                cout << "\nExiting the program..." << endl;
                return 0;
        }
    
        clearScreen();
        if (user.login(&accountType, &accountID) != 0) {
            continue;
        } else {
            switch (accountType) {
                case 0:
                    adminHandler();
                    break;
                case 1:    
                    facultyHandler(accountID);
                    break;
                case 2:
                    studentHandler(accountID);
                    break;
            }
        }
    }

    return 0;
}

void adminHandler() {
    Admin admin;
    admin.menu();
}

void facultyHandler(string accountID) {
    Faculty faculty(accountID);
    faculty.menu();
}

void studentHandler(string accountID) {
    Student student(accountID);
    student.menu();
}