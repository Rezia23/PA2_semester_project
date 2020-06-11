//
// Created by terez on 06.05.2020.
//

#include "CCommandDeterminant.h"
#include "messages.h"

bool CCommandDeterminant::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = MSG_NOT_EXISTING_VARIABLE;
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has determinant:\n";


    try {
        CDeterminantCalculator det;
        m_Determinant = det(memory.At(m_VarName));
        m_Result += to_string(m_Determinant);
        return true;
    } catch (const std::runtime_error &e) {
        m_Result = "Matrix " + m_VarName + " is not square - cannot get determinant.";
        return false;
    }

}
