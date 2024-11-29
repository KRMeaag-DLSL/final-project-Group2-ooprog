#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class StudentEntry {
    private:
        int studentID;
        string name;
        int age;
        string contact;
        string address;
        string emailAddress;
        string department;
    public:
        StudentEntry(int id, string name, int age, string contact, string address, string emailAddress, string department) :
         studentID(id), name(name), age(age), contact(contact), address(address), emailAddress(emailAddress), department(department) {}

        int getStudentID() { return studentID;}
        void setStudentID(int id) {studentID = id;}
        string getName() const { return name;}
        void setName(string n) { name = n;}
        int getAge() { return age;}
        void setAge(int a) { age = a;}
        string getContact() { return contact;}
        void setContact(string c) { contact = c;}
        string getAddress() { return address;}
        void setAddress(int a) { address = a;}
        string getEmailAddress() { return emailAddress;}
        void setEmailAddress(string ea) { emailAddress = ea;}
        string getDepartment() { return department;}
        void setDepartment(string d) { department = d;}
};

class Record {
    private:
        int studentID;
        string offence;
        int severity;
        string date;
    public:
        Record(int id, string of, int s, string d) : studentID(id), offence(of), severity(s), date(d) {}
        int getStudentID() { return studentID;}
        string getOffence() { return offence;}
        int getSeverity() { return severity;}
        string getDate() { return date;}
        void setStudentID(int id) { studentID = id;}
        void setOffence(string of) { offence = of;}
        void setSeverity(int s) { severity = s;}
        void setDate(string d) { date = d;}
};

class Deadline {
    private:
        int studentID;
        string name;
        int daysUntilDeadlines;
        string deadlineDate;
        string subject;
    public:
        Deadline(int id, string n, int dUD, string dLD, string s) 
        : studentID(id), name(n), daysUntilDeadlines(dUD), deadlineDate(dLD), subject(s) {}
        int getStudentID() { return studentID;}
        string getName() { return name;}
        int getDaysUntilDeadlines() { return daysUntilDeadlines;}
        string getDeadlineDate() { return deadlineDate;}
        string getSubject() { return subject;}
        void setStudentID(int id) {studentID = id;}
        void setName(string n) {name = n;}
        void setDaysUntilDeadlines(int dUD) {daysUntilDeadlines = dUD;}
        void setDeadlineDate(string dLD) {deadlineDate = dLD;}
        void setSubject(string s) {subject = s;}
};

class Grade {
    private:
        int studentID;
        double english;
        double math;
        double science;
        double socStud;
        double filipino;
        double tle;
        double clce;
        double mapeh;
    public:
        Grade(int id, double e, double m, double s, double sS, double f, double t, double c, double mapeh) 
        : studentID(id), english(e), math(m), science(s), socStud(sS), filipino(f), tle(t), clce(c), mapeh(mapeh) {}
        int getStudentID() { return studentID;}
        double getEnglish() { return english;}
        double getMath(){ return math;}
        double getScience(){ return science;}
        double getSocStud(){ return socStud;}
        double getFilipino(){ return filipino;}
        double getTLE(){ return tle;}
        double getCLCE(){ return clce;}
        double getMAPEH(){ return mapeh;}
        void setStudentID(int id) {studentID = id;}
        void setEnglish(double e){ english = e;}
        void setMath(double m){ math = m;}
        void setScience(double s){ science = s;}
        void setSocStud(double sS){ socStud = sS;}
        void setFilipino(double f){ filipino = f;}
        void setTLE(double t){ tle = t;}
        void setCLCE(double c){ clce = c;}
        void setMAPEH(double m){ mapeh = m;}
};

class FinancialCommitment {
    private:
        int studentID;
        int totalTuitionFee;
        int additionalFees;
        int paidAmount;
        string paymentDeadline;
    public:
        FinancialCommitment(int id, int ttf, int af, int pa, string pd) 
        : studentID(id), totalTuitionFee(ttf), additionalFees(af), paidAmount(pa), paymentDeadline(pd) {}
        int getStudentID() { return studentID;}
        int getTotalTuitionFee() { return totalTuitionFee;}
        int getAdditionalFees() { return additionalFees;}
        int getPaidAmount() { return paidAmount;}
        string getPaymentDeadline() { return paymentDeadline;}
};

class Attendance {
    private:
        int studentID;
        int absents;
        int lates;
    public:
        Attendance(int id, int a, int l) : studentID(id), absents(a), lates(l) {}
        int getStudentID() { return studentID;}
        int getAbsents() { return absents;}
        int getLates() { return lates;}
        void setStudentID(int id) { studentID = id;}
        void setAbsents(int a) { absents = a;}
        void setLates(int l) { lates = l;}
};

class Database {
    private:
        static Database* instance;
        vector<StudentEntry> studentEntries;
        vector<Record> records;
        vector<Grade> grades;
        vector<Deadline> deadlines;
        vector<Attendance> attendance;
        vector<FinancialCommitment> financialCommitments;

        Database () { 
            loadData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            loadData("MA2_Records-DB - Sheet1.csv", 2);
            loadData("MA2_Deadlines-DB - Sheet1.csv", 3);
            loadData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);
            loadData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);
            loadData("MA2_Attendance-DB - Sheet1.csv", 6);

            // delete this shit
            cout << "Total student entries loaded: " << studentEntries.size() << endl;
            cout << "Total records loaded: " << records.size() << endl;
            cout << "Total deadlines loaded: " << deadlines.size() << endl;
            cout << "Total grades loaded: " << grades.size() << endl;
            cout << "Total commitments loaded: " << financialCommitments.size() << endl;
            cout << "Total attendance loaded: " << attendance.size() << endl;
            
            saveData("MA2_Student-Entry-DB - Sheet1.csv", 1);
            saveData("MA2_Records-DB - Sheet1.csv", 2);
            saveData("MA2_Deadlines-DB - Sheet1.csv", 3);
            saveData("MA2_GS-JHS-Grades-DB - Sheet1.csv", 4);
            saveData("MA2_Financial-Commitments-DB - Sheet1.csv", 5);
            saveData("MA2_Attendance-DB - Sheet1.csv", 6);
        }
    
    public:
        static Database* getInstance() {
            return ((instance == nullptr) ? new Database() : instance);
        }

        void searchEntry(string studentID) {}
        vector<StudentEntry>& getStudentEntries() { return studentEntries;}
        vector<Record>& getRecords() { return records;}
        vector<Grade>& getGrades() { return grades;}
        vector<Deadline>& getDeadlines() { return deadlines;}
        vector<Attendance>& getAttendance() { return attendance;}
        vector<FinancialCommitment>& getFinancialCommitments() { return financialCommitments;}

        void getRowFromFile(ifstream& fin, vector<string>& row, string line, string word) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

        }

        void loadData(string fileName, int type) {
            ifstream fin(fileName, ios::in);

            if (!fin.is_open()) {
                cerr << "Error: Unable to open file!" << endl;
                return;
            }

            vector<string> row;
            string line, word;

            // Skip the header
            getline(fin, line);

            while (getline(fin, line)) {
                getRowFromFile(fin, row, line, word);

                int id = stoi(row[0]);
                // Add entry to the vector
                switch (type) {
                    case 1: {
                        int age = stoi(row[2]);
                        studentEntries.push_back(StudentEntry(id, row[1], age, row[3], row[4], row[5], row[6]));
                        break;
                    }
                    case 2: {
                        int severity = stoi(row[2]);
                        records.push_back(Record(id, row[1], severity, row[3]));
                        break;
                    }
                    case 3: {
                        int daysUntilDeadline =  stoi(row[2]);
                        deadlines.push_back(Deadline(id, row[1], daysUntilDeadline, row[3], row[4]));
                        break;
                    }
                    case 4: {
                        double english = stod(row[1]);
                        double math = stod(row[2]);
                        double science = stod(row[3]);
                        double socStud = stod(row[4]);
                        double filipino = stod(row[5]);
                        double tle = stod(row[6]);
                        double clce = stod(row[7]);
                        double mapeh = stod(row[8]);
                        grades.push_back(Grade(id, english, math, science, socStud, filipino, tle, clce, mapeh));
                        break;
                    }
                    case 5: {
                        int totalTuitionFee = stod(row[1]);
                        int additionalFees = stod(row[2]);
                        int paidAmount = stod(row[3]);
                        financialCommitments.push_back(FinancialCommitment(id, totalTuitionFee, additionalFees, paidAmount, row[4]));
                        break;
                    }
                    case 6: {
                        int absents = stoi(row[1]);
                        int lates = stoi(row[2]); 
                        attendance.push_back(Attendance(id, absents, lates));
                        break;
                    }
                }
            }
            fin.close();
        }

        void saveData(string fileName, int type) {
            // File pointer
            fstream fin, fout;

            // Open an existing record
            fin.open(fileName, ios::in);

            // Create a new file to store updated data
            fout.open("new.csv", ios::out);

            switch(type) {
                case 1: {
                    fout << "Student-ID,Name,Age,Contact,Address,Email Address,Department\n";
                    for (auto& student : studentEntries) {
                        fout << student.getStudentID() << "," << student.getName() << "," << student.getAge() << "," << student.getContact()
                        << "," << student.getAddress() << "," << student.getEmailAddress() << "," << student.getDepartment() << "\n";
                    }
                    break;
                }
                case 2: {
                    fout << "Student-ID,Offense,Severity,Date\n";
                    for (auto& record : records) {
                        fout << record.getStudentID() << "," << record.getOffence() << "," << record.getSeverity() << "," << record.getDate()
                        << "\n";
                    }
                    break;
                }
                case 3: {
                    fout << "Student-ID,Name,Days until the Deadline,Deadline Date,Subject\n";
                    for (auto& deadline : deadlines) {
                        fout << deadline.getStudentID() << "," << deadline.getName() << "," << deadline.getDaysUntilDeadlines() << "," <<
                        deadline.getDeadlineDate() << "," << deadline.getSubject() << "\n";
                    }
                    break;
                }
                case 4: {
                    fout << "Student-ID,English,Science,Mathematics,Filipino,Social Studies,CLCE ,TLE,MAPEH\n";
                    for (auto& grade : grades) {
                        fout << grade.getStudentID() << "," << grade.getEnglish() << "," << grade.getScience() << "," << grade.getMath()
                        << "," << grade.getFilipino() << "," << grade.getSocStud() << "," << grade.getCLCE() << "," << grade.getTLE()
                        << "," << grade.getMAPEH() << "\n";
                    }
                    break;
                }
                case 5: {
                    fout << "Student-ID,Total-Tuition-Fee,Additional-Fees,Paid-Amount,Payment-Deadline\n";
                    for (auto& commitment : financialCommitments) {
                        fout << commitment.getStudentID() << "," << commitment.getTotalTuitionFee() << "," << commitment.getAdditionalFees()
                        << "," << commitment.getPaidAmount() << "," << commitment.getPaymentDeadline() << "\n";
                    }
                    break;
                }
                case 6: {
                    fout << "Student-ID,Absents,Lates\n";
                    for (auto& attendance : attendance) {
                        fout << attendance.getStudentID() << "," << attendance.getAbsents() << "," << attendance.getLates() << "\n";
                    }
                    break;
                }
            }
            fin.close();
            fout.close();
            
            // removing the existing file
            remove(fileName.c_str());

            // renaming the updated file with the existing file name
            rename("new.csv", fileName.c_str());
        }
};