#pragma once
// WasteStack.h
#ifndef WASTE_STACK_H
#define WASTE_STACK_H

#include <string>


using namespace std;

struct WasteBin {
    string name;
    double capacity;
    double fillLevel;
    string location;
    string type;
};


const int MAX_STACK_SIZE = 5; //  the maximum stack size 


class WasteStack {
private:
    static constexpr int MAX_STACK_SIZE = 5;
    WasteBin stack[MAX_STACK_SIZE];
    int top;

public:
    WasteStack(); //constructor

    void push(const string& name, double capacity, const string& location, const string& type);
    WasteBin pop();
    void displayStack() const;
    void configureBin(const string& name, const string& location);

    int getTop() const; //encapsulation(sensitive data hidden from the user)
    const WasteBin* getStack() const;

private:
    bool isBinFull(int index) const;
    void checkFillLevelWarning(const WasteBin& bin) const;
};

#endif // WASTE_STACK_H



