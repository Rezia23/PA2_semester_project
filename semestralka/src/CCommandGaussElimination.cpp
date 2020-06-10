//
// Created by terez on 19.05.2020.
//

#include "CCommandGaussElimination.h"

bool CCommandGaussElimination::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = "Variable does not exist.";
        return false;
    }
    m_Result = "Matrix " + m_VarName + " would be eliminated in these steps:";
    shared_ptr<CMatrix> result = shared_ptr<CMatrix>(memory.m_Variables.at(m_VarName)->Clone());
    CGaussEliminationOperator op(result);
    m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
    vector<shared_ptr<CMatrix>> eliminationProcess = op.GetEliminationProcess();
    for (std::size_t i = 0; i < eliminationProcess.size(); i++) {
        m_Result += "\n" + eliminationProcess[i]->ToString();
    }
    return true;
}
