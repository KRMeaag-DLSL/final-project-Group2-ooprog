#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Database.h"
#include "Students.h"
#include "Users.h"
#include "SortStrategy.h"

using namespace std;

Attendance getAttendanceFromID(int id, Database* db) {
    for (Attendance attendance : db->getAttendance()) {
        if (attendance.getStudentID() == id) return attendance;
    }
    return Attendance();
}

Database* Database::instance = nullptr;

Grade getGradeFromID(int id, Database* db) {
    for (Grade grade : db->getGrades()) {
        if (grade.getStudentID() == id) return grade;
    }
    return Grade();
}

StudentEntry getInfoFromID(int id, Database* db) {
    for (StudentEntry entry : db->getStudentEntries()) {
        if (entry.getStudentID() == id) return entry;
    }
    return StudentEntry();
}

void testAttendanceSort() {
    Database* db = Database::getInstance();
    vector<int> data;
    for(auto& attendance : db->getAttendance()) {
        data.push_back(attendance.getStudentID());
    }
    cout << "\nBEFORE SORT:\n";
    cout << left << setw(20) << "STUDENT ID" <<
        left << setw(20) << "ABSENTS" <<
        left << setw(20) << "LATES" << endl;
    for (int i : data) {
        Attendance attendance = getAttendanceFromID(i, db);
        cout << left << setw(20) << attendance.getStudentID() <<
        left << setw(20) << attendance.getAbsents() <<
        left << setw(20) << attendance.getLates() << endl;
    }
    SortContext context(new AttendanceSort());
    context.sortData(data);

    cout << "AFTER SORT:\n";
    cout << left << setw(20) << "STUDENT ID" <<
        left << setw(20) << "ABSENTS" <<
        left << setw(20) << "LATES" << endl;;
    for (int i : data) {
        Attendance attendance = getAttendanceFromID(i, db);
        cout << left << setw(20) << attendance.getStudentID() <<
        left << setw(20) << attendance.getAbsents() <<
        left << setw(20) << attendance.getLates() << endl;
    }
}

void testGradesSort() {
    Database* db = Database::getInstance();
    vector<int> data;
    for(auto& attendance : db->getAttendance()) {
        data.push_back(attendance.getStudentID());
    }
    cout << "\nBEFORE SORT:\n";
    cout << left << setw(10) << "ENGLISH" 
         << left << setw(10) << "MATH" 
         << left << setw(10) << "SCIENCE" 
         << left << setw(10) << "SOC STUD"
         << left << setw(10) << "FILIPINO" 
         << left << setw(10) << "TLE" 
         << left << setw(10) << "CLCE" 
         << left << setw(10) << "MAPEH" << endl;
    for (int i : data) {
        Grade grade = getGradeFromID(i, db);
        cout << left << setw(10) << grade.getEnglish()
            << left << setw(10) << grade.getMath()
            << left << setw(10) << grade.getScience()
            << left << setw(10) << grade.getSocStud()
            << left << setw(10) << grade.getFilipino()
            << left << setw(10) << grade.getTLE()
            << left << setw(10) << grade.getCLCE()
            << left << setw(10) << grade.getMAPEH()
            << left << setw(10) << (grade.getEnglish() + 
                            grade.getMath() + 
                            grade.getScience() + 
                            grade.getSocStud() + 
                            grade.getFilipino() + 
                            grade.getTLE() + 
                            grade.getCLCE() + 
                            grade.getMAPEH())/8 << endl;
    }
    SortContext context(new GradesSort());
    context.sortData(data);

    cout << "\nAFTER SORT:\n";
    cout << left << setw(10) << "ENGLISH" 
         << left << setw(10) << "MATH" 
         << left << setw(10) << "SCIENCE" 
         << left << setw(10) << "SOC STUD"
         << left << setw(10) << "FILIPINO" 
         << left << setw(10) << "TLE" 
         << left << setw(10) << "CLCE" 
         << left << setw(10) << "MAPEH" << endl;
    for (int i : data) {
        Grade grade = getGradeFromID(i, db);
        cout << left << setw(10) << grade.getEnglish()
            << left << setw(10) << grade.getMath()
            << left << setw(10) << grade.getScience()
            << left << setw(10) << grade.getSocStud()
            << left << setw(10) << grade.getFilipino()
            << left << setw(10) << grade.getTLE()
            << left << setw(10) << grade.getCLCE()
            << left << setw(10) << grade.getMAPEH()
            << left << setw(10) << (grade.getEnglish() + 
                            grade.getMath() + 
                            grade.getScience() + 
                            grade.getSocStud() + 
                            grade.getFilipino() + 
                            grade.getTLE() + 
                            grade.getCLCE() + 
                            grade.getMAPEH())/8 << endl;
    }
}

void testIDSort() {
    Database* db = Database::getInstance();
    const int WIDTH = 25;
    vector<int> data;
    for(auto& entries : db->getStudentEntries()) {
        data.push_back(entries.getStudentID());
    }
    cout << "\nBEFORE SORT:\n";
    cout << left << setw(WIDTH) << "ID" 
         << left << setw(WIDTH) << "Section" 
         << left << setw(WIDTH) << "Name" 
         << left << setw(WIDTH) << "Age"
         << left << setw(WIDTH) << "Contact" 
         << left << setw(WIDTH) << "Address" 
         << left << setw(WIDTH) << "Email Address" 
         << left << setw(WIDTH) << "Department" << endl;
    for (int i : data) {
        StudentEntry entry = getInfoFromID(i, db);
        cout << left << setw(WIDTH) << entry.getStudentID()
         << left << setw(WIDTH) << entry.getSection()
         << left << setw(WIDTH) << entry.getName()
         << left << setw(WIDTH) << entry.getAge()
         << left << setw(WIDTH) << entry.getContact()
         << left << setw(WIDTH) << entry.getAddress()
         << left << setw(WIDTH) << entry.getEmailAddress()
         << left << setw(WIDTH) << entry.getDepartment() << endl;
    }
    SortContext context(new IDSort());
    context.sortData(data);

    cout << "AFTER SORT:\n";
    cout << left << setw(WIDTH) << "ID" 
         << left << setw(WIDTH) << "Section" 
         << left << setw(WIDTH) << "Name" 
         << left << setw(WIDTH) << "Age"
         << left << setw(WIDTH) << "Contact" 
         << left << setw(WIDTH) << "Address" 
         << left << setw(WIDTH) << "Email Address" 
         << left << setw(WIDTH) << "Department" << endl;
    for (int i : data) {
        StudentEntry entry = getInfoFromID(i, db);
        cout << left << setw(WIDTH) << entry.getStudentID()
         << left << setw(WIDTH) << entry.getSection()
         << left << setw(WIDTH) << entry.getName()
         << left << setw(WIDTH) << entry.getAge()
         << left << setw(WIDTH) << entry.getContact()
         << left << setw(WIDTH) << entry.getAddress()
         << left << setw(WIDTH) << entry.getEmailAddress()
         << left << setw(WIDTH) << entry.getDepartment() << endl;
    }
}

int main() {
    cout << "Hello";
    testIDSort();
}