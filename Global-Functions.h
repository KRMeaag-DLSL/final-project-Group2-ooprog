#pragma once

#include <cctype>
#include <cstdlib>
#include <ctype.h>
#include <iostream>

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
        else if (strInput.length() != 1) {
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
