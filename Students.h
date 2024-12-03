#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
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
            Database* db = Database::getInstance();
            vector<StudentEntry>& entries = db->getStudentEntries();

            for (auto& entry : entries) {
                if (entry.getStudentID() == stoi(studentIDInput)) {
                    section = entry.getSection();
                }
            }

        }
    
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
                    if(logout())
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
        auto& deadlines = db->getDeadlines();
        bool foundEntry = false;

        cout << "Deadlines under your section " << section << ":\n";
       
        for (auto& deadline : deadlines) {
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
        int balance = 0;
        int paidAmt = 0;
        int index = 0;

        cout << "Payment History for Student ID " << studentID << ":\n";
    
        for (int i = 0; i < financialCommitments.size(); i++) {
            if (to_string(financialCommitments[i].getStudentID()) == studentID) {
                foundEntry = true;
                index = i;
                balance = (financialCommitments[i].getTotalTuitionFee() + financialCommitments[i].getAdditionalFees()) - financialCommitments[i].getPaidAmount();

                cout << "Total Tuition Fee: " << financialCommitments[i].getTotalTuitionFee() << "\n";
                cout << "Additional Fees: " << financialCommitments[i].getAdditionalFees() << "\n";
                cout << "Paid Amount: " << financialCommitments[i].getPaidAmount() << "\n";
                cout << "Payment Deadline: " << financialCommitments[i].getPaymentDeadline() << "\n";
                cout << "-----------------------------------------------------------\n";
            }
        }

        // No Payment History Found
        if(!foundEntry) { 
            cout << "No payment history found for Student ID " << studentID << ".\n";
            continueToNext();
            return;
        }

        // Fully Paid Balance
        if (balance == 0) {
            cout << "\nYou've fully paid your remaining balance." << endl;
            continueToNext();
            return;
        }

        // Remaining Balance
        cout << "\nYour remaining balance is P" << balance << endl;
        cout << "\nDo you want to make a payment? " << endl;
        cout << "[1] Yes" << endl;
        cout << "[2] No" << endl;
        cout << "Type your choice here: ";

        switch(inputMenu(2)) {
            case -1: // Error
                return;

            case 2: // Exit Balance Menu
                cout << "\nNo payments made, returning to main menu." << endl;
                continueToNext();
                return;
        }

        // User wants to pay
        cout << "\nAmount to be paid: ";
        if (!inputIntNum(&paidAmt)) {
            return;
        }

        // Errors
        if (paidAmt > balance) {
            cout << "\nError! Amount that'll be paid is higher than the balance, please try again!" << endl;
            continueToNext();
            return;
        } else if (paidAmt == 0) {
            cout << "\nPaid amount is zero. no changes to the database has been made." << endl;
            continueToNext();
            return;
        } else if (paidAmt < 0) {
            cout << "\nError! You paid a negative amount of money. Please try again!" << endl;
            continueToNext();
            return;
        }

        // Update Balance
        if (paidAmt == balance) {
            cout << "\nBalance has been fully paid in full. Thank you!" << endl;
        } else if (paidAmt < balance) {
            cout << "\nAmount has been paid, your remaining balance is: P" << balance - paidAmt << endl;
        }

        int newPaidAmount = financialCommitments[index].getPaidAmount() + paidAmt;

        financialCommitments[index].setPaidAmount(newPaidAmount);

        db->saveData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);

        cout << endl;
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

                cout << "Enter new address(City) (leave blank to keep current): ";
                    getline(cin, newAddress);

                    if (!newAddress.empty()) {
                        student.setAddress(newAddress);
                        cout << "Address updated.\n";
                    } else {
                        cout << "No changes made for the address.\n";
                    }

                db->saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);

                cout << "Information successfully updated.\n";
                 continueToNext();
            }
        }
    }
    };