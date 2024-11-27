#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Database.h"

using namespace std;

Database* Database::instance = nullptr;

int main() {
    Database::getInstance()->loadData();
    cout << Database::getInstance()->getStudentEntries().size() << endl;
    for (auto& id : Database::getInstance()->getStudentEntries()) {
        cout << id.getName() << endl;
    }
    return 0;
}