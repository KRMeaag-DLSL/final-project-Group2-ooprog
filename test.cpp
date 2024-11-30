#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Database.h"
#include "Faculty.h"
#include "Users.h"

using namespace std;

Database* Database::instance = nullptr;

int main() {
    Faculty faculty("Faculty201");

    faculty.menu();

}