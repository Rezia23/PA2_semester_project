//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDPUT_H
#define SEMESTRALKA_CCOMMANDPUT_H

#include "CCommand.h"
#include "CMatrixStandard.h"

class CCommandPut : public CCommand {
public:
    CCommandPut() : CCommand() {}

    ~CCommandPut() override = default;

    CCommandPut(string varName, unique_ptr<CCommand> &subCommand) : m_VariableName(varName),
                                                                    m_Subcommand(move(subCommand)) {}

    bool Execute(CMemory & memory) override {
        if(!memory.ExistsVariable(m_VariableName)){
            memory.m_Variables.insert(make_pair(m_VariableName, unique_ptr<CMatrix> (new CMatrixStandard())));
        }
        if (!m_Subcommand->Execute(memory)) {
            return false;
        }
        m_Result = "To matrix " + m_VariableName + " has been put:\n";
        m_Result += m_Subcommand->m_ResultMatrix->ToString();
        memory.Insert(m_VariableName, move(m_Subcommand->m_ResultMatrix));
        return true;
    }

private:
    string m_VariableName;
    unique_ptr<CCommand> m_Subcommand;
};


#endif //SEMESTRALKA_CCOMMANDPUT_H
