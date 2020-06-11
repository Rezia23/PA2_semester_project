//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <memory>
#include <sstream>
#include <iomanip>
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

    void ShowHelp() const override {
        for (std::size_t i = 0; i < HELP.size(); i++) {
            cout << HELP[i][0] << setw(120 - HELP[i][0].size()) << HELP[i][1] << "         " << HELP[i][2] << endl;
        }
    }

    /**
     * Read name of a variable from input.
     * @param input input data
     * @param varName name of variable
     * @return true if variable name read successfully, false otherwise (incorrect syntax)
     */
    bool getVariableName(string &input, string &varName) const;
    /**
     * Read size of result matrix from input.
     * @param numRows number of rows
     * @param numCols number of columns
     * @param inStream input stream
     * @return true if read successfully, false otherwise (incorrect syntax)
     */
    bool ReadSize(std::size_t &numRows, std::size_t &numCols, istream &inStream) const;
    /**
     * Read and set values of a matrix from a stream.
     * @param inStream input stream
     * @param matrix values of matrix to be set
     * @param numRows number of rows of the matrix
     * @param numCols number of columns of the matrix
     * @return true if read successfully, false otherwise (wrong number of values)
     */
    bool ReadMatrix(istream &inStream, vector<vector<double>> &matrix, size_t numRows, size_t numCols) const;
    /**
     * Check if command is properly ended.
     * @param inStream input stream
     * @return true if properly ended
     */
    bool IsSyntaxCorrect(istream &inStream) const {
        char delimiter;
        return (inStream >> delimiter) && delimiter == DELIMITER_END_COMMAND;
    }

    void ShowResult(string result) const override {
        cout << result << endl;
    }
    /**
     * Parse name of the command from input.
     * @param input input data
     * @param in_command name of the command
     * @return true if parsed successfully, false otherwise (incorrect syntax)
     */
    bool ParseCommandWord(string &input, string &in_command);

    bool ParseCommand(string &input, unique_ptr<CCommand> &command) override;

    /**
     * Load name of operand variable.
     * @param input input data
     * @param name variable name
     * @return true if loaded successfully, false otherwise (incorrect syntax)
     */
    static bool LoadOperandName(string &input, string &name);
    /**
     * Parse parameters for loading of a matrix.
     * @param input input data
     * @param varName name of variable to be loaded
     * @param matrixNums values of a loaded matrix
     * @return true if successful, false otherwise (incorrect syntax)
     */
    bool ParseLoading(string &input, string &varName, vector<vector<double>> &matrixNums);
    /**
     * Parse operand variable names.
     * @param input input data
     * @param operands vector to store operands
     * @param numOfOperands number of operands to parse
     * @return true if successfull, false otherwise (incorrect syntax)
     */
    static bool ParseOperands(string &input, vector<string> &operands, std::size_t numOfOperands = 1);
    /**
     * Parse parameters for cutting of a matrix.
     * @param input input data
     * @param varName input variable name
     * @param numRows number of rows of the cut matrix
     * @param numCols number of columns of the cut matrix
     * @param startPoint row and column index where to start cutting
     * @return true if successful, false otherwise (incorrect syntax)
     */
    bool ParseCutting(string &input, string &varName, std::size_t &numRows, size_t &numCols,
                      pair<size_t, size_t> &startPoint);


};


#endif //SEMESTRALKA_CAPPLICATIONCONSOLE_H
