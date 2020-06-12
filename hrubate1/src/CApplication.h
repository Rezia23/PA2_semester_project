//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATION_H
#define SEMESTRALKA_CAPPLICATION_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <sstream>
#include "CMatrix.h"
#include "CMatrixStandard.h"
#include "CCommand.h"
#include "CMemory.h"

class CApplication {

protected:
    CMemory m_Memory;

    /**
     * Show basic usage instructions on the screen.
     */
    virtual void PrintInstructions() const = 0;

    /**
     * Get input from user.
     * @return input data in string
     */
    virtual string GetInput() const = 0;

    /**
     * Parse input data into commands.
     * @param input input data
     * @param command parsed command
     * @return true if command successfully parsed, false otherwise
     */
    virtual bool ParseCommand(string &input, unique_ptr<CCommand> &command) = 0;

    /**
     * Show result of operation on screen.
     * @param result result of operation
     */
    virtual void ShowResult(string result) const = 0;


public:


    CApplication() = default;

    virtual ~CApplication() = default;

    /**
     * Evaluate input from user.
     * @param input input data
     * @param result string representation of result of operation
     * @param command command to be parsed
     * @return true if evaluation successful, false otherwise
     */
    bool Evaluate(string input, string &result, unique_ptr<CCommand> &command);

    /**
     * Run application.
     */
    void Run();

    /**
     * Show message on the screen.
     * @param msg message to be shown
     */
    virtual void ShowMsg(string msg) const = 0;

    /**
     * Show description of app commands on the screen.
     */
    virtual void ShowHelp() const = 0;

};


#endif //SEMESTRALKA_CAPPLICATION_H
