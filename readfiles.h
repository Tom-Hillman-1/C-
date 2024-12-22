#ifndef PAYMENTS_H
#define PAYMENTS_H
#include <string>
#include <map>
#include "people.h"

using namespace std;

// Reads and processes the payments file with data of purchase information
bool loadPayments(const string& filename, map<string, people>& people);

// Reads the people file and generates purchase summaries for specific persons's
bool generateSummaries(const string& filename, const map<string, people>& people);

#endif
