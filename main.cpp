#include "LogAnalyzer.h"

int main() {

    LogAnalyzer analyzer;

    analyzer.analyzeLogFile(
        R"(C:\Users\aalsh\OneDrive\Documents\C++\Log-Analysis-and-Tool-Monitoring\system.log)"
    );

    analyzer.printSummary();

    return 0;
}