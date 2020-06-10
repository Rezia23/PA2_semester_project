//
// Created by terez on 30.04.2020.
//

#include "CCommandCut.h"

bool CCommandCut::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = "Variable does not exist.";
        return false;
    }
    m_Result = "Matrix " + m_VarName + " would be cut to:\n";
    shared_ptr<CMatrix> result = shared_ptr<CMatrix>(memory.At(m_VarName)->Clone());
    CCutOperator op(result, m_NumRows, m_NumCols, m_StartPoint);
    try {
        m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
        m_Result += m_ResultMatrix->ToString();
        return true;
    } catch (const std::runtime_error &e) {
        m_Result = "Matrix " + m_VarName + " cannot be cut.";
        return false;
    }
}
