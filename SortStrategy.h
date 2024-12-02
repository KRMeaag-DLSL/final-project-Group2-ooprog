#include <iostream>
#include <algorithm>
#include <vector>
#include "Database.h"

using namespace std;

class SortStrategy {
    public:
        virtual void sortData(vector<int>& data) = 0;
};

class BalanceSort : public SortStrategy {
    public:
        void sortData(vector<int>& data) override {}
};

class IDSort : public SortStrategy {
    public:
        void sortData(vector<int>& data) override {
            sort(data.begin(), data.end(), [](int a, int b) {
                StudentEntry studentEntryA, studentEntryB;
                for (StudentEntry entry : Database::getInstance()->getStudentEntries()) {
                    if (entry.getStudentID() == a) studentEntryA = entry;
                    else if (entry.getStudentID() == b) studentEntryB = entry;
                }

                return studentEntryA.getStudentID() < studentEntryB.getStudentID();
            });
        }
};

class GradesSort : public SortStrategy {
    public:
        void sortData(vector<int>& data) override {
            sort(data.begin(), data.end(), [](int a, int b) {
                Grade gradeA, gradeB;
                for (Grade grade : Database::getInstance()->getGrades()) {
                    if (grade.getStudentID() == a) gradeA = grade;
                    else if (grade.getStudentID() == b) gradeB = grade;
                }

                //point system
                double valueA = (gradeA.getEnglish() + 
                            gradeA.getMath() + 
                            gradeA.getScience() + 
                            gradeA.getSocStud() + 
                            gradeA.getFilipino() + 
                            gradeA.getTLE() + 
                            gradeA.getCLCE() + 
                            gradeA.getMAPEH())/8;
                float valueB = (gradeB.getEnglish() + 
                            gradeB.getMath() + 
                            gradeB.getScience() + 
                            gradeB.getSocStud() + 
                            gradeB.getFilipino() + 
                            gradeB.getTLE() + 
                            gradeB.getCLCE() + 
                            gradeB.getMAPEH())/8;
                return valueA > valueB;
            });
        }
};

class AttendanceSort : public SortStrategy {
    public:
        void sortData(vector<int>& data) override {
            sort(data.begin(), data.end(), [](int a, int b) {
                Attendance attendanceA, attendanceB;
                for (Attendance attendance : Database::getInstance()->getAttendance()) {
                    if (attendance.getStudentID() == a) attendanceA = attendance;
                    else if (attendance.getStudentID() == b) attendanceB = attendance;
                }

                //point system
                float valueA = attendanceA.getAbsents() + (attendanceA.getLates()*0.5);
                float valueB = attendanceB.getAbsents() + (attendanceB.getLates()*0.5);
                return valueA < valueB;
            });
        }
};

class SortContext {
    private:
        SortStrategy* strategy;
    
    public:
        SortContext(SortStrategy* strategy) : strategy(strategy) {}

        void setSortStrategy(SortStrategy* strat) {strategy = strat;}

        void sortData(vector<int>& data) {
            strategy->sortData(data);
        }

};