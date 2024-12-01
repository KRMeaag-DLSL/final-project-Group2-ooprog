#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Users.h"
#include "Global-Functions.h"
#include "Database.h"

using namespace std;

class Admin : Account{
    private:
        string adminID;

    public:
        void createStudentEntry() {
            clearScreen();
            string section, name, contact, address, emailAddress, department;
            int id, age;
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Student Section: ";
            getline(cin, section);
            cout << "Enter Student Age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Student Address: ";
            getline(cin, address);
            cout << "Enter Student Email: ";
            getline(cin, emailAddress);
            cout << "Enter Student Department: ";
            getline(cin, department);

            Database::getInstance()->getStudentEntries().push_back(
                StudentEntry(id,section,name,age,contact,address,emailAddress,department));
            Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);

        }
        void createDisciplinaryRecord() {}
        void searchStudent() {}
        void analytics() {}
        void updateDisciplinaryRecords() {}
        void updateStudentPerformance() {}
        void assignFaculty() {}
        void updateStudentInfo() {}
        void deleteStudentEntry() {}
        void removeDisciplinaryRecord() {}
        void displayStudents() {}

        void menu() override {
            int choice;
            bool loopMenu = true;

            // Main Menu
            while (loopMenu) {
                clearScreen();
                cout << "Good day, " << adminID << "! Please pick from the following:" << endl;

                cout << "[1] Create Student Entry" << endl
                    << "[2] Create Disciplinary Record" << endl
                    << "[3] Search Student" << endl
                    << "[4] Analytics" << endl
                    << "[5] Update Disciplinary Records" << endl
                    << "[6] Update Student Performance" << endl
                    << "[7] Assign Faculty" << endl
                    << "[8] Update Student Info" << endl
                    << "[9] Delete Student Entry" << endl
                    << "[10] Remove Disciplinary Record" << endl
                    << "[11] Display Students" << endl;

                choice = inputMenu(6);

                if (choice == -1) {
                    continue;
                }

                switch (choice) {
                    case 1:
                        createStudentEntry();
                        break;
                    case 2:
                        createDisciplinaryRecord();
                        break;
                    case 3:
                        searchStudent();
                        break;
                    case 4:
                        analytics();
                        break;
                    case 5:
                        updateDisciplinaryRecords();
                        break;
                    case 6:
                        updateStudentPerformance();
                        break;
                    case 7:
                        assignFaculty();
                        break;
                    case 8:
                        updateStudentInfo();
                        break;
                    case 9:
                        deleteStudentEntry();
                        break;
                    case 10:
                        removeDisciplinaryRecord();
                        break;
                    case 11:
                        displayStudents();
                        break;
                }
            }
        }

};