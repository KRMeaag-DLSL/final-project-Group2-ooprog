#include <iostream>
#include <vector>

using namespace std;

class SortStrategy {
    public:
        virtual void sort(vector<int>& data) = 0;
};

class BalanceSort : SortStrategy {
    public:
        void sort(vector<int>& data) override {}
};

class IDSort : SortStrategy {
    public:
        void sort(vector<int>& data) override {}
};

class GradesSort : SortStrategy {
    public:
        void sort(vector<int>& data) override {}
};

class AttendanceSort : SortStrategy {
    public:
        void sort(vector<int>& data) override {
            



        }
};

class SortContext {
    private:
        SortStrategy* strategy;
    
    public:
        void setSortStrategy(SortStrategy* strat) {strategy = strat;}

        void sortData(vector<int>& data) {
            strategy->sort(data);
        }

};