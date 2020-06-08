//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <memory>
#include <sstream>
#include "CApplication.h"
#include "CMatrixSparse.h"
#include "CCommandLoad.h"
#include "CCommandPrint.h"
#include "CCommandAdd.h"
#include "CCommandSubtract.h"
#include "CCommandMultiply.h"
#include "CCommandTranspose.h"
#include "CCommandPut.h"
#include "CCommandMergeUnder.h"
#include "CCommandMergeNextTo.h"
#include "CCommandCut.h"
#include "CCommandInverse.h"
#include "CCommandDeterminant.h"
#include "CCommandGaussEliminationDestructive.h"
#include "CCommandOrder.h"
#include "messages.h"
#include "CCommandGaussElimination.h"
#include "CCommandTransposeDestructive.h"
#include "CCommandCutDestructive.h"


using namespace std;

class CApplicationConsole : public CApplication {
public:
    CApplicationConsole() : CApplication() {};

    ~CApplicationConsole() override = default;

    void PrintInstructions() const override {
        cout << USAGE_INSTRUCTIONS << endl;
    }

private:
    string GetInput() const override;

    void ShowMsg(string msg) const override {
        cout << msg << endl;
    }


    bool getVariableName(string &input, string &varName) const;

    bool ReadSize(std::size_t &numRows, std::size_t &numCols, istream &inStream) const;

    bool ReadMatrix(istream &inStream, vector<vector<double>> &matrix, size_t numRows, size_t numCols) const;

    bool IsSyntaxCorrect(istream &inStream) const {
        char delimiter;
        return (inStream >> delimiter) && delimiter == ';';
    }

    void ShowResult(string result) const override {
        cout << result << endl;
    }

    bool ParseCommandWord(string &input, string &in_command) {

        std::string::size_type semicolonPosition;
        semicolonPosition = input.find(":");
        if (semicolonPosition == std::string::npos) {
            return false;
        }
        in_command = input.substr(0, semicolonPosition);
        input = input.substr(semicolonPosition + 1);
        return true;
    }

    //todo add other commands, separate into functions
    bool ParseCommand(string &input, unique_ptr<CCommand> &nextCommand) override {
        string in_command;
        if (!ParseCommandWord(input, in_command)) {
            return false;
        }
        if (in_command == COMMAND_LOAD) {
            string varName;
            vector<vector<double>> matrixNums;
            if (!ParseLoading(input, varName, matrixNums)) {
                return false;
            }
            nextCommand = (std::make_unique<CCommandLoad>(varName, matrixNums));
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
            nextCommand = (std::make_unique<CCommandPrint>(operands[0]));
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
            nextCommand = (std::make_unique<CCommandAdd>(operands[0], operands[1]));
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
            nextCommand = (std::make_unique<CCommandSubtract>(operands[0], operands[1]));
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
            nextCommand = (std::make_unique<CCommandMultiply>(operands[0], operands[1]));
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
            nextCommand = (std::make_unique<CCommandPut>(name, subCommand));
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
                nextCommand = (std::make_unique<CCommandTranspose>(operands[0]));
            } else {
                nextCommand = (std::make_unique<CCommandTransposeDestructive>(operands[0]));
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
                nextCommand = (std::make_unique<CCommandCut>(varName, numRows, numCols, startPoint));
            } else {
                nextCommand = (std::make_unique<CCommandCutDestructive>(varName, numRows, numCols, startPoint));
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
            nextCommand = (std::make_unique<CCommandMergeUnder>(operands[0], operands[1]));
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
            nextCommand = (std::make_unique<CCommandMergeNextTo>(operands[0], operands[1]));
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
            nextCommand = (std::make_unique<CCommandInverse>(operands[0]));
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
            nextCommand = (std::make_unique<CCommandDeterminant>(operands[0]));
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
                nextCommand = (std::make_unique<CCommandGaussElimination>(operands[0]));
            } else {
                nextCommand = (std::make_unique<CCommandGaussEliminationDestructive>(operands[0]));
            }

            return true;
        } else if (in_command == COMMAND_ORDER) {
            vector<string> operands;
            if (!ParseOperands(input, operands, 1)) {
                return false;
            }
            stringstream inStream(input);
            if (!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (std::make_unique<CCommandOrder>(operands[0]));
            return true;
        }

        return false;
    }

    bool LoadOperandName(string &input, string &name) {
        std::string::size_type spacePosition;
        spacePosition = input.find(" ");
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

    bool ParseLoading(string &input, string &varName, vector<vector<double>> &matrixNums) {
        if (!getVariableName(input, varName)) {
            return false;
        }
        stringstream inStream(input);
        size_t numRows;
        size_t numCols;
        if (!ReadSize(numRows, numCols, inStream)) {
            return false;
        }
        matrixNums.resize(numRows);
        if (!ReadMatrix(inStream, matrixNums, numRows, numCols)) {
            return false;
        }
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        return true;
    }

    bool ParseOperands(string &input, vector<string> &operands, std::size_t numOfOperands = 1) {
        for (size_t i = 0; i < numOfOperands; i++) {
            string name;
            if (!LoadOperandName(input, name)) {
                return false;
            }
            operands.push_back(name);
        }
        return true;
    }

    bool ParseCutting(string &input, string &varName, std::size_t &numRows, size_t &numCols,
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
        if (!(IsSyntaxCorrect(inStream))) {
            return false;
        }
        return true;
    }


};


#endif //SEMESTRALKA_CAPPLICATIONCONSOLE_H
