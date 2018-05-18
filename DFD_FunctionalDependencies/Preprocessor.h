//
// Created by Hongyu Zhu on 2018/5/16.
//



#ifndef FD_PREPROCESSOR_H
#define FD_PREPROCESSOR_H


#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

class Preprocessor {
public:
    Preprocessor(string filePath, unsigned long colNum);

    int getData(vector<vector<unsigned>> &data);

private:
    void parseLine(vector<unsigned> &parsed, const string &line, vector<unordered_map<string, unsigned>> &metElementSet,
                   vector<unsigned> &maxIndex);

    string filePath; // path to data file
    unsigned long colNum;
};


#endif //FD_PREPROCESSOR_H
