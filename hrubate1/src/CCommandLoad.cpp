//
// Created by hrubate1 on 30.04.2020.
//

#include "CCommandLoad.h"

bool CCommandLoad::Execute(CMemory &memory) {
    if (memory.ExistsVariable(m_VariableName)) {
        m_Result = "Cannot create variable with same name as existing.";
        return false;
    }
    m_Result = "Matrix " + m_VariableName + " successfully loaded.\n";
    m_Result += m_ResultMatrix->ToString();
    memory.Insert(m_VariableName, move(m_ResultMatrix));
    return true;
}
