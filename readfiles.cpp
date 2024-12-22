#include "readfiles.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
//helper function to open files
bool openFile(const string& filename, ifstream& file) {
    file.open(filename);
    if (!file) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return false;
    }
    return true;
}
//try to open the payments.txt file
bool loadPayments(const string& filename, map<string, people>& people) {
    ifstream file;
    if (!openFile(filename, file)) {
        return false;
    }
//reads the file line by line, analyzing each person's purchases
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string personName, itemName;
        double itemPrice;

//throws error messages depanding on the data input error
        if (!(iss >> personName)) {
            cerr << "Error: Missing person name in line: " << line << endl;
            continue;
        }
        if (!(iss >> itemName)) {
            cerr << "Error: Missing item name for person '" << personName << "' in line: " << line << endl;
            continue;
        }
        if (!(iss >> itemPrice)) {
            cerr << "Error: Missing or invalid price for item '" << itemName << "' by '" << personName << "' in line: " << line << endl;
            continue;
        }
        //adds the purchase to the corecct person
        people[personName].addPurchase(itemName, itemPrice);
    }

    return true;
}
//opens people file, goes through each name/line in the file,
//then prints summery if the person is found. else throws an error message
bool generateSummaries(const string& filename, const map<string, people>& people) {
    ifstream file;
    if (!openFile(filename, file)) {
        return false;
    }
    string personName;
    bool peopleFileEmpty = true;

    while (getline(file, personName)) {
        peopleFileEmpty = false;
        auto it = people.find(personName);
        if (it != people.end()) {
            it->second.printSummary(personName);
        } else {
            cerr << "Error: Name '" << personName << "' not found in payments data." << endl;
        }
    }
    //check if file is empty, throw error
    if (peopleFileEmpty) {
        cerr << "Error: The file '" << filename << "' is empty." << endl;
        return false;
    }
    return true;
}
