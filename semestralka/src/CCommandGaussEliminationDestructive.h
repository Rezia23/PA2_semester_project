//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H
#define SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H


#include "CCommandGaussElimination.h"


class CCommandGaussEliminationDestructive : public CCommandGaussElimination {
public:
    bool Execute(CMemory &memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has been eliminated in these steps:";

        CGaussEliminationOperator op(memory.m_Variables.at(m_VarName));
        memory.Insert(m_VarName, shared_ptr<CMatrix>(op.Evaluate(memory)));
        m_ResultMatrix = unique_ptr<CMatrix>(memory.At(m_VarName)->Clone());

        vector<shared_ptr<CMatrix>> eliminationProcess = op.GetEliminationProcess();
        for (std::size_t i = 0; i < eliminationProcess.size(); i++) {
            m_Result += "\n" + eliminationProcess[i]->ToString();
        }
        return true;
    }

    CCommandGaussEliminationDestructive(string varName) : CCommandGaussElimination(varName) {}


};


#endif //SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H
