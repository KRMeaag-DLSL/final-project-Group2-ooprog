#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
using namespace std;

class Pet {
private:
    string type;
    bool isFriendly;

public:
    Pet(string type, bool isFriendly) : type(type), isFriendly(isFriendly) {}

    virtual void makeNoise() const = 0;

    virtual string toString() const {
    return "Pet " + type + " is " + (isFriendly ? "friendly" : "not friendly");
    }

};

class Lion : public Pet {
public:
    Lion() : Pet("lion", false) {}

    void makeNoise() const override {
    cout<<"Roar!\n";
    }
};

class Dog : public Pet {
private:
    string breed;

public:
    Dog(string breed): Pet("dog", true), breed(breed) {}

    void makeNoise() const override{
    cout<<"Arf!\n";
    }

    string toString() const override {
    return "Pet dog is friendly [" + breed + "]";
    }
};

class Cat : public Pet {
public: 
    Cat () : Pet("cat", true) {}

    void makeNoise() const override {
    cout<<"Meow!\n";
    }
};

class PetHouse {
public:
    PetHouse(const vector<Pet*>& pets){
    for (const auto& pet : pets) {
    pet->makeNoise();
    }
}
};