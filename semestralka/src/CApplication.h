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
#include "messages.h"

class CApplication {

public:
protected:
    CMemory m_Memory;

    /**
     * Shoq basic usage instructions on the screen.
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
    bool Evaluate(string input, string &result, unique_ptr<CCommand> &command) {

        if (!ParseCommand(input, command)) {
            result = "Command could not be parsed.";
            return false;
        }
        if (!command->Execute(m_Memory)) {
            result = command->m_Result;
            return false;
        }
        result = command->m_Result;
        return true;
    }

    /**
     * Run application.
     */
    void Run() {
        while (true) {
            string input = GetInput();
            if (input == COMMAND_EXIT) {
                ShowMsg("Closing the app.");
                break;
            } else if (input == COMMAND_HELP) {
                ShowHelp();
                continue;
            }
            string result;
            unique_ptr<CCommand> nextCommand;
            if (!Evaluate(input, result, nextCommand)) {
                ShowMsg("Operation failed:");
            }
            ShowResult(result);

        }
    }

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
