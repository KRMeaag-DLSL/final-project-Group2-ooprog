#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Global-Functions.h"
#include "Users.h"
#include "Database.h"

class Faculty : public Account {
    private:
        string facultyID;
        string currentSubject;
        string assignedSection;

    public:
        Faculty(string facultyID) : facultyID(facultyID), currentSubject("Default"), assignedSection("Default") {
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
                getline(s, section, ',');
                getline(s, subject, ',');

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

        string getAssignedSection() {
            return assignedSection;
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

        void createDeadline() {
            vector<Deadline>& deadlines = Database::getInstance()->getDeadlines();
        }

        void updateDeadline() {
            vector<Deadline>& deadlines = Database::getInstance()->getDeadlines();
        }

        void deleteDeadline() {
            vector<Deadline>& deadlines = Database::getInstance()->getDeadlines();
        }

        void deadlineSubMenu() {
            vector<Deadline>& deadlines = Database::getInstance()->getDeadlines();


        }

        void searchStudent() {
            vector<StudentEntry> entry = Database::getInstance()->getStudentEntries();
            int searchID;
            
            clearScreen();
            cout << "Which student do you want to search for?" << endl;
            cout << "Type the student's ID number: ";
            searchID = inputStudentID();

            // Input Error
            if (searchID == -1) {
                return;
            }

            for (auto& student : entry) {
                if (searchID == student.getStudentID()) {
                    // Student is not under teacher's section
                    if (assignedSection != student.getSection()) {
                        cout << "\nYou are not allowed to view this student's information. Student is assigned to another section" << endl;
                        continueToNext();
                        return;
                    }

                    cout << "\nEntry Found!" << endl;
                    cout << "Student ID: " << student.getStudentID() << endl;
                    cout << "Student Section " << student.getSection() << endl;
                    cout << "Student Name: " << student.getName() << endl;
                    cout << "Student Age: " << student.getAge() << endl;
                    cout << "Student Contact: " << student.getContact() << endl;
                    cout << "Student Address: " << student.getAddress() << endl;
                    cout << "Student Email Address: " << student.getEmailAddress() << endl;
                    cout << "Student Department: " << student.getDepartment() << endl << endl;

                    continueToNext();
                    return;
                }
            }

            cout << "\nStudent ID does not exist in the database." << endl;
            continueToNext();
            return;
        }

        void updateGrades() {
            Database* db = Database::getInstance();
            vector<Grade>& grades = db->getGrades();
            const string subjects[] = {
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
            
            clearScreen();
            cout << "Which student's grades would you want to update?" << endl;
            cout << "Type the student's ID number: ";
            searchID = inputStudentID();

            // Input Error
            if (searchID == -1) {
                return;
            }

            // Search for Student in Database
            for (int i = 0; i < grades.size(); i++) {
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

            // Checks for error before changing grade
            if (!inputDoubleNum(&newGrade)) {
                return;
            }

            // Assigns new grade based on teacher's subject
            switch (subjectIndex) {
                case 0: // English
                    grades[keyDatabase].setEnglish(newGrade);
                    break;

                case 1: // Science
                    grades[keyDatabase].setScience(newGrade);
                    break;

                case 2: // Mathematics
                    grades[keyDatabase].setMath(newGrade);
                    break;

                case 3: // Filipino
                    grades[keyDatabase].setFilipino(newGrade);
                    break;

                case 4: // Social Studies
                    grades[keyDatabase].setSocStud(newGrade);
                    break;

                case 5: // CLCE
                    grades[keyDatabase].setCLCE(newGrade);
                    break;

                case 6: // TLE
                    grades[keyDatabase].setTLE(newGrade);
                    break;

                case 7: // MAPEH
                    grades[keyDatabase].setMAPEH(newGrade);
                    break;
            }

            // Saves data
            db->saveData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);

            cout << "\nSuccessfully saved the changes to the student's grades." << endl;
            continueToNext();
        }

        void updateAttendance() {
            Database* db = Database::getInstance();
            vector<Attendance>& attendance = db->getAttendance();

            int searchID;
            int keyDatabase = -1;
            bool isEditAbsent;
            bool isIncrease;
            double input;
            int days;
            
            clearScreen();
            cout << "Which student do you want to change the attendance re?" << endl;
            cout << "Type the student's ID number: ";
            searchID = inputStudentID();

            // Input Error
            if (searchID == -1) {
                return;
            }

            // Search for Student in Database
            for (int i = 0; i < attendance.size(); i++) {
                if (attendance[i].getStudentID() == searchID) {
                    keyDatabase = i;
                }
            }

            // Student Not Found
            if (keyDatabase == -1) {
                cout << "\nID does not match any student in the database." << endl;
                continueToNext();
                return;
            }

            cout << "\nEntry found! Attendance records of student:" << attendance[keyDatabase].getStudentID() << endl;
            cout << "Absents: " << attendance[keyDatabase].getAbsents() << endl;
            cout << "Lates: " << attendance[keyDatabase].getLates() << endl;

            // Edit the attendance
            cout << "\nWill you edit the number of absent days or late days?" << endl;
            cout << "[1] Absent Days" << endl;
            cout << "[2] Late Days" << endl;
            cout << "Type your choice: ";

            switch (inputMenu(2)) {
                case -1:
                    return;

                case 1:
                    isEditAbsent = true;
                    break;

                case 2:
                    isEditAbsent = false;
                    break;
            }

            cout << "\nIncrease or Decrease?" << endl;
            cout << "[1] Increase" << endl;
            cout << "[2] Decrease" << endl;
            cout << "Type your choice: ";

            switch (inputMenu(2)) {
                case -1:
                    return;

                case 1:
                    isIncrease = true;
                    break;

                case 2:
                    isIncrease = false;
                    break;
            }

            cout << (isIncrease ? "\nAdd " : "\nSubtract ") << (isEditAbsent ? "absent days " : "late days ") << "by: ";
            
            if (!inputIntNum(&days)) {
                return;
            }

            if (isEditAbsent && isIncrease) {
                attendance[keyDatabase].setAbsents(attendance[keyDatabase].getAbsents() + days);
            } else if (isEditAbsent && !isIncrease) {
                attendance[keyDatabase].setAbsents(attendance[keyDatabase].getAbsents() - days);
            } else if (!isEditAbsent && isIncrease) {
                attendance[keyDatabase].setLates(attendance[keyDatabase].getLates() + days);
            } else {
                attendance[keyDatabase].setLates(attendance[keyDatabase].getLates() - days);
            }

            db->saveData("MA2_Attendance-DB - Sheet1.csv", 6);

            cout << "\nSuccessfully saved the changes to the student's grades." << endl;
            cout << "\nNew attendance records of student " << attendance[keyDatabase].getStudentID() << endl;
            cout << "Absents: " << attendance[keyDatabase].getAbsents() << endl;
            cout << "Lates: " << attendance[keyDatabase].getLates() << endl << endl;
            continueToNext();
        }

        void updateStudentPerformance() {
            int choice;
            bool loopMenu = true;

            // Student Perf Sub Menu
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
                        updateGrades();
                        break;
                    case 2:
                        updateAttendance();
                        break;
                    case 3:
                        return;
                }
            }
        }

        void createDisciplinaryRecord() {
            Database* db = Database::getInstance();
            vector<StudentEntry>& information = db->getStudentEntries();
            vector<Record>& records = db->getRecords();

            int searchID;
            int severity;
            string offense;
            string date;
            
            clearScreen();
            cout << "Which student committed the offense?" << endl;
            cout << "Type the student's ID number: ";
            searchID = inputStudentID();

            // Input Error
            if (searchID == -1) {
                return;
            }

            for (auto& student : information) {
                if (searchID == student.getStudentID()) {
                    cout << "\nStudent Found!" << endl;
                    cout << "\nWhat is the offense?" << endl;
                    cout << "Type the student's offense here: ";
                    cin.ignore();
                    getline(cin, offense);
                    while (true) {
                        cout << "\nWhat is the severity of the offense?" << endl;
                        cout << "Type the severity here [1 - 4]: ";
                        severity = inputMenu(4);
                        if (severity != -1) {
                            break;
                        }
                    }

                    cout << "\nWhat is the date of officially recording this offense?" << endl;
                    cout << "Type date here [MM/DD/YYYY]: ";
                    cin >> date;

                    records.push_back(Record(searchID, offense, severity, date));

                    
                    db->saveData("MA2_Records-DB - Sheet1.csv", 2);

                    cout << "\nSuccessfully saved the changes to the student's grades." << endl;
                    continueToNext();
                    return;
                }
            }

            cout << "\nStudent ID does not exist in the database." << endl;
            continueToNext();
            return;            
        }

        void displayStudentList() {
            vector<StudentEntry>& students = Database::getInstance()->getStudentEntries();
            const int WIDTH = 25;

            cout << "Displaying student entries under your assigned section" << endl;

            cout << "Student ID" << setw(WIDTH) << "Section" << setw(WIDTH) << "Name" << setw(WIDTH) << "Department" << endl;
            
            for (auto& student : students) {
                if (assignedSection == student.getSection()) {
                    cout << student.getStudentID() << setw(WIDTH) 
                    << student.getSection() << setw(WIDTH) 
                    << student.getName() << setw(WIDTH) 
                    << student.getDepartment() << endl;
                }
            }

            cout << endl;
            continueToNext();
            return;
        }
};