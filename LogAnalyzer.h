#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;

class LogAnalyzer {
private:
    unordered_map<string, int> logCounts;

public:
    void analyzeLogFile(const string& filename);
    void printSummary();
};
#endif