// WasteStack.cpp
#include "WasteStack.h"
#include <iostream>

using namespace std;

WasteStack::WasteStack() : top(-1) {} //indicate empty stack

void WasteStack::push(const string& name, double capacity, const string& location, const string& type) {
    if (top < MAX_STACK_SIZE - 1) { // add bins in the stack
        WasteBin bin;
        bin.name = name;
        bin.capacity = capacity;
        bin.fillLevel = 0.0;  // Initial fill level is zero
        bin.location = location;
        bin.type = type;

        stack[++top] = bin;

        if (isBinFull(top)) {
            cout << "Bin " << name << " at " << location << " is full. Please collect the waste." << endl; //bin is full
        }
        else {
            checkFillLevelWarning(bin);
        }
    }
    else {
        cout << "Stack is full. Cannot add more waste bins." << endl; //stack is full
    }
}

void WasteStack::checkFillLevelWarning(const WasteBin& bin) const {
    double fillPercentage = (bin.fillLevel / bin.capacity) * 100.0; //filllevel and capapcity in kg

    if (fillPercentage >= 80.0) {
        cout << "Warning: Bin " << bin.name << " at " << bin.location << " is close to capacity. Consider collecting the waste." << endl;
        cout << "Bin should collect: " << bin.type << ", Location: " << bin.location << endl;
    }
    else if (fillPercentage >= 50.0) {
        cout << "Medium fill level in Bin " << bin.name << " at " << bin.location << ". Consider checking the waste collection." << endl;
    }
    else if (fillPercentage >= 25.0) {
        cout << "Low fill level in Bin " << bin.name << " at " << bin.location << ". Waste collection is ongoing." << endl;
    }
}

WasteBin WasteStack::pop() {
    if (top >= 0) {
        return stack[top--];
    }
    else {
        cout << "Stack is empty." << endl; //top<0  ,top=-1
        WasteBin emptyBin; // Return an empty bin to indicate the stack is empty
        return emptyBin;
    }
}

void WasteStack::displayStack() const { //printing waste bin information
    cout << "Waste Bins:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << "Bin- " << stack[i].name << "      |     Location - " << stack[i].location
            << "    |    Type - " << stack[i].type << "     |     Fill Level - " << stack[i].fillLevel << " / " << stack[i].capacity << " kg" << endl;

        if (isBinFull(i)) {
            cout << "Bin " << stack[i].name << " at " << stack[i].location << " is full. Please collect the waste." << endl;
        }
    }
}

void WasteStack::configureBin(const string& name, const string& location) {
    for (int i = top; i >= 0; i--) { //ubdating location
        if (stack[i].name == name) {
            stack[i].location = location;
            cout << "Updated bin location." << endl;

            if (isBinFull(i)) {
                cout << "Bin " << name << " at " << location << " is full. Please collect the waste." << endl;
            }

            return;
        }
    }
    cout << "Bin not found." << endl;
}

int WasteStack::getTop() const {
    return top;
}

const WasteBin* WasteStack::getStack() const {
    return stack;
}

bool WasteStack::isBinFull(int index) const {
    return stack[index].fillLevel >= stack[index].capacity;
}