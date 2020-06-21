//
// Created by hrubate1 on 27.04.2020.
//

#include "CApplicationConsole.h"
#include <iostream>
#include <string>
#include <vector>
#include "messages.h"

using namespace std;

bool CApplicationConsole::getVariableName(string &input, string &varName) const {
    std::string::size_type spacePosition;
    spacePosition = input.find(DELIMITER_PARAMETERS);
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
    int rows, cols;
    if (!(inStream >> rows) || !(inStream >> cols)) {
        return false;
    }
    if (rows <= 0 || cols <= 0) {
        return false;
    }
    numRows = rows;
    numCols = cols;
    char delimiter;
    return ((inStream >> delimiter) && delimiter == DELIMITER_MATRIX_SIZE);
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

bool CApplicationConsole::ParseCommandWord(string &input, string &in_command) {

    std::string::size_type semicolonPosition;
    semicolonPosition = input.find(DELIMITER_COMMAND_WORD);
    if (semicolonPosition == std::string::npos) {
        return false;
    }
    in_command = input.substr(0, semicolonPosition);
    input = input.substr(semicolonPosition + 1);
    return true;
}

bool CApplicationConsole::ParseCommand(string &input, unique_ptr<CCommand> &command) {
    string in_command;
    if (!ParseCommandWord(input, in_command)) {
        return false;
    }
    //go to branch according to particular commands, parse their parameters
    if (in_command == COMMAND_LOAD) {
        string varName;
        vector<vector<double>> matrixNums;
        if (!ParseLoading(input, varName, matrixNums)) {
            return false;
        }
        command = (std::make_unique<CCommandLoad>(varName, matrixNums));
        return true;
    } else if (in_command == COMMAND_PRINT) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandPrint>(operands[0]));
        return true;
    } else if (in_command == COMMAND_ADD) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 2)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandAdd>(operands[0], operands[1]));
        return true;
    } else if (in_command == COMMAND_SUBTRACT) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 2)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandSubtract>(operands[0], operands[1]));
        return true;
    } else if (in_command == COMMAND_MULTIPLY) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 2)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandMultiply>(operands[0], operands[1]));
        return true;
    } else if (in_command == COMMAND_PUT) {
        string name;
        if (!LoadOperandName(input, name)) {
            return false;
        }
        unique_ptr<CCommand> subCommand;
        if (!ParseCommand(input, subCommand)) {
            return false;
        }
        command = (std::make_unique<CCommandPut>(name, subCommand));
        return true;
    } else if (in_command == COMMAND_TRANSPOSE || in_command == COMMAND_TRANSPOSE_DESTRUCTIVE) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        if (in_command == COMMAND_TRANSPOSE) {
            command = (std::make_unique<CCommandTranspose>(operands[0]));
        } else {
            command = (std::make_unique<CCommandTransposeDestructive>(operands[0]));
        }

        return true;
    } else if (in_command == COMMAND_CUT || in_command == COMMAND_CUT_DESTRUCTIVE) {
        string varName;
        size_t numRows;
        size_t numCols;
        pair<size_t, size_t> startPoint;
        if (!ParseCutting(input, varName, numRows, numCols, startPoint)) {
            return false;
        }
        if (in_command == COMMAND_CUT) {
            command = (std::make_unique<CCommandCut>(varName, numRows, numCols, startPoint));
        } else {
            command = (std::make_unique<CCommandCutDestructive>(varName, numRows, numCols, startPoint));
        }
        return true;
    } else if (in_command == COMMAND_MERGE_UNDER) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 2)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandMergeUnder>(operands[0], operands[1]));
        return true;
    } else if (in_command == COMMAND_MERGE_NEXT_TO) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 2)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandMergeNextTo>(operands[0], operands[1]));
        return true;
    } else if (in_command == COMMAND_INVERSE) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandInverse>(operands[0]));
        return true;
    } else if (in_command == COMMAND_DETERMINANT) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandDeterminant>(operands[0]));
        return true;
    } else if (in_command == COMMAND_GAUSS_ELIMINATION || in_command == COMMAND_GAUSS_ELIMINATION_DESTRUCTIVE) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        if (in_command == COMMAND_GAUSS_ELIMINATION) {
            command = (std::make_unique<CCommandGaussElimination>(operands[0]));
        } else {
            command = (std::make_unique<CCommandGaussEliminationDestructive>(operands[0]));
        }

        return true;
    } else if (in_command == COMMAND_RANK) {
        vector<string> operands;
        if (!ParseOperands(input, operands, 1)) {
            return false;
        }
        stringstream inStream(input);
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        command = (std::make_unique<CCommandRank>(operands[0]));
        return true;
    }
    return false;
}

bool CApplicationConsole::LoadOperandName(string &input, string &name) {
    std::string::size_type spacePosition;
    spacePosition = input.find(DELIMITER_PARAMETERS);
    if (spacePosition == std::string::npos) {
        return false;
    }
    name = input.substr(0, spacePosition);
    if (name == "") {
        return false;
    }
    input = input.substr(spacePosition + 1);
    return true;
}

bool CApplicationConsole::ParseLoading(string &input, string &varName, vector<vector<double>> &matrixNums) {
    if (!getVariableName(input, varName)) {
        return false;
    }
    stringstream inStream(input);
    size_t numRows;
    size_t numCols;
    if (!ReadSize(numRows, numCols, inStream)) {
        return false;
    }
    if (matrixNums.max_size() < numRows) {
        return false;
    }
    matrixNums.resize(numRows);
    if (matrixNums[0].max_size() < numCols) {
        return false;
    }
    if (!ReadMatrix(inStream, matrixNums, numRows, numCols)) {
        return false;
    }
    if (!(IsSyntaxCorrect(inStream))) {
        return false;
    }
    return true;
}

bool CApplicationConsole::ParseOperands(string &input, vector<string> &operands, std::size_t numOfOperands) {
    for (size_t i = 0; i < numOfOperands; i++) {
        string name;
        if (!LoadOperandName(input, name)) {
            return false;
        }
        operands.push_back(name);
    }
    return true;
}

bool CApplicationConsole::ParseCutting(string &input, string &varName, size_t &numRows, size_t &numCols,
                                       pair<size_t, size_t> &startPoint) {
    if (!getVariableName(input, varName)) {
        return false;
    }
    stringstream inStream(input);
    if (!ReadSize(numRows, numCols, inStream)) {
        return false;
    }
    if (!(inStream >> startPoint.first) || !(inStream >> startPoint.second)) {
        return false;
    }
    return IsSyntaxCorrect(inStream);
}
