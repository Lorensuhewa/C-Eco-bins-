// WasteList.cpp

#include "WasteList.h"
#include <iostream>
#include <limits>


using namespace std;

const vector<string> wasteItemsList = {
    "Plastic","Polythene","Glass","Cans", "Papers","Cardboard","GardenWaste","FoodWaste", "Rubbish"
};

WasteList::WasteList() : head(nullptr) {}

WasteList::~WasteList() {
    while (head) {
        WasteItem* temp = head;
        head = head->next;
        delete temp;
    }
}

void WasteList::categorizeWaste() const {
    WasteItem* current = head;
    while (current) {
        string type = getWasteType(current->name);
        string suitableBin = getSuitableBin(type);
        cout << "Item:" << current->name << "      |        Type:" << type << "       |       Suitable Bin:" << suitableBin << " \n" << endl;

        current = current->next;
    }
}

void WasteList::addWaste(const std::string& name, double weight) {
    if (!isWasteItemValid(name)) {
        cout << "This waste item is not in the list. Item not added." << endl;
        return;
    }

    WasteItem* newItem = new WasteItem;
    newItem->name = name;
    newItem->weight = weight;
    newItem->next = head;
    head = newItem;

    cout << "New waste item added to the bin." << endl;
}

bool WasteList::isWasteItemValid(const string& itemName) const {
    for (const string& item : wasteItemsList) {
        if (compareIgnoreCase(item, itemName)) {
            return true;
        }
    }
    return false;
}

bool WasteList::compareIgnoreCase(const string& str1, const string& str2) const {
    // Utility function to compare strings case-insensitively
    if (str1.size() != str2.size()) {
        return false;
    }

    for (size_t i = 0; i < str1.size(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }

    return true;
}

void WasteList::removeWaste() {
    if (head) {
        WasteItem* temp = head;
        head = head->next;
        delete temp;
        cout << "Waste item removed from the list." << endl;
    }
    else {
        cout << "No waste items to remove from the list." << endl;
    }
}

void WasteList::displayWaste() const {
    WasteItem* current = head;
    cout << "Waste List:" << endl;
    while (current) {
        cout << "Name: " << current->name << "       |     Weight: " << current->weight << " kg\n" << endl;
        current = current->next;
    }
}

void WasteList::editWaste(const string& name, const string& newName, double newWeight) {
    WasteItem* current = head;
    while (current) {
        if (compareIgnoreCase(current->name, name)) {
            current->name = newName;
            current->weight = newWeight;
            cout << "Updated waste item details." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Waste item not found." << endl;
}

WasteItem* WasteList::getHead() const {
    return head;
}

void WasteList::addNewWasteItems() {
    int numItems;

    // Get the number of waste items to add
    cout << "Enter the number of waste items to add: ";
    while (!(std::cin >> numItems) || numItems <= 0) {
        cin.clear();  // Clear input buffer to restore cin to a usable state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore last input
        cout << "Invalid input. Please enter a positive integer: ";
    }

    // Loop to add the specified number of waste items
    for (int i = 0; i < numItems; ++i) {
        // Display the list of waste items for the user to choose from
        int itemChoice = displayWasteItemMenu();

        // Get user input for new details
        double newWeight;
        cout << "Enter weight for item " << i + 1 << ": ";
        while (!(cin >> newWeight) || newWeight <= 0) {
            cin.clear();  // Clear input buffer to restore cin to a usable state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore last input
            cout << "Invalid input. Please enter a positive number: ";
        }

        // Add the new waste item to the list
        if (itemChoice > 0 && itemChoice <= static_cast<int>(wasteItemsList.size())) {
            addWaste(wasteItemsList[itemChoice - 1], newWeight);
        }
        else {
            cout << "Invalid choice. This waste item is not in the list." << endl;
            --i;  // Decrement i to repeat the loop for the current iteration
        }
    }
}

int WasteList::displayWasteItemMenu() const {
    cout << "Select the waste item:" << endl;

    for (size_t i = 0; i < wasteItemsList.size(); ++i) {
        cout << i + 1 << ". " << wasteItemsList[i] << endl;
    }

    int choice;
    cout << "Enter your choice (1-" << wasteItemsList.size() << "): ";
    while (!(cin >> choice) || choice < 1 || choice > static_cast<int>(wasteItemsList.size())) {
        cin.clear();  // Clear input buffer to restore cin to a usable state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore last input
        cout << "Invalid choice. Please enter a valid number (1-" << wasteItemsList.size() << "): ";
    }

    return choice;
}

std::string WasteList::getWasteType(const std::string& itemName) const {
    if (compareIgnoreCase(itemName, "Plastic") || compareIgnoreCase(itemName, "Polythene") ||
        compareIgnoreCase(itemName, "Glass") || compareIgnoreCase(itemName, "Cans")) {
        return "Blue";  // Blue bin
    }

    else if (compareIgnoreCase(itemName, "Papers") || compareIgnoreCase(itemName, "Cardboard")) {
        return "Yellow";  // Yellow bin
    }
    else if (compareIgnoreCase(itemName, "GardenWaste")) {
        return "Green";  // Red bin
    }
    else if (compareIgnoreCase(itemName, "FoodWaste")) {
        return "Red";  // Green bin
    }
    else if (compareIgnoreCase(itemName, "Rubbish")) {
        return "Black";  // Black bin
    }
    else {
        return "This waste item is not in the list. This item can not put into the bins";
    }
}


string WasteList::getSuitableBin(const string& wasteType) const {
    if (wasteType == "Blue") {
        return "Put your garbage in the Blue Bin";
    }
    else if (wasteType == "Yellow") {
        return "Put your garbage in the Yellow Bin";
    }
    else if (wasteType == "Red") {
        return "Put your garbage in the Red Bin";
    }
    else if (wasteType == "Green") {
        return "Put your garbage in the Green Bin";
    }
    else if (wasteType == "Black") {
        return "Put your garbage in the Black Bin";
    }
    else {
        return "This item is not in the list";
    }
}



bool WasteList::isPaperAndCardboard(const string& itemName) const {
    return (compareIgnoreCase(itemName, "Papers") || compareIgnoreCase(itemName, "Cardboard"));
}

bool WasteList::isPlasticGlassCans(const string& itemName) const {
    return (compareIgnoreCase(itemName, "Plastic") || compareIgnoreCase(itemName, "Polythene") ||
        compareIgnoreCase(itemName, "Glass") || compareIgnoreCase(itemName, "Cans"));
}

bool WasteList::isGardenWaste(const string& itemName) const {
    return (compareIgnoreCase(itemName, "GardenWaste"));
}

bool WasteList::isFoodWaste(const string& itemName) const {
    return compareIgnoreCase(itemName, "Food Waste");
}
bool WasteList::isGeneralWaste(const string& itemName) const {
    return compareIgnoreCase(itemName, "Rubbish");
}

