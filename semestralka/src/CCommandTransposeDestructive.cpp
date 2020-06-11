//
// Created by terez on 19.05.2020.
//

#include "CCommandTransposeDestructive.h"
#include "messages.h"

bool CCommandTransposeDestructive::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = MSG_NOT_EXISTING_VARIABLE;
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has been transposed to:\n";

    CTransposeOperator op(memory.At(m_VarName));

    memory.Insert(m_VarName, shared_ptr<CMatrix>(op.Evaluate(memory))); //replace original variable with result
    m_ResultMatrix = unique_ptr<CMatrix>(memory.At(m_VarName)->Clone());
    m_Result += m_ResultMatrix->ToString();
    return true;
}
