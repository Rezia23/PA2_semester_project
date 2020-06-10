//
// Created by terez on 06.05.2020.
//

#include "CCommandInverse.h"

bool CCommandInverse::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = "Variable does not exist.";
        return false;
    }
    m_Result = "Inversion of " + m_VarName + " is:\n";

    CInverseOperator op(memory.At(m_VarName));
    try {
        m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
        m_Result += m_ResultMatrix->ToString();
        return true;
    } catch (const std::runtime_error &e) {
        m_Result = "Matrix " + m_VarName + " does not have inverse.";
        return false;
    }

}
