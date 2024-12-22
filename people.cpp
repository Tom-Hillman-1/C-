#include "people.h"
#include <iostream>
#include <iomanip>
#include <map>
void people::addPurchase(const string& itemName, double itemPrice) {
    //validate input is positive
    if (itemPrice < 0) {
        cerr << "Warning: Invalid price for item '" << itemName << "' (" << itemPrice << "). Skipping." << endl;
        return;
    }
    purchases[itemName] = itemPrice;
    totalSpent += itemPrice;
}
//display person's purchase details
void people::printSummary(const string& personName) const {
    cout << personName << endl;
    for (const auto& [item, price] : purchases) {
        cout << item << " " << fixed << setprecision(2) << price << endl;
    }
    //outputs the total expenses for the person
    cout << "Total: " << fixed << setprecision(2) << totalSpent << endl;
}
