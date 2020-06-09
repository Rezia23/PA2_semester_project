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

    virtual void PrintInstructions() const = 0;

    virtual string GetInput() const = 0;

    virtual bool ParseCommand(string &input, unique_ptr<CCommand> &nextCommand) = 0;

    virtual void ShowResult(string result) const = 0;


public:


    CApplication() = default;

    virtual ~CApplication() = default;


    bool Evaluate(string input, string &result, unique_ptr<CCommand> &nextCommand) {

        if (!ParseCommand(input, nextCommand)) {
            result = "Command could not be parsed.";
            return false;
        }
        if (!nextCommand->Execute(m_Memory)) {
            result = nextCommand->m_Result;
            return false;
        }
        result = nextCommand->m_Result;
        return true;
    }

    void Run() {
        while (true) {
            string input = GetInput();
            if (input == COMMAND_EXIT) {
                ShowMsg("Closing the app.");
                break;
            } else if (input==COMMAND_HELP){
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


    virtual void ShowMsg(string msg) const = 0;
    virtual void ShowHelp() const = 0;


    //todo fix
//    void ShowVariables() const {
//        if (m_Variables.size() == 0) {
//            ShowMsg("No variables to be shown.");
//        }
//        for (auto a = m_Variables.begin(); a != m_Variables.end(); a++) {
//            ShowVarName(a->first);
//            //getstring representation
//            //show
//            a->second->Print();
//        }
//    }
};


#endif //SEMESTRALKA_CAPPLICATION_H
