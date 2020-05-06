//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <sstream>
#include "CApplication.h"
#include "CMatrixSparse.h"
//#include "CCommandLoad.h"
//#include "CCommandPrint.h"
#include "CCommandAdd.h"
#include "CCommandLoad.h"
#include "CCommandPrint.h"
//#include "CCommandSubtract.h"
//#include "CCommandMultiply.h"
//#include "CCommandPut.h"
//#include "CCommandTranspose.h"
//#include "CCommandCut.h"
//#include "CCommandMergeUnder.h"
//#include "CCommandMergeNextTo.h"

using namespace std;

class CApplicationConsole : public CApplication {
public:
    CApplicationConsole() : CApplication() {};

    ~CApplicationConsole() override = default;

    void PrintInstructions() const override {
        cout << "TBD instructions how to use" << endl;
    }

private:
    string GetInput() const override;

    void ShowMsg(string msg) const override {
        cout << msg << endl;
    }

    void ShowVarName(string name) const override {
        cout << name << ":" << endl;
    }

    void ShowMatrix(unique_ptr<CMatrix> &matrix) const override {
        //to be corrected
        matrix->Print();
    }

    bool getVariableName(string &input, string &varName) const;

    bool ReadSize(std::size_t &numRows, std::size_t &numCols, istream &inStream) const;

    bool ReadMatrix(istream &inStream, vector<vector<double>> &matrix, size_t numRows, size_t numCols) const;

    bool IsSyntaxCorrect(istream &inStream) const {
        char delimiter;
        return (inStream >> delimiter) && delimiter == ';';
    }

    void ShowResult(string result) {
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

    //tbd add other commands, separate into functions
    bool ParseCommand(string &input, unique_ptr<CCommand> &nextCommand) override {
        string in_command;
        if (!ParseCommandWord(input, in_command)) {
            return false;
        }
        if (in_command == "load") {
            string varName;
            vector<vector<double>> matrixNums;
            if (!ParseLoading(input, varName, matrixNums)) {
                return false;
            }
            nextCommand = (std::make_unique<CCommandLoad>(varName, matrixNums));
        }else if (in_command == "print") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 1)) {
                return false;
            }
            stringstream inStream(input);
            if (!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (std::make_unique<CCommandPrint>(operands[0]));
        }else if (in_command == "add") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 2)) {
                return false;
            }
            stringstream inStream(input);
            if (!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (std::make_unique<CCommandAdd>(operands[0], operands[1]));
        }
//            else if (in_command == "subtract") {
//            vector<string> operands;
//            if (!ParseOperands(input, operands, 2)) {
//                return false;
//            }
//            stringstream inStream(input);
//            if (!(IsSyntaxCorrect(inStream))) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandSubtract>(operands[0], operands[1]));
//        } else if (in_command == "multiply") {
//            vector<string> operands;
//            if (!ParseOperands(input, operands, 2)) {
//                return false;
//            }
//            stringstream inStream(input);
//            if (!(IsSyntaxCorrect(inStream))) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandMultiply>(operands[0], operands[1]));
//        } else if (in_command == "put") {
//            string name;
//            if (!LoadOperandName(input, name)) {
//                return false;
//            }
//            unique_ptr<CCommand> subCommand;
//            if (!ParseCommand(input, subCommand)) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandPut>(name, subCommand));
//
//        } else if (in_command == "transpose") {
//            vector<string> operands;
//            if (!ParseOperands(input, operands, 1)) {
//                return false;
//            }
//            stringstream inStream(input);
//            if (!(IsSyntaxCorrect(inStream))) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandTranspose>(operands[0]));
//        } else if (in_command == "cut") {
//            string varName;
//            size_t numRows;
//            size_t numCols;
//            pair<size_t, size_t> startPoint;
//            if (!ParseCutting(input, varName, numRows, numCols, startPoint)) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandCut>(varName, numRows, numCols, startPoint));
//        } else if (in_command == "merge_under") {
//            vector<string> operands;
//            if (!ParseOperands(input, operands, 2)) {
//                return false;
//            }
//            stringstream inStream(input);
//            if (!(IsSyntaxCorrect(inStream))) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandMergeUnder>(operands[0], operands[1]));
//        } else if (in_command == "merge_next_to") {
//            vector<string> operands;
//            if (!ParseOperands(input, operands, 2)) {
//                return false;
//            }
//            stringstream inStream(input);
//            if (!(IsSyntaxCorrect(inStream))) {
//                return false;
//            }
//            nextCommand = (std::make_unique<CCommandMergeNextTo>(operands[0], operands[1]));
//        }

        return true;
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
