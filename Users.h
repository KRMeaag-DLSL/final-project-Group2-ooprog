#pragma once
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Global-Functions.h"

using namespace std;

class Account {
    private:
        string username;
        string password;

    public:
        int login(int* accountType, string* accountID) {
            string line;
            cout << "\nUsername: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            ifstream fin;
            fin.open("MA2_Accounts-Information-DB - Sheet1.csv", ios::in);

            if (!fin.is_open()) {
                cerr << "Error! Unable to open account information file" << endl;
                return 1; // Error - File I/O is not working
            }

            getline(fin,line);

            while(getline(fin, line)) {
                string checkUser, checkPassword, userType;
                stringstream s(line);

                getline(s,checkUser, ',');
                getline(s,checkPassword, ',');
                getline(s,userType, ',');

                if (username == checkUser && password == checkPassword) {
                    if (userType == "Admin") {
                        *accountType = 0; // User Type 0 Means Admin
                    } else if (userType == "Faculty") {
                        *accountType = 1; // User Type 1 Means Faculty
                    } else if (userType == "Student") {
                        *accountType = 2; // User Type 2 Means Student
                    }

                    *accountID = checkUser;

                    return 0; // No errors
                }
            }

            clearScreen();
            cout << "\nLogin failed. Please check your username and password." << endl;
            continueToNext();
            return 2; // Error - Incorrect Credentials
        }

        bool logout() {
            string choice;

            clearScreen();
            while (true) {
                cout << "\nAre you sure you want to log out? [Y/N]: ";
                cin >> choice;
                if (choice.length() != 1 || (toupper(choice[0]) != 'Y' && toupper(choice[0]) != 'N')) {
                    cout << "\nInvalid input, please try again!" << endl;
                } else if (toupper(choice[0]) == 'Y') {
                    return true; // User logged out
                } else if (toupper(choice[0]) == 'N') {
                    return false; // User did not choose to log-out
                }
            }
        }

        virtual void menu() {}
};