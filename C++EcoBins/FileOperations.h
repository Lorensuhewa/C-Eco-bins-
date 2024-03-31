#pragma once


#include "WasteList.h"
#include "WasteStack.h"

using namespace std;

void saveWasteItemsToFile(WasteList& wasteList, const string& filename);
void loadWasteItemsFromFile(WasteList& wasteList, const string& filename);
void saveWasteBinsToFile(const WasteStack& wasteStack, const string& filename);
void loadWasteBinsFromFile(WasteStack& wasteStack, const string& filename);

