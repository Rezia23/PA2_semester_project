 //
// Created by terez on 27.04.2020.
//

#include "CApplicationConsole.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CApplicationConsole::getVariableName(string &input, string &varName) const {
    std::string::size_type spacePosition;
    spacePosition = input.find(" ");
    if (spacePosition == std::string::npos) {
        return false;
    }
    varName = input.substr(0, spacePosition);
    if (varName == "") {
        return false;
    }
    input = input.substr(spacePosition + 1);
    return true;
}

bool CApplicationConsole::ReadSize(std::size_t &numRows, std::size_t &numCols, istream &inStream) const {
    if (!(inStream >> numRows) || !(inStream >> numCols)) {
        return false;
    }
    char delimiter;
    if (!(inStream >> delimiter) || delimiter != '|') {
        return false;
    }
    return true;
}

bool CApplicationConsole::ReadMatrix(istream &inStream, vector<vector<double>> &matrix, size_t numRows,
                                     size_t numCols) const {
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < numCols; j++) {
            double nextNum;
            if (!(inStream >> nextNum)) {
                return false;
            }
            matrix[i].push_back(nextNum);
        }
    }
    return true;
}

string CApplicationConsole::GetInput() const {
    string input;
    getline(cin, input);
    return input;
}
