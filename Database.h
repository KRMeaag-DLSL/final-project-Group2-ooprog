#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class StudentEntry {
    private:
        unsigned long long studentID;
        string name;
        int age;
        string contact;
        string address;
        string emailAddress;
        string department;
    public:
        StudentEntry(unsigned long long id, string name, int age, string contact, string address, string emailAddress, string department) :
         studentID(id), name(name), age(age), contact(contact), address(address), emailAddress(emailAddress), department(department) {}

        unsigned long long getStudentID() { return studentID;}
        void setStudentID(unsigned long long id) {studentID = id;}
        string getName() const { return name;}
        void setName(string n) { name = n;}
        int getAge() { return age;}
        void setAge(int a) { age = a;}
        string getContact() { return contact;}
        void setContact(string c) { contact = c;}
        string getAddress() { return address;}
        void setAddress(int a) { address = a;}
        string getEmailAddress() { return emailAddress;}
        void setEmailAddress(string ea) { emailAddress = ea;}
        string getDepartment() { return department;}
        void setDepartment(string d) { department = d;}
};

class Record {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
};

class Deadline {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
};

class Grade {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
};

class Attendance {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
};

class FinancialCommitment {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
};

class Database {
    private:
        static Database* instance;
        vector<StudentEntry> studentEntries;
        vector<Record> records;
        vector<Grade> grades;
        vector<Deadline> deadlines;
        vector<Attendance> attendance;
        vector<FinancialCommitment> financialCommitments;

        Database () { loadData();}
    
    public:
        static Database* getInstance() {
            return ((instance == nullptr) ? new Database() : instance);
        }

        void searchEntry(string studentID) {}
        vector<StudentEntry>& getStudentEntries() { return studentEntries;}
        vector<Record>& getRecords() { return records;}
        vector<Grade>& getGrades() { return grades;}
        vector<Deadline>& getDeadlines() { return deadlines;}
        vector<Attendance>& getAttendance() { return attendance;}
        vector<FinancialCommitment>& getFinancialCommitments() { return financialCommitments;}

        void getRowFromFile(ifstream& fin, vector<string>& row, string line, string word) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            // Debug: Check the parsed row
            cout << "Parsed row: ";
            for (const auto& col : row) {
                cout << "[" << col << "] ";
            }
            cout << endl;
        }

        void loadData() {
            ifstream fin("MA2_Student-Entry-DB.csv", ios::in);

            if (!fin.is_open()) {
                cerr << "Error: Unable to open file!" << endl;
                return;
            }

            vector<string> row;
            string line, word;

            // Skip the header
            getline(fin, line);

            while (getline(fin, line)) {
                getRowFromFile(fin, row, line, word);

                // Convert age to integer
                int id = stoul(row[0]);
                int age = stoi(row[2]);

                // Add entry to the vector
                studentEntries.push_back(StudentEntry(id, row[1], age, row[3], row[4], row[5], row[6]));
            }
            fin.close();

            cout << "Total student entries loaded: " << studentEntries.size() << endl;
        }
};