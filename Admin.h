#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Users.h"

using namespace std;

class Admin : Account{
    void createStudentEntry() {

    }
    void createDisciplinaryRecord() {}
    void searchStudent() {}
    void analytics() {}
    void updateDisciplinaryRecords() {}
    void updateStudentPerformance() {}
    void assignFaculty() {}
    void updateStudentInfo() {}
    void deleteStudentEntry() {}
    void removeDisciplinaryRecord() {}
    void displayStudents() {}

    void menu() override {
        cout << "1. Create Student Entry" << endl
            << "2. Create Disciplinary Record" << endl
            << "3. Search Student" << endl
            << "4. Analytics" << endl
            << "5. Update Disciplinary Records" << endl
            << "6. Update Student Performance" << endl
            << "7. Assign Faculty" << endl
            << "8. Update Student Info" << endl
            << "9. Delete Student Entry" << endl
            << "10. Remove Disciplinary Record" << endl
            << "11. Display Students" << endl;
    }

};