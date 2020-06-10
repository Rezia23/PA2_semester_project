//
// Created by terez on 07.05.2020.
//

#include "CCommandOrder.h"

bool CCommandOrder::Execute(CMemory &memory) {
    if (!memory.ExistsVariable(m_VarName)) {
        m_Result = "Variable does not exist.";
        return false;
    }
    m_Result = "Matrix " + m_VarName + " has order:\n";

    COrderCalculator order;
    m_Order = order(memory.At(m_VarName));
    m_Result += to_string(m_Order);
    return true;

}
