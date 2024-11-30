#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Global-Functions.h"
#include "Users.h"
#include "Database.h"

class Faculty : public Account {
    private:
        string facultyID;
        string currentSubject;
        string assignedSection;

    public:
        Faculty(string facultyID) : facultyID(facultyID) {
            ifstream fin;
            string line;

            fin.open("MA2_Teacher-Subject-DB - Sheet1.CSV", ios::in);

            if (!fin.is_open()) {
                cerr << "Error! Unable to open account information file" << endl;
                return;
            }

            getline(fin, line); // Skips line

            while(getline(fin, line)) {
                string userID, subject, section;
                stringstream s(line);
                
                getline(s, userID, ',');
                getline(s, subject, ',');
                getline(s, section, ',');

                if (userID == facultyID) {
                    currentSubject = subject;
                    assignedSection = section;
                }
            }
        }

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

                cout << "Type your choice: ";
                switch (inputMenu(6)) {
                    case -1:
                        continue;
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
                        return;
                        // logout();
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

        void updateGrades() {
            Database* db = Database::getInstance();
            vector<Grade>& grades = db->getGrades();
            string subjects[] = {
                "English",
                "Science",
                "Mathematics",
                "Filipino",
                "Social Studies",
                "CLCE",
                "TLE",
                "MAPEH"
            };

            int searchID;
            int keyDatabase = -1;
            int subjectIndex;
            double newGrade;
            
            cout << "Which student's grades would you want to update?" << endl;
            cout << "Type student number here: ";
            searchID = inputStudentID();
            

            // Input Error
            if (searchID == -1) {
                continueToNext();
                return;
            }

            // Search for Student in Database
            for (int i = 0; grades.size(); i++) {
                if (grades[i].getStudentID() == searchID) {
                    keyDatabase = i;
                }
            }

            // Student Not Found
            if (keyDatabase == -1) {
                cout << "ID does not match any student in the database." << endl;
                continueToNext();
                return;
            }

            // Find Subject Associated with Teacher
            for (int i = 0; i < 8; i++) {
                if (currentSubject == subjects[i]) {
                    subjectIndex = i;
                }
            }

            // Assign New Grade

            cout << "\nInput new grade: ";
            inputNum(&newGrade);

            switch (subjectIndex) {
                case 0: // English
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 1: // Science
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 2: // Mathematics
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 3: // Filipino
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 4: // Social Studies
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 5: // CLCE
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 6: // TLE
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 7: // MAPEH
                    grades[keyDatabase].setEnglish(newGrade);
                    break;
            }
        }

        void updateAttendance() {

        }

        void updateStudentPerformance() {
            int choice;
            bool loopMenu = true;

            // Main Menu
            while (loopMenu) {
                clearScreen();
                cout << "Select from the following to edit:" << endl;

                cout << "[1] Grades" << endl;
                cout << "[2] Attendance" << endl;
                cout << "[3] Cancel Editing Student Performance" << endl;

                cout << "Type your choice: ";
                switch (inputMenu(3)) {
                    case -1:
                        continue;
                    case 1:
                        deadlineSubMenu();
                        break;
                    case 2:
                        updateStudentPerformance();
                        break;
                    case 3:
                        return;
                }
            }

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