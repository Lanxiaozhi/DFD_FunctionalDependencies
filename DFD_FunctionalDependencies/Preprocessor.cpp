//
// Created by Hongyu Zhu on 2018/5/16.
//

#include "Preprocessor.h"


Preprocessor::Preprocessor(string filePath, unsigned long colNum) : filePath(std::move(filePath)), colNum(colNum) {

}

int Preprocessor::getData(vector<vector<unsigned>> &data) {
    ifstream dataFile(filePath);
    string line;
    vector<unordered_map<string, unsigned>> metElementSet(colNum, unordered_map<string, unsigned>());
    vector<unsigned> maxIndex(colNum, 0);
    vector<unsigned> parsed(colNum, 0);
    if (dataFile.is_open()) {
        int rowCount = 0;
        while (getline(dataFile, line)) {
            rowCount++;
            parseLine(parsed, line, metElementSet, maxIndex);
//            // ===== DEBUG ======
//            for (int j = 0; j < colNum; j++) {
//                cout << parsed[j] << " ";
//            }
//            cout << endl;
//            // ==== DEBUGEND ====
            data.push_back(parsed);
        }
        dataFile.close();
        return rowCount;
    }
    return -1;
}

void Preprocessor::parseLine(vector<unsigned> &parsed, const string &line,
                             vector<unordered_map<string, unsigned>> &metElementSet,
                             vector<unsigned> &maxIndex) {
    // split line by ","(a comma) but not by ", "(a comma and a space)
    // and transform each element to an unsigned int.
    unsigned lastPos = 0;
    unsigned pos = 0;
    unsigned len = line.length();
    string elem;

    for (int i = 0; i < colNum - 1; i++) {
        while (line[pos] != ',' || (pos + 1 < len && line[pos + 1] == ' ')) {
            pos++;
        }

        elem = line.substr(lastPos, pos - lastPos);
        pos++;
        lastPos = pos;
        auto got = metElementSet[i].find(elem);
        if (got == metElementSet[i].end()) {
            maxIndex[i]++;
            metElementSet[i].insert({elem, maxIndex[i]});
            parsed[i] = maxIndex[i];
        } else {
            parsed[i] = got->second;
        }
    }
    elem = line.substr(lastPos, len - lastPos);
    auto got = metElementSet[colNum - 1].find(elem);
    if (got == metElementSet[colNum - 1].end()) {
        maxIndex[colNum - 1]++;
        metElementSet[colNum - 1].insert({elem, maxIndex[colNum - 1]});
        parsed[colNum - 1] = maxIndex[colNum - 1];
    } else {
        parsed[colNum - 1] = got->second;
    }
}