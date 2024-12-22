#include <iostream>
#include <map>
#include "people.h"
#include "readfiles.h"

using namespace std;

int main() {
    map<string, people> people;

    // Attempt to load payment data from the file - print erroe if fails
    if (!loadPayments("payments.txt", people)) {
        cerr << "Failed to load payments data." << endl;
        return 1;
    }

    // Attempt to generate and print purchase summaries - print error if fails
    if (!generateSummaries("people.txt", people)) {
        cerr << "Failed to generate summaries." << endl;
        return 2;
    }

    return 0;
}
