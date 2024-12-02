#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Database.h"
#include "Students.h"
#include "Users.h"
#include "SortStrategy.h"
#include <iomanip>

using namespace std;

Database* Database::instance = nullptr;

Attendance getAttendanceFromID(int id, Database* db) {
    for (Attendance attendance : db->getAttendance()) {
        if (attendance.getStudentID() == id) return attendance;
    }
    return Attendance();
}

int main() {
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