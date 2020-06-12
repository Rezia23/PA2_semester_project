//
// Created by hrubate1 on 27.04.2020.
//

#include "CApplication.h"
#include "messages.h"


bool CApplication::Evaluate(string input, string &result, unique_ptr<CCommand> &command) {

    if (!ParseCommand(input, command)) {
        result = MSG_COMMAND_NOT_PARSED;
        return false;
    }
    if (!command->Execute(m_Memory)) {
        result = command->m_Result;
        return false;
    }
    result = command->m_Result;
    return true;
}

void CApplication::Run() {
    while (true) {
        string input = GetInput();
        if (input == COMMAND_EXIT) {
            ShowMsg(MSG_EXIT);
            break;
        } else if (input == COMMAND_HELP) {
            ShowHelp();
            continue;
        }
        string result;
        unique_ptr<CCommand> nextCommand;
        if (!Evaluate(input, result, nextCommand)) {
            ShowMsg(MSG_FAILED_OPERATION);
        }
        ShowResult(result);

    }
}
