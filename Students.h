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

    public:
        Student(string studentID) : studentID(studentID) {}
    
    string getStudentID(){
        return studentID;
    }

    void setStudentID(){
        this->studentID = studentID;
    }

    void menu() override {
    int choice;
            bool loopMenu = true;

            // Main Menu
            while (loopMenu) {
                clearScreen();
                cout << "Good day, " << studentID << "! Please pick from the following:" << endl;

                cout << "[1] Display Student Grades" << endl;
                cout << "[2] Display Student Deadlines" << endl;
                cout << "[3] Display Student Attendance" << endl;
                cout << "[4] Display Payment History" << endl;
                cout << "[5] Display Student Information" << endl;
                cout << "[6] Edit Student Information" << endl;
                cout << "[7] Log-out" << endl;


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
                        return;
                        break;
                }
            }
    }

    void displayStudentGrades(){
        Database* db = Database::getInstance();
        auto& grades = db->getGrades();

        cout << "Grades for Student ID: " << studentID << endl;
        for (auto& grade : grades) {
            if (to_string(grade.getStudentID()) == studentID) {
                cout << "English: " << grade.getEnglish() << endl;
                cout << "Mathematics: " << grade.getMath() << endl;
                cout << "Science: " << grade.getScience() << endl;
                cout << "Filipino: " << grade.getFilipino() << endl;
                cout << "Social Studies: " << grade.getSocStud() << endl;
                cout << "TLE: " << grade.getTLE() << endl;
                cout << "CLCE: " << grade.getCLCE() << endl;
                cout << "MAPEH: " << grade.getMAPEH() << endl;
                return;
            }

    }
            cout << "No grades found for Student ID " << studentID << ".\n";
    }

    void displayStudentDeadlines(){
        Database* db = Database::getInstance();
         auto& deadline = db->getDeadlines();

        cout << "Deadlines for Student ID " << studentID << ":\n";
       
        for (auto& deadline : db->getDeadlines()) {
            if (to_string(deadline.getStudentID()) == studentID) {
                cout << "Name: " << deadline.getName() << "\n";
                cout << "Days until the Deadline: " << deadline.getDaysUntilDeadlines() << "\n";
                cout << "Deadline Date: " << deadline.getDeadlineDate() << "\n";
                cout << "Subject: " << deadline.getSubject() << "\n";
                cout << "-------------------------\n";
                return;
            }
        }
        
            cout << "No deadlines found for Student ID " << studentID << ".\n";
     
    }

    void displayStudentAttendance(){
      Database* db = Database::getInstance();
      auto& attendances = db->getAttendance();

        cout << "Attendance for Student ID " << studentID << ":\n";

        for (auto& attendance : attendances) {
            if (to_string(attendance.getStudentID()) == studentID) {
             cout << "Absents: " << attendance.getAbsents() << "\n";
             cout << "Lates: " << attendance.getLates() << "\n";
             cout << "--------------------------------------\n";
            return;
        }
    }
   
        cout << "No attendance records found for Student ID " << studentID << ".\n";
    }

    void displayPaymentHistory(){
         Database* db = Database::getInstance();
         auto& financialCommitments = db->getFinancialCommitments();
    cout << "Payment History for Student ID " << studentID << ":\n";
    
    for (auto& commitment : financialCommitments) {
        if (to_string(commitment.getStudentID()) == studentID) {
            cout << "Total Tuition Fee: " << commitment.getTotalTuitionFee() << "\n";
            cout << "Additional Fees: " << commitment.getAdditionalFees() << "\n";
            cout << "Paid Amount: " << commitment.getPaidAmount() << "\n";
            cout << "Payment Deadline: " << commitment.getPaymentDeadline() << "\n";
            cout << "-----------------------------------------------------------\n";
            return; 
        }
    }
    cout << "No payment history found for Student ID " << studentID << ".\n";
    }

    void displayStudentInformation(){
         Database* db = Database::getInstance();
         auto& studentEntries = db->getStudentEntries();

    cout << "Student Information for Student ID " << studentID << ":\n";
    
    for (auto& student : studentEntries) {
        if (to_string(student.getStudentID()) == studentID) {
            cout << "Name: " << student.getName() << "\n";
            cout << "Section: " << student.getSection() << "\n";
            cout << "Age: " << student.getAge() << "\n";
            cout << "Contact Number: " << student.getContact() << "\n";
            cout << "Address: " << student.getAddress() << "\n";
            cout << "Email Address: " << student.getEmailAddress() << "\n";
            cout << "--------------------------------------------------\n";
            return; 
        }
    }
    cout << "No student information found for Student ID " << studentID << ".\n";
    }

    void editStudentInformation() {
           Database* db = Database::getInstance();
        auto& studentEntries = db->getStudentEntries();

        for (auto& student : studentEntries) {
            if (to_string(student.getStudentID()) == studentID) {
                string newName, newContact, newAddress, newEmail;
                int newAge;

                cout << "Editing Student Information for Student ID " << studentID << ":\n";

                 cout << "Enter new contact number (format: 123-456-7890, leave blank to keep current): ";
                 getline(cin, newContact);
                if (!newContact.empty()) {
                if (newContact.length() == 12 &&
                    newContact[3] == '-' &&
                    newContact[7] == '-' &&
                    checkStrDigit(newContact.substr(0, 3)) &&
                    checkStrDigit(newContact.substr(4, 3)) &&
                    checkStrDigit(newContact.substr(8, 4))) {
                    student.setContact(newContact);
                } else {
                    cout << "Invalid contact number format. Keeping the current one.\n";
                }
            }

                cout << "Enter new address (leave blank to keep current): ";
                getline(cin, newAddress);
                if (!newAddress.empty()) {
                    student.setAddress(newAddress);
                }

                cout << "Information successfully updated.\n";
                return;
            }
        }
        cout << "Student ID not found.\n";
    }
};

