#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Database.h"

using namespace std;

Database* Database::instance = nullptr;

int main() {

    // Check size of vector
    cout << "Number of students loaded: " << Database::getInstance()->getStudentEntries().size() << endl;

    // Print all student names
    for (const auto& entry : Database::getInstance()->getStudentEntries()) {
        cout << "Name: " << entry.getName() << endl;
    }

    return 0;
}
