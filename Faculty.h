#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Users.h"
#include "Database.h"

class Faculty : public Account {
    private:
        string facultyID;
        string currentSubject;

    public:
        Faculty(string facultyID) : facultyID(facultyID) {}

        string getFacultyID() {
            return facultyID;
        }

        string getCurrentSubject() {
            return currentSubject;
        }

        void menu() override {
            int choice;
            bool loopMenu = true;

            // Main Menu
            while (loopMenu) {
                clearScreen();
                cout << "Good day, " << facultyID << "! Please pick from the following:" << endl;

                cout << "[1] Manage Deadlines" << endl;
                cout << "[2] Update Student Performance" << endl;
                cout << "[3] Search Student" << endl;
                cout << "[4] Display Full List of Students" << endl;
                cout << "[5] Create Disciplinary Record" << endl;
                cout << "[6] Log-out" << endl;

                choice = inputMenu(6);

                if (choice == -1) {
                    continue;
                }

                switch (choice) {
                    case 1:
                        deadlineSubMenu();
                        break;
                    case 2:
                        updateStudentPerformance();
                        break;
                    case 3:
                        searchStudent();
                        break;
                    case 4:
                        displayStudentList();
                        break;
                    case 5:
                        createDisciplinaryRecord();
                        break;
                    case 6:
                        logout();
                        break;
                }
            }
        }

        void deadlineSubMenu() {
            string choice;
            cout << "Deadline Menu" << endl;
            cout << "Type anything to continue: ";
            cin >> choice;
        }

        void createDeadline() {}

        void updateDeadline() {}

        void deleteDeadline() {}

        void searchStudent() {
            string choice;
            cout << "Search Student Menu" << endl;
            cout << "Type anything to continue: ";
            cin >> choice;
        }

        void updateStudentPerformance() {
            string choice;
            cout << "Update Student Performance Menu" << endl;
            cout << "Type anything to continue: ";
            cin >> choice;
        }

        void createDisciplinaryRecord() {
            string choice;
            cout << "Create Disciplinary Record Menu" << endl;
            cout << "Type anything to continue: ";
            cin >> choice;
        }

        void displayStudentList() {
            string choice;
            cout << "Display Student List Menu" << endl;
            cout << "Type anything to continue: ";
            cin >> choice;
        }
};