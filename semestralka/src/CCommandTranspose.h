//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDTRANSPOSE_H
#define SEMESTRALKA_CCOMMANDTRANSPOSE_H

#include "CCommand.h"

class CCommandTranspose : public CCommand {
public:
    CCommandTranspose() : CCommand() {}

    ~CCommandTranspose() override = default;

    CCommandTranspose(string varName) : m_VarName(varName) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix" + m_VarName + " has been transposed to:\n";
        (memory.m_Variables.at(m_VarName)->Transpose());
        m_ResultMatrix = unique_ptr<CMatrix>(memory.m_Variables.at(m_VarName)->Clone());
        m_Result += m_ResultMatrix->ToString();
        return true;
    }

private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDTRANSPOSE_H