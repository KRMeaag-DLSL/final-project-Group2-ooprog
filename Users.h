#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

class Account {
    private:
        string username;
        string password;

    public:
        int login() {
            string line;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            ifstream fin;
            fin.open("MA2_Accounts-Information-DB.csv", ios::in);

            if (!fin.is_open()) {
                cerr << "Error! Unable to open account information file" << endl;
                return 1;
            }

            getline(fin,line);

            while(getline(fin, line)) {
                string checkUser, checkPassword;
                stringstream s(line);

                getline(s,checkUser, ',');
                getline(s,checkPassword, ',');

                if (username == checkUser && password == checkPassword) {
                    cout << "Login successful!" << endl;
                    return 0;
                }
            }

            cout << "Login failed. Please check your username and password." << endl;
            return 2;
        }

        void logout() {}
};