#include <cstdlib>
#include <ctype.h>
#include <iostream>

using namespace std;

inline void clearScreen() {
  if (system("cls"))
  {
      system("clear");
  }
}

inline int inputMenu(int maxOption) {
    string strInput;
    try {
        cin >> strInput;
        if (!isdigit(strInput[0])) {
            throw "Input is not an integer, please try again!";
        }
        else if (strInput.length() != 1) {
            throw "Input is invalid, please try again!";
        }
        else if (atoi(&strInput[0]) < 1 || atoi(&strInput[0]) > maxOption) {
            throw "Input is not within the range of options, please try again!";
        }
        else {
            return atoi(&strInput[0]);
        }
    } catch (const string msg) {
        cout << msg << endl;
        return -1;
    } catch (...) {
        cout << "Unknown exception error occured. Please try again!" << endl;
        return -1;
    }

    return 0;
}

inline void continueToNext() {
    string input;
    cout << "Type any character then press enter to continue: ";
    cin >> input;
}
