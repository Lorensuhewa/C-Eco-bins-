#pragma once
#ifndef WASTELIST_H
#define WASTELIST_H
#include <iostream>
#include <string>
#include <vector>

struct WasteItem {
    std::string name;
    double weight;
    WasteItem* next;
};

class WasteList {
private:
    WasteItem* head;

    bool isWasteItemValid(const std::string& itemName) const;
    bool compareIgnoreCase(const std::string& str1, const std::string& str2) const;

    bool isGeneralWaste(const std::string& itemName) const;
    bool isPaperAndCardboard(const std::string& itemName) const;
    bool isPlasticGlassCans(const std::string& itemName) const;
    bool isGardenWaste(const std::string& itemName) const;
    bool isFoodWaste(const std::string& itemName) const;

public:
    WasteList();
    ~WasteList();

    void categorizeWaste() const;
    void addWaste(const std::string& name, double weight);
    void removeWaste();
    void displayWaste() const;
    void editWaste(const std::string& name, const std::string& newName, double newWeight);
    WasteItem* getHead() const;
    void addNewWasteItems();

    int displayWasteItemMenu() const;
    std::string getWasteType(const std::string& itemName) const;
    std::string getSuitableBin(const std::string& wasteType) const;
};

# endif// WASTELIST
