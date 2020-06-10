//
// Created by terez on 19.05.2020.
//

#include "CCommandCutDestructive.h"

bool CCommandCutDestructive::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = "Variable does not exist.";
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has been cut to:\n";
    CCutOperator op(memory.At(m_VarName), m_NumRows, m_NumCols, m_StartPoint);
    try {
        memory.Insert(m_VarName, shared_ptr<CMatrix>(op.Evaluate(memory))); //replace original variable with result
        m_ResultMatrix = unique_ptr<CMatrix>(memory.At(m_VarName)->Clone());
        m_Result += m_ResultMatrix->ToString();
        return true;
    } catch (const std::runtime_error &e) {
        m_Result = "Matrix " + m_VarName + " cannot be cut.";
        return false;
    }
}
