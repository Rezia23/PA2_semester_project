//
// Created by hrubate1 on 30.04.2020.
//

#include "CCommandSubtract.h"

bool CCommandSubtract::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_Operand1) || !memory.ExistsVariable(m_Operand2)) {
        m_Result = "Variables do not exist.";
        return false;
    }
    m_Result = "Result of subtraction is:\n";
    CSubtractOperator op(memory.At(m_Operand1), memory.At(m_Operand2));
    try {
        m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate());
        m_Result += m_ResultMatrix->ToString();
        return true;
    } catch (const std::runtime_error &e) {
        m_Result = "Matrices " + m_Operand1 + " and " + m_Operand2 + " are not compatible for subtraction.";
        return false;
    }
}
