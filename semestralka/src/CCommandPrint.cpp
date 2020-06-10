//
// Created by terez on 30.04.2020.
//

#include "CCommandPrint.h"

bool CCommandPrint::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VariableName)) {
        m_Result = "Variable " + m_VariableName + " does not exist.";
        return false;
    }
    m_Result = memory.At(m_VariableName)->ToString();
    return true;
}
