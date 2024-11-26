#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class StudentEntry {
    private:
        string studentID;
    public:
        string getStudentID() { return studentID;}
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

        Database () {}
    
    public:
        static Database* getInstance() {
            return ((instance == nullptr) ? new Database() : instance);
        }

        void searchEntry(string studentID) {}
        vector<StudentEntry> getStudentEntries() { return studentEntries;}
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
            }
        }
};