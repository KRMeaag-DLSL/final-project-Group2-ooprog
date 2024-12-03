#pragma once
#include <cstdio>
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
            string section, name, contact, address, emailAddress, department, tuitionDeadline;
            int id = 0, age = 0, tuition = 0;

            while (true) {
                clearScreen();
                cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
                cout << "Enter Student ID: ";
                id = inputStudentID();
                cin.ignore();
                if (id != -1) break;
            }

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Section: ";
            getline(cin, section);

            while (true) {
                clearScreen();
                cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                    << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                    << address << "], [" << emailAddress << "], [" 
                    << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                    << tuitionDeadline << "]\n";
                cout << "Enter Student Age: ";
                bool check = inputIntNum(&age);
                cin.ignore();
                if (check) break;
            }

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Contact Info: ";
            getline(cin, contact);

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Name: ";
            getline(cin, name);

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Address: ";
            getline(cin, address);

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Email: ";
            getline(cin, emailAddress);

            clearScreen();
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n";
            cout << "Enter Student Department: ";
            getline(cin, department);

            while (true) {
                clearScreen();  
                cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                    << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                    << address << "], [" << emailAddress << "], [" 
                    << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                    << tuitionDeadline << "]\n";
                cout << "Enter Tuition Amount: ";
                bool check = inputIntNum(&tuition);
                cin.ignore();
                if (check) break;
            }

            while(true) {
                clearScreen();
                cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                    << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                    << address << "], [" << emailAddress << "], [" 
                    << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                    << tuitionDeadline << "]\n";
                cout << "Enter Deadline Of Tuition (MM-DD-YYYY): ";
                string check = inputDate(false);
                if (check != "INVALID_ERROR!") {
                    tuitionDeadline = check;
                    break;
                }
            }

            clearScreen();
            cout << "Student Entry Successfully Added!\n";
            cout << "[" << ((id == 0 || id == -1) ? " " : to_string(id)) << "], [" << section << "], [" 
                << ((age == 0 || age == -1) ? " " : to_string(age)) << "], [" << contact << "], [" << name << "], [" 
                << address << "], [" << emailAddress << "], [" 
                << department << "], [" << ((tuition == 0 || tuition == -1) ? " " : to_string(tuition)) << "], [" 
                << tuitionDeadline << "]\n\n";

            Database* db = Database::getInstance();
            db->getStudentEntries().push_back(StudentEntry(id,section,name,age,contact,address,emailAddress,department));
            db->getAttendance().push_back(Attendance(id, 0, 0));
            db->getFinancialCommitments().push_back(FinancialCommitment(id, tuition, 0, 0, tuitionDeadline));
            db->getGrades().push_back(Grade(id, 0, 0, 0, 0, 0, 0, 0, 0));
            db->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            db->saveData("MA2_Attendance-DB - Sheet1.csv", 6);
            db->saveData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);
            db->saveData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);
            continueToNext();

        }
        
        void createDisciplinaryRecord() {
            int studentID = 0, severity = 0;
            string offence, date;

            while (true) {
                clearScreen();
                cout << "[" << ((studentID == 0 || studentID == -1) ? " " : to_string(studentID)) << "], [" <<
                    offence << "], [" << ((severity == 0 || severity == -1) ? " " : to_string(severity)) << "], [" <<
                    date << "]\n";
                cout << "Enter Student ID: ";
                studentID = inputStudentID();
                cin.ignore();
                if (studentID != -1) break;
            }

            clearScreen();
            cout << "[" << ((studentID == 0 || studentID == -1) ? " " : to_string(studentID)) << "], [" <<
                offence << "], [" << ((severity == 0 || severity == -1) ? " " : to_string(severity)) << "], [" <<
                date << "]\n";
            cout << "Enter Offence: ";
            getline(cin, offence);

            while (true) {
                clearScreen();
                cout << "[" << ((studentID == 0 || studentID == -1) ? " " : to_string(studentID)) << "], [" <<
                    offence << "], [" << ((severity == 0 || severity == -1) ? " " : to_string(severity)) << "], [" <<
                    date << "]\n";
                cout << "Enter Severity (1-3): ";
                bool check = inputIntNum(&severity);
                if (severity > 3 || severity < 1) {
                    cout << "\nSeverity must be between 1 and 3.\n";
                    severity = 0;
                    continueToNext();
                    continue;
                }
                else if (check) break;
            }
            
            while (true) {
                clearScreen();
                cout << "[" << ((studentID == 0 || studentID == -1) ? " " : to_string(studentID)) << "], [" <<
                    offence << "], [" << ((severity == 0 || severity == -1) ? " " : to_string(severity)) << "], [" <<
                    date << "]\n";
                cout << "Enter Date: ";
                string check = inputDate(false);
                if (check != "INVALID_ERROR!") {
                    date = check;
                    break;
                }
            }

            clearScreen();
            cout << "Disciplinary Record Successfully Added!\n";
            cout << "[" << ((studentID == 0 || studentID == -1) ? " " : to_string(studentID)) << "], [" <<
                offence << "], [" << ((severity == 0 || severity == -1) ? " " : to_string(severity)) << "], [" <<
                date << "]\n\n";

            Database::getInstance()->getRecords().push_back(Record(studentID, offence, severity, date));
            Database::getInstance()->saveData("MA2_Records-DB - Sheet1.csv", 2);

            continueToNext();
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
            Database* db = Database::getInstance();
            int updateIndex = -1;
            int searchID;
            while (true) {
                clearScreen();
                cout << "Which disciplinary record do you want to update?" << endl;
                cout << "Type the student's ID number: ";
                searchID = inputStudentID();
                if (searchID != -1) break;
            }

            for (int i = 0; i < db->getRecords().size(); i++) {
                Record record = db->getRecords()[i];
                if (searchID == record.getStudentID()) {
                    updateIndex = i;
                }
            }
            if (updateIndex == -1) {
                cout << "Disciplinary Record Not Found In Database!" << endl;
                continueToNext();
                return;
            }
            bool loopMenu = true;
            while (loopMenu) {
                clearScreen();
                cout << "Select from the following to edit:" << endl;
                cout << "[1] Offence" << endl;
                cout << "[2] Severity" << endl;
                cout << "[3] Date" << endl;
                cout << "[4] Cancel Editing Disciplinary Record" << endl;
                
                switch(inputMenu(4)) {
                    case 1: {
                        clearScreen();
                        string offence;
                        cin.ignore();
                        cout << "Enter The New Offence: ";
                        getline(cin, offence);
                        db->getRecords()[updateIndex].setOffence(offence);
                        loopMenu = false;
                        break;
                    }
                    case 2: {
                        while (true) {
                            clearScreen();
                            int severity;
                            cin.ignore();
                            cout << "Enter The New Severity (1-3): ";
                            bool check = inputIntNum(&severity);
                            db->getRecords()[updateIndex].setSeverity(severity);
                            if (severity > 3 || severity < 1) {
                                cout << "\nSeverity must be between 1 and 3.\n";
                                severity = 0;
                                continueToNext();
                                continue;
                            }
                            else if (check) break;
                        }
                        loopMenu = false;
                        break;
                    }
                    case 3: {
                        while (true) {
                            clearScreen();
                            string date;
                            cin.ignore();
                            cout << "Enter The New Date (MM-DD-YYYY): ";
                            string check = inputDate(false);
                            if (check != "INVALID_ERROR!") {
                                date = check;
                                db->getRecords()[updateIndex].setDate(date);
                                break;
                            }
                        }
                        loopMenu = false;
                        break;
                    }
                    case -1: case 4:
                        loopMenu = false;
                        break;
                }
            }
            
            db->saveData("MA2_Records-DB - Sheet1.csv", 2);
            clearScreen();
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
        
        bool updateSection(TeacherInfo* info) {
            string sections[] = {
                "BM105",
                "BM202",
                "CMR204",
                "CMR207"
            };
            while(true) {
                clearScreen();
                cout << "Choose A Section:\n";
                for (int i = 0; i < 4; ++i) {
                    cout << "[" << (i + 1) << "] " << sections[i] << "\n";
                }
                cout << "[5] Go Back\n";

                int choice = inputMenu(5);

                if (choice == 5) return false;
                else if (choice == -1) continue;

                info->setSection(sections[choice-1]);
                return true;
            }
        }
        
        bool updateSubject(TeacherInfo* info) {
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
            int choice;

            while (true) {
                clearScreen();
                cout << "Choose A Subject:\n";
                for (int i = 0; i < 8; ++i) {
                    cout << "[" << (i + 1) << "] " << subjects[i] << "\n";
                }
                cout << "[9] Go Back\n";

                choice = inputMenu(9);

                if (choice == 9) return false;
                else if (choice == -1) continue;

                info->setSubject(subjects[choice-1]);
                return true;
            }
        }

        void assignFaculty() {
            string facultyID;
            TeacherInfo* teacherInfo;
            bool checkID = false;
            Database* db = Database::getInstance();

            while (true) {
                clearScreen();
                cout << "What is the faculty ID of the faculty you want to assign?" << endl;
                getline(cin, facultyID);

                for (TeacherInfo& info : db->getTeacherInfo()) {
                    if (info.getFacultyID() == facultyID) {
                        teacherInfo = &info;
                        checkID = true;
                    }
                }

                if (!checkID) {
                    cout << "\nFaculty ID not found." << endl;
                    continueToNext();
                    return;
                }

                while(true) {
                    clearScreen();
                    cout << "Do you want to change the assigned subject or the assigned section?" << endl;
                    cout << "[1] Subject" << endl;
                    cout << "[2] Section" << endl;
                    cout << "[3] Cancel editing" << endl;
                    cout << "Type your choice here: ";

                    switch(inputMenu(3)) {
                        case -1:
                            continue;
                        case 1:
                            if (!updateSubject(teacherInfo)) continue;
                            break;
                        case 2:
                            if (!updateSection(teacherInfo)) continue;
                            break;
                        case 3:
                            return;
                    }

                    db->saveData("MA2_Teacher-Subject-DB - Sheet1.csv", 7);
                    cout << "Update Successful!" << endl;
                    cout << left << setw(15) << "Faculty-ID" <<
                            left << setw(15) << "Section" <<
                            left << setw(15) << "Subject" << endl;
                    cout << left << setw(15) << facultyID <<
                            left << setw(15) << teacherInfo->getSection() << 
                            left << setw(15) << teacherInfo->getSubject() << endl << endl;
                    continueToNext();
                }

            }
                      
        }
        
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
            Database* db = Database::getInstance();
            db->getStudentEntries().erase(Database::getInstance()->getStudentEntries().begin() + deleteIndex);
            db->getAttendance().erase(Database::getInstance()->getAttendance().begin() + deleteIndex);
            db->getFinancialCommitments().erase(Database::getInstance()->getFinancialCommitments().begin() + deleteIndex);
            db->getGrades().erase(Database::getInstance()->getGrades().begin() + deleteIndex);
            db->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            db->saveData("MA2_Attendance-DB - Sheet1.csv", 6);
            db->saveData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);
            db->saveData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);
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
                cin.ignore();

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
                        if (logout()) return;
                        break;
                }
            }
        }

};