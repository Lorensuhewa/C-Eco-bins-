// ConsoleApplication3.cpp

#include <iostream>
#include "WasteList.h"
#include "WasteStack.h"
#include "FileOperations.h"

using namespace std;

// Function to get user input for a waste item
WasteItem getUserWasteItemInput() {
    WasteItem item;
    cout << "------------------------------------------------------------------------------------------------\nEnter the items from the list:\n\n* Plastic\n* Polythene\n* Glass\n* Cans\n* Papers\n* Cardboards\n* GardenWaste\n* FoodWaste\n* Rubbish\n\n";
    cin >> item.name;
    cout << "Enter waste item weight (kg): ";
    cin >> item.weight;
    return item;
}

// Function to get user input for a waste bin
WasteBin getUserWasteBinInput() {
    WasteBin bin;
    cout << "Enter waste bin name: \n\n* PaperAndCardboard\n* PlasticGlassCans\n* GardenWaste\n* FoodWaste\n* GeneralWaste\n\n";
    cin >> bin.name;
    cout << "Enter waste bin capacity (kg): ";
    cin >> bin.capacity;
    cout << "Enter waste bin location: ";
    cin >> bin.location;
    cout << "Enter waste bin type: \n\n* Yellow\n* Blue\n* Green \n* Red\n* Black\n\n ";
    cin >> bin.type;
    return bin;
}

int main() {
    WasteList wasteList;
    WasteStack wasteStack;

    cout << "                                **************************************************\n                                    Welcome to smart waste management system\n                                *****************************************************\n";

    // Get user input for waste items and add them to the linked list
    int numItems;
    cout << "Enter the number of waste items: ";
    cin >> numItems;

    for (int i = 0; i < numItems; i++) {
        WasteItem item = getUserWasteItemInput();
        wasteList.addWaste(item.name, item.weight);
    }

    // Display categorized waste items
    cout << "Categorized Waste Items:" << endl;
    wasteList.categorizeWaste();

    // Get user input for waste bins and push them onto the stack
    int numBins;
    cout << "Enter the number of waste bins: ";
    cin >> numBins;

    for (int i = 0; i < numBins; i++) {
        WasteBin bin = getUserWasteBinInput();
        wasteStack.push(bin.name, bin.capacity, bin.location, bin.type);  // Adjusted to match the current function signature
    }

    // Display the waste items and bins
    wasteList.displayWaste();
    wasteStack.displayStack();

    // The rest of your code for editing, allocating waste, dynamic scheduling, etc.

    // Save waste items and bins to files
    saveWasteItemsToFile(wasteList, "waste_items.txt");
    saveWasteBinsToFile(wasteStack, "waste_bins.txt");

    // Load waste items and bins from files
    WasteList loadedWasteList;
    WasteStack loadedWasteStack;

    loadWasteItemsFromFile(loadedWasteList, "waste_items.txt");
    loadWasteBinsFromFile(loadedWasteStack, "waste_bins.txt");

    // Display the loaded waste items and bins
    loadedWasteList.displayWaste();
    loadedWasteStack.displayStack();

    return 0;
}