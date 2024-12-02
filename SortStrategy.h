#include <iostream>
#include <vector>

using namespace std;

class SortContext {
    private:
        SortStrategy* strategy;
    
    public:
        void setSortStrategy(SortStrategy* strat) {strategy = strat;}

        void sortData(vector<string>& data) {
            strategy->sort(data);
        }

};

class SortStrategy {
    public:
        virtual void sort(vector<string>& data) = 0;
};

class BalanceSort : SortStrategy {
    public:
        void sort(vector<string>& data) override {
            
        }
};

class IDSort : SortStrategy {
    public:
        void sort(vector<string>& data) override {}
};

class GradesSort : SortStrategy {
    public:
        void sort(vector<string>& data) override {}
};

class AttendanceSort : SortStrategy {
    public:
        void sort(vector<string>& data) override {}
};