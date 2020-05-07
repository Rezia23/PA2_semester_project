//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDINVERSE_H
#define SEMESTRALKA_CCOMMANDINVERSE_H


#include "CCommand.h"
#include "CInverseOperator.h"

class CCommandInverse : public CCommand {
public:
    CCommandInverse() : CCommand() {}

    ~CCommandInverse() override = default;

    CCommandInverse(string varName) : m_VarName(varName) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Inversion of " + m_VarName + " is:\n";

        CInverseOperator op (memory.m_Variables.at(m_VarName));
        try{
            m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
            m_Result += m_ResultMatrix->ToString();
            return true;
        }catch(const std::runtime_error& e){
            m_Result = "Matrix " + m_VarName  + " is not square - cannot find inverse.";
            return false;
        }

    }

private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDINVERSE_H
