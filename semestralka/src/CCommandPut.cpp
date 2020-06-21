//
// Created by hrubate1 on 30.04.2020.
//

#include "CCommandPut.h"

bool CCommandPut::Execute(CMemory &memory) {
    //checking for existence of a variable  unusually after executing subcommand, so only when command is valid,
    // new variable is created (if not already existing)

    if (!m_Subcommand->Execute(memory)) {
        return false;
    }
    if (m_Subcommand->m_ResultMatrix == nullptr) {
        m_Result = "Could not put such value to " + m_VariableName;
        return false;
    }

    if (!memory.ExistsVariable(m_VariableName)) {
        memory.m_Variables.insert(make_pair(m_VariableName, unique_ptr<CMatrix>(new CMatrixStandard())));
    }

    m_Result = "To matrix " + m_VariableName + " has been put:\n";
    m_Result += m_Subcommand->m_ResultMatrix->ToString();
    memory.Insert(m_VariableName, move(m_Subcommand->m_ResultMatrix));
    return true;
}
