#pragma once

#include <cctype>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <regex>

using namespace std;

// Pauses and continues to next
inline void continueToNext() {
    string input;
    cout << "Type any character then press enter to continue: ";
    cin >> input;
}

// Clears Screen
inline void clearScreen() {
  if (system("cls"))
  {
      system("clear");
  }
}

// For Menus, Returns either chosen number or -1, indicating error
inline int inputMenu(int maxOption) {
    string strInput;
    try {
        cin >> strInput;
        if (!isdigit(strInput[0])) {
            throw string("\nInput is either a negative or not an integer, please try again!");
        }
        else if (strInput.length() > 2) {// I changed it cuz my menus is more than one digit
            throw string("\nInput is invalid, please try again!");
        }
        else if (atoi(&strInput[0]) < 1 || atoi(&strInput[0]) > maxOption) {
            throw string("\nInput is not within the range of options, please try again!");
        }
        else {
            return atoi(&strInput[0]);
        }
    } catch (const string& msg) {
        cout << msg << endl;
        continueToNext();
        return -1;
    } catch (...) {
        cout << "\nUnknown exception error occured. Please try again!" << endl;
        continueToNext();
        return -1;
    }

    return 0;
}

inline bool checkStrDigit(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

// For StudentID Searches, Returns either inputted ID or -1, indicating error
inline int inputStudentID() {
    string strInput;
    try {
        cin >> strInput;
        if (!checkStrDigit(strInput)) {
            throw string("\nInput is not an integer, please try again!");
        } else if (strInput.length() != 10) {
            throw string("\nInput is not a student ID, please try again!");
        } else if (stoi(strInput) < 0) {
            throw string("\nInput is a negative number, please try again!");
        } else {
            return stoi(strInput);
        }
    } catch (const string& msg) {
        cout << msg << endl;
        continueToNext();
        return -1;
    } catch (...) {
        cout << "\nUnknown exception error occured. Please try again!" << endl;
        continueToNext();
        return -1;
    }

    return 0;
}

// For double numbers that do not allow negative numbers, changes made using num ptr
inline bool inputDoubleNum(double* num) {
    string numStr;
    try {
        cin >> numStr;
        if (!checkStrDigit(numStr)) {
            throw string("\nInput is not an integer, please try again!");
        } else if (stoi(numStr) < 0) {
            throw string("\nInput is a negative number, please try again!");
        } else {
            *num = stoi(numStr);
            return true;
        }
    } catch (const string& msg) {
        cout << msg << endl;
        continueToNext();
        return false;
    } catch (...) {
        cout << "\nUnknown exception error occured. Please try again!" << endl;
        continueToNext();
        return false;
    }

    return false;
}

// For int numbers that do not allow negative numbers, changes made using num ptr
inline bool inputIntNum(int* num) {
    string numStr;
    try {
        cin >> numStr;
        if (!checkStrDigit(numStr)) {
            throw string("\nInput is not an integer, please try again!");
        } else if (stoi(numStr) < 0) {
            throw string("\nInput is a negative number, please try again!");
        } else {
            *num = stoi(numStr);
            return true;
        }
    } catch (const string& msg) {
        cout << msg << endl;
        continueToNext();
        return false;
    } catch (...) {
        cout << "\nUnknown exception error occured. Please try again!" << endl;
        continueToNext();
        return false;
    }

    return false;
}

inline int checkDate(string input) {
    int slashCtr = 0;
    int digitCtr = 0;

    if (input.length() != 10) {
        return 1;
    }

    if (input[2] != '/' || input[5] != '/') {
        return 1;
    }

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '/') {
            slashCtr++;
        } else if (isdigit(input[i])) {
            digitCtr++;
        }
    }

    if (slashCtr != 2 || digitCtr != 8) {
        return 1;
    }

    int month = stoi(input.substr(0, 2));
    int day = stoi(input.substr(3, 2));
    int year = stoi(input.substr(6, 4));

    if (month < 1 || month > 12) {
        return 2;
    }

    if (day < 1 || day > 31) {
        return 3;
    }
    
    if (month < 12 && year <= 2024) {
        return 4;
    }

    return 0;
}

inline bool isValidContact(const string& contact) {
    regex pattern(R"(\d{3}-\d{3}-\d{4})"); // Matches XXX-XXX-XXXX
    return regex_match(contact, pattern);
}

// Asks for date input, returns date if no errors and returns "INVALID_ERROR!" if an error occurs
inline string inputDate(bool isAdding) {
    string input;
    try {
        cin >> input;
        switch (checkDate(input)) {
            case 0:
                return input;
            case 1:
                throw string("Input is not a date. Please try again!");
                break;
            case 2:
                throw string("Input does not follow the correct month format (MM/DD/YYYY). Please try again!");
                break;
            case 3:
                throw string("Input's day is invalid. Please try again!");
                break;
            case 4:
                if (isAdding) {
                    throw string("You are trying to set a deadline in the past. Please try again!");
                    break;
                }
                return input;
        }
    } catch (const string& msg) {
        cout << msg << endl;
        continueToNext();
        return "INVALID_ERROR!";
    } catch (...) {
        cout << "\nUnknown exception error occured. Please try again!" << endl;
        continueToNext();
        return "INVALID_ERROR!";
    }

    return "???";
}