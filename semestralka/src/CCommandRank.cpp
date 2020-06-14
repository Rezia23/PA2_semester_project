//
// Created by hrubate1 on 07.05.2020.
//

#include "CCommandRank.h"
#include "messages.h"

bool CCommandRank::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = MSG_NOT_EXISTING_VARIABLE;
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has rank:\n";

    CRankCalculator rank;
    m_Rank = rank(memory.At(m_VarName));
    m_Result += to_string(m_Rank);
    return true;

}
