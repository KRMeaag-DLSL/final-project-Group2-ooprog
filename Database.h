#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class StudentEntry {
    private:
        string studentID;
        string name;
        int age;
        int contact;
        string address;
        string emailAddress;
        string department;
    public:
        StudentEntry(string id, string name, int age, int contact, string address, string emailAddress, string department) :
         studentID(id), name(name), age(age), contact(contact), address(address), emailAddress(emailAddress), department(department) {}

        string getStudentID() { return studentID;}
        void setStudentID(string id) {studentID = id;}
        string getName() { return name;}
        void setName(string n) { name = n;}
        int getAge() { return age;}
        void setAge(int a) { age = a;}
        int getContact() { return contact;}
        void setContact(int c) { contact = c;}
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
        vector<StudentEntry*> studentEntries;
        vector<Record> records;
        vector<Grade> grades;
        vector<Deadline> deadlines;
        vector<Attendance> attendance;
        vector<FinancialCommitment> financialCommitments;

        Database () {}
    
    public:
        static Database* getInstance() {
            return ((instance == nullptr) ? new Database() : instance);
        }

        void searchEntry(string studentID) {}
        vector<StudentEntry*>& getStudentEntries() { return studentEntries;}
        vector<Record> getRecords() { return records;}
        vector<Grade> getGrades() { return grades;}
        vector<Deadline> getDeadlines() { return deadlines;}
        vector<Attendance> getAttendance() { return attendance;}
        vector<FinancialCommitment> getFinancialCommitments() { return financialCommitments;}

        void loadData() {
            ifstream fin;
            fin.open("MA2_Student-Entry-DB.csv", ios::in);

            vector<string> row;
            string line, word, temp;

            while(!fin.eof()) {
                row.clear();

                // read an entire row and
                // store it in a string variable 'line'
                getline(fin, line);

                if (line.rfind("Student-ID", 0) == 0) continue;

                // used for breaking words
                stringstream s(line);

                // read every column data of a row and
                // store it in a string variable, 'word'
                while (getline(s, word, ','))
                {
                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }

                stringstream strm(row[2]);
                stringstream strm2(row[3]);
                int age, contact;
                strm >> age;
                strm2 >> contact;


                //cout << row[0] << " " << row[1] << row[2] << " " << row[3] << row[4] << " " << row[5] << " " << row[6];

                StudentEntry entry(row[0], row[1], age, contact, row[4], row[5], row[6]);
                getStudentEntries().push_back(&entry);
            }
        }
};