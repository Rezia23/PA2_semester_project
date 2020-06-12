//
// Created by terez on 07.05.2020.
//

#include "CCommandGaussEliminationDestructive.h"
#include "messages.h"

bool CCommandGaussEliminationDestructive::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = MSG_NOT_EXISTING_VARIABLE;
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has been eliminated in these steps:";

    CGaussEliminationOperator op(memory.m_Variables.at(m_VarName));
    memory.Insert(m_VarName, shared_ptr<CMatrix>(op.Evaluate())); //replace original variable with result
    m_ResultMatrix = unique_ptr<CMatrix>(memory.At(m_VarName)->Clone());

    vector<shared_ptr<CMatrix>> eliminationProcess = op.GetEliminationProcess();
    for (std::size_t i = 0; i < eliminationProcess.size(); i++) {
        m_Result += "\n" + eliminationProcess[i]->ToString();
    }
    return true;
}
