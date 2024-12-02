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
            // string section, name, contact, address, emailAddress, department, tuitionDeadline;
            // int id, age, tuition;
            // cout << "Enter Student ID: ";
            // cin >> id;
            // cin.ignore();
            // cout << "Enter Student Section: ";
            // getline(cin, section);
            // cout << "Enter Student Age: ";
            // cin >> age;
            // cin.ignore();
            // cout << "Enter Student Contact Info: ";
            // getline(cin, contact);
            // cout << "Enter Student Name: ";
            // getline(cin, name);
            // cout << "Enter Student Address: ";
            // getline(cin, address);
            // cout << "Enter Student Email: ";
            // getline(cin, emailAddress);
            // cout << "Enter Student Department: ";
            // getline(cin, department);
            // cout << "Enter Tuition Amount: ";
            // cin >> tuition;
            // cin.ignore();
            // cout << "Enter Deadline Of Tuition: ";
            // getline(cin, tuitionDeadline);
            Database* db = Database::getInstance();
            db->getStudentEntries().push_back(
                StudentEntry(0,"section","name",0,"contact","address","emailAddress","department"));
            // Database::getInstance()->getStudentEntries().push_back(StudentEntry(id,section,name,age,contact,address,emailAddress,department));
            // Database::getInstance()->getAttendance().push_back(Attendance(id, 0, 0));
            // Database::getInstance()->getFinancialCommitments().push_back(FinancialCommitment(id, tuition, 0, 0, tuitionDeadline));
            // Database::getInstance()->getGrades().push_back(Grade(id, 0, 0, 0, 0, 0, 0, 0, 0));
            // Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            // Database::getInstance()->saveData("MA2_Attendance-DB - Sheet1.csv", 6);
            // Database::getInstance()->saveData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);
            // Database::getInstance()->saveData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);
            continueToNext();

        }
        
        void createDisciplinaryRecord() {
            clearScreen();
            int studentID, severity;
            string offence, date;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cin.ignore();
            cout << "Enter Offence: ";
            getline(cin, offence);
            cout << "Enter Severity: ";
            cin >> severity;
            cin.ignore();
            cout << "Enter Date: ";
            getline(cin, date); 

            Database::getInstance()->getRecords().push_back(Record(studentID, offence, severity, date));
            Database::getInstance()->saveData("MA2_Records-DB - Sheet1.csv", 2);
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

        void analytics() {}
        
        void updateDisciplinaryRecords() {
            clearScreen();
            int updateIndex = -1;
            cout << "Which disciplinary record do you want to update?" << endl;
            cout << "Type the student's ID number: ";
            int searchID;
            cin >> searchID;
            for (int i = 0; i < Database::getInstance()->getRecords().size(); i++) {
                Record record = Database::getInstance()->getRecords()[i];
                if (searchID == record.getStudentID()) {
                    updateIndex = i;
                }
            }
            if (updateIndex == -1) {
                cout << "Disciplinary Record Not Found In Database!" << endl;
                continueToNext();
                return;
            }

            int studentID, severity;
            string offence, date;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cin.ignore();
            cout << "Enter Offence: ";
            getline(cin, offence);
            cout << "Enter Severity: ";
            cin >> severity;
            cin.ignore();
            cout << "Enter Date: ";
            getline(cin, date);

            Record* record = &Database::getInstance()->getRecords()[updateIndex];
            record->setStudentID(studentID);
            record->setOffence(offence);
            record->setSeverity(severity);
            record->setDate(date);
            Database::getInstance()->saveData("MA2_Records-DB - Sheet1.csv", 2);
            cout << "Disciplinary Record Updated Successfully!" << endl;
            continueToNext();
        }

        void updateGrades() {
            Database* db = Database::getInstance();
            vector<Grade>& grades = db->getGrades();

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

            // Input Which Grade To Update

            while (true) {
                cout << "Select a subject to update the grade:" << endl;
                cout << "[1] English" << endl;
                cout << "[2] Science" << endl;
                cout << "[3] Mathematics" << endl;
                cout << "[4] Filipino" << endl;
                cout << "[5] Social Studies" << endl;
                cout << "[6] CLCE" << endl;
                cout << "[7] TLE" << endl;
                cout << "[8] MAPEH" << endl;
                cout << "Type your choice: ";
                subjectIndex = inputMenu(8);
                if (subjectIndex == -1) continue;
                break;
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
            cout << "Which student do you want to change the attendance?" << endl;
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
        
        void assignFaculty() {}
        
        void updateStudentInfo() {
            clearScreen();
            int updateIndex = -1;
            cout << "Which student entry do you want to update?" << endl;
            cout << "Type the student's ID number: ";
            int searchID;
            cin >> searchID;
            for (int i = 0; i < Database::getInstance()->getStudentEntries().size(); i++) {
                StudentEntry student = Database::getInstance()->getStudentEntries()[i];
                if (searchID == student.getStudentID()) {
                    updateIndex = i;
                }
            }
            if (updateIndex == -1) {
                cout << "Student ID Not Found In Database!" << endl;
                continueToNext();
                return;
            }

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
            cout << "Enter Student Contact Info: ";
            getline(cin, contact);
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Student Address: ";
            getline(cin, address);
            cout << "Enter Student Email: ";
            getline(cin, emailAddress);
            cout << "Enter Student Department: ";
            getline(cin, department);

            StudentEntry entry = Database::getInstance()->getStudentEntries()[updateIndex];
            entry.setStudentID(id);
            entry.setSection(section);
            entry.setAge(age);
            entry.setContact(contact);
            entry.setName(name);
            entry.setAddress(address);
            entry.setEmailAddress(emailAddress);
            entry.setDepartment(department);
            Database::getInstance()->saveData("MA2_Records-DB - Sheet1.csv", 2);
            cout << "Student Entry Updated Successfully!" << endl;
            continueToNext();
        }
        
        void deleteStudentEntry() {
            clearScreen();
            int deleteIndex = -1;
            cout << "Which student entry do you want to delete?" << endl;
            cout << "Type the student's ID number: ";
            int searchID;
            cin >> searchID;
            for (int i = 0; i < Database::getInstance()->getStudentEntries().size(); i++) {
                StudentEntry student = Database::getInstance()->getStudentEntries()[i];
                if (searchID == student.getStudentID()) {
                    deleteIndex = i;
                }
            }
            if (deleteIndex == -1) {
                cout << "Student ID Not Found In Database!" << endl;
                continueToNext();
                return;
            }
            cout << "Student ID Has Been Removed From The Database!" << endl;
            Database::getInstance()->getStudentEntries().erase(Database::getInstance()->getStudentEntries().begin() + deleteIndex);
            Database::getInstance()->getAttendance().erase(Database::getInstance()->getAttendance().begin() + deleteIndex);
            Database::getInstance()->getFinancialCommitments().erase(Database::getInstance()->getFinancialCommitments().begin() + deleteIndex);
            Database::getInstance()->getGrades().erase(Database::getInstance()->getGrades().begin() + deleteIndex);
            Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            Database::getInstance()->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            continueToNext();
        }

        void removeDisciplinaryRecord() {
            clearScreen();
            int deleteIndex = -1;
            cout << "Which disciplinary record do you want to delete?" << endl;
            cout << "Type the student's ID number: ";
            int searchID;
            cin >> searchID;
            for (int i = 0; i < Database::getInstance()->getRecords().size(); i++) {
                Record record = Database::getInstance()->getRecords()[i];
                if (searchID == record.getStudentID()) {
                    deleteIndex = i;
                }
            }
            if (deleteIndex == -1) {
                cout << "Disciplinary Record Not Found In Database!" << endl;
                continueToNext();
                return;
            }
            cout << "Disciplinary Record Has Been Removed From The Database!" << endl;
            Database::getInstance()->getRecords().erase(Database::getInstance()->getRecords().begin() + deleteIndex);
            Database::getInstance()->saveData("MA2_Records-DB - Sheet1.csv", 2);
            continueToNext();
        }
        
        void displayStudents() {
            vector<StudentEntry>& students = Database::getInstance()->getStudentEntries();
            const int WIDTH = 25;

            cout << "Displaying student entries under your assigned section" << endl;

            cout << "Student ID" << setw(WIDTH) << "Section" << setw(WIDTH) << "Name" << setw(WIDTH) << "Department" << endl;
            
            for (auto& student : students) {
                cout << student.getStudentID() << setw(WIDTH) 
                << student.getSection() << setw(WIDTH) 
                << student.getName() << setw(WIDTH) 
                << student.getDepartment() << endl;
            }

            cout << endl;
            continueToNext();
            return;
        }

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
                    << "[11] Display Students" << endl
                    << "[12] Log - Out" << endl;

                choice = inputMenu(12);

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
                    case 12:
                        // logout();
                        return;
                }
            }
        }

};