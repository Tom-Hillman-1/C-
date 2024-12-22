#ifndef PERSON_H
#define PERSON_H
#include <iomanip>
#include <map>
#include <string>

using namespace std;

class people {
public:
    // Adds the purchases to the person's records and then print the summery
    void addPurchase(const string& itemName, double itemPrice);
    void printSummary(const string& personName) const;

// tracks item prices for a person
private:
    map<string, double> purchases;
    double totalSpent = 0.0;
};

#endif
