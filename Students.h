#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Users.h"
#include "Database.h"
#include "Global-Functions.h"

using namespace std;

class Student : public Account {
    private:
    string studentID;
    string section;

    public:
        Student(string studentIDInput) : studentID((studentIDInput)), section("Default") {
            cout << "TEST 1" << endl;
            Database* db = Database::getInstance();

            cout << "TEST 12" << endl;
            vector<StudentEntry>& entries = db->getStudentEntries();

            cout << "TEST 3" << endl;

            for (auto& entry : entries) {
                if (entry.getStudentID() == stoi(studentIDInput)) {
                    section = entry.getSection();
                }
            }

            cout << "TEST 4" << endl;
        }
    
    string getStudentID(){
        return studentID;
    }

    string getSection(){
        return section;
    }

    void setStudentID(){
        this->studentID = studentID;
    }

    void setSection(){
        this->section = section;
    }

    void menu() override {
    int choice;
            bool loopMenu = true;

            // Main Menu
            while (loopMenu) {
                clearScreen();
                cout << "TEST 3" << endl;

                cout << "Good day, " << studentID << ", from section " << section << "! Please pick from the following:" << endl;

                cout << "[1] Display Student Grades" << endl;
                cout << "[2] Display Student Deadlines" << endl;
                cout << "[3] Display Student Attendance" << endl;
                cout << "[4] Display Payment History" << endl;
                cout << "[5] Display Student Information" << endl;
                cout << "[6] Edit Student Information" << endl;
                cout << "[7] Log-out" << endl;

                cout << "Type your choice: ";
                switch (inputMenu(7)) {
                    case -1:
                        continue;
                    case 1:
                        displayStudentGrades();
                        break;
                    case 2:
                        displayStudentDeadlines();
                        break;
                    case 3:
                        displayStudentAttendance();
                        break;
                    case 4:
                        displayPaymentHistory();
                        break;
                    case 5:
                        displayStudentInformation();
                        break;
                    case 6:
                        editStudentInformation();
                        break;
                    case 7:
                        if(logout());
                            return;
                        break;
                }
            }
    }

    void displayStudentGrades(){
        clearScreen();
        Database* db = Database::getInstance();
        auto& grades = db->getGrades();
        bool foundEntry = false;

        cout << "Grades for Student ID: " << studentID << endl;
        for (auto& grade : grades) {
            if (to_string(grade.getStudentID()) == studentID) {
                foundEntry = true;
                cout << "English: " << grade.getEnglish() << endl;
                cout << "Mathematics: " << grade.getMath() << endl;
                cout << "Science: " << grade.getScience() << endl;
                cout << "Filipino: " << grade.getFilipino() << endl;
                cout << "Social Studies: " << grade.getSocStud() << endl;
                cout << "TLE: " << grade.getTLE() << endl;
                cout << "CLCE: " << grade.getCLCE() << endl;
                cout << "MAPEH: " << grade.getMAPEH() << endl;
                cout << "---------------------------------------------\n";
            }

    }
        if(!foundEntry){
            cout << "No grades found for Student ID " << studentID << ".\n";
            continueToNext();
            return;
        }

        continueToNext();
        return;
    }

    void displayStudentDeadlines(){
        clearScreen();
        Database* db = Database::getInstance();
        auto& deadline = db->getDeadlines();
        bool foundEntry = false;

        cout << "Deadlines under your section " << section << ":\n";
       
        for (auto& deadline : db->getDeadlines()) {
            if (deadline.getSection() == section) {
                foundEntry = true;
                cout << "Section: " << deadline.getSection() << "\n";
                cout << "Deadline Date: " << deadline.getDeadlineDate() << "\n";
                cout << "Subject: " << deadline.getSubject() << "\n";
                cout << "----------------------------------------\n";
            }
        }
        
        if (!foundEntry) {
            cout << "No deadlines found for Student ID " << studentID << ".\n";
            continueToNext();
            return;
        }

        continueToNext();
        return;
    }

    void displayStudentAttendance(){
      clearScreen();
      Database* db = Database::getInstance();
      auto& attendances = db->getAttendance();
        bool foundEntry = false;
        cout << "Attendance for Student ID " << studentID << ":\n";

        for (auto& attendance : attendances) {
            if (to_string(attendance.getStudentID()) == studentID) {
             foundEntry = true;
             cout << "Absents: " << attendance.getAbsents() << "\n";
             cout << "Lates: " << attendance.getLates() << "\n";
             cout << "--------------------------------------\n";
        }
    }
   
        if(!foundEntry){
        cout << "No attendance records found for Student ID " << studentID << ".\n";
         continueToNext();
            return;
        }

        continueToNext();
        return;
    }

    void displayPaymentHistory(){
         clearScreen();
         Database* db = Database::getInstance();
         auto& financialCommitments = db->getFinancialCommitments();
         bool foundEntry = false;
    cout << "Payment History for Student ID " << studentID << ":\n";
    
    for (auto& commitment : financialCommitments) {
        if (to_string(commitment.getStudentID()) == studentID) {
            foundEntry = true;
            cout << "Total Tuition Fee: " << commitment.getTotalTuitionFee() << "\n";
            cout << "Additional Fees: " << commitment.getAdditionalFees() << "\n";
            cout << "Paid Amount: " << commitment.getPaidAmount() << "\n";
            cout << "Payment Deadline: " << commitment.getPaymentDeadline() << "\n";
            cout << "-----------------------------------------------------------\n";
            
        }
    }
    
    if(!foundEntry){
    cout << "No payment history found for Student ID " << studentID << ".\n";
     continueToNext();
            return;
        }

        continueToNext();
        return;
    }
    

    void displayStudentInformation(){
         clearScreen();
         Database* db = Database::getInstance();
         auto& studentEntries = db->getStudentEntries();
         bool foundEntry = false;
    cout << "Student Information for Student ID " << studentID << ":\n";
    
    for (auto& student : studentEntries) {
        if (to_string(student.getStudentID()) == studentID) {
            foundEntry = true;
            cout << "Name: " << student.getName() << "\n";
            cout << "Section: " << student.getSection() << "\n";
            cout << "Age: " << student.getAge() << "\n";
            cout << "Contact Number: " << student.getContact() << "\n";
            cout << "Address: " << student.getAddress() << "\n";
            cout << "Email Address: " << student.getEmailAddress() << "\n";
            cout << "--------------------------------------------------\n";
            
        }
    }
    if(!foundEntry){
    cout << "No student information found for Student ID " << studentID << ".\n";
        continueToNext();
        return;
        }

        continueToNext();
        return;
    }

    void editStudentInformation() {
        clearScreen();
           Database* db = Database::getInstance();
        auto& studentEntries = db->getStudentEntries();
        bool foundEntry = false;
        for (auto& student : studentEntries) {
            if (to_string(student.getStudentID()) == studentID) {
                foundEntry = true;
                string newName, newContact, newAddress, newEmail;
                int newAge;

                cout << "Editing Student Information for Student ID " << studentID << ":\n";

                
               cout << "Editing student information for ID: " << studentID << endl;

            
            cout << "Enter new contact number (format XXX-XXX-XXXX) or press ENTER to skip: ";
            cin.ignore(); 
            getline(cin, newContact);

           
            if (newContact.empty()) {
                cout << "No changes made to the contact number." << endl;
            } else {
                
                while (!isValidContact(newContact)) {
                    cout << "Invalid contact format. Please try again using XXX-XXX-XXXX or press ENTER to skip: ";
                    getline(cin, newContact);

                    // Check if user decides to skip during re-prompt
                    if (newContact.empty()) {
                        cout << "No changes made to the contact number." << endl;
                        return;
                    }
                }

                student.setContact(newContact);
                cout << "Contact number updated successfully!" << endl;
            }

                cout << "Enter new address (leave blank to keep current): ";
                getline(cin, newAddress);
                if (!newAddress.empty()) {
                    student.setAddress(newAddress);
                    cout << "Address updated.\n";
                }
                

                db->saveData("MA2_Student-Entry-DB - Sheet1.csv", 5);
                db->saveData("MA2_Student-Entry-DB - Sheet1.csv", 6);

                cout << "Information successfully updated.\n";
                 continueToNext();
            }
        }
    }
    };



