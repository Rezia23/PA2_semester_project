//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDADD_H
#define SEMESTRALKA_CCOMMANDADD_H

#include "CCommand.h"

class CCommandAdd : public CCommand {
public:
    CCommandAdd() : CCommand() {}

    ~CCommandAdd() override = default;

    CCommandAdd(string operand1, string operand2) : m_Operand1(operand1), m_Operand2(operand2) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_Operand1) || !memory.ExistsVariable(m_Operand2)) {
            m_Result = "Variables do not exist.";
            return false;
        }
        m_Result = "Result of addition is:\n";
        m_ResultMatrix = unique_ptr<CMatrix>(memory.m_Variables.at(m_Operand1)->Add(memory.m_Variables.at(m_Operand2)));
        m_Result += m_ResultMatrix->ToString();
        return true;
    }

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDADD_H
