#include "LogAnalyzer.h"

void LogAnalyzer::analyzeLogFile(const string& filename) {

    ifstream file(filename);
    cout << filename << endl;

    vector<string> logs;

    // ❌ File open failed
    if (!file.is_open()) {
        cout << "Failed to open log file." << endl;
        return;
    }

    // ✅ Read file into vector
    string line;
    while (getline(file, line)) {
        logs.push_back(line);
    }

    file.close();

    // ✅ Regex pattern
    regex pattern(R"((\S+\s+\S+)\s+(INFO|WARN|ERROR|CRITICAL)\s+(.*))");

    // ✅ Process logs
    for (const string& logLine : logs) {

        smatch matches;

        if (regex_search(logLine, matches, pattern)) {

            string timestamp = matches[1];
            string level = matches[2];
            string message = matches[3];

            logCounts[level]++;

            cout << "Timestamp : " << timestamp << endl;
            cout << "Level     : " << level << endl;
            cout << "Message   : " << message << endl;
            cout << "--------------------------" << endl;

            if (level == "CRITICAL") {
                cout << "ALERT: Critical issue detected" << endl;
            }
        }
    }
}

void LogAnalyzer::printSummary() {

    cout << "\n====== LOG SUMMARY ======" << endl;

    for (const auto& entry : logCounts) {
        cout << entry.first << " : " << entry.second << endl;
    }
}