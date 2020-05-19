//
// Created by terez on 19.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H
#define SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H

#include "CCommandTranspose.h"

class CCommandTransposeDestructive:public CCommandTranspose {
public:
    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has been transposed to:\n";

        CTransposeOperator op (memory.At(m_VarName));

        memory.Insert(m_VarName, shared_ptr<CMatrix>(op.Evaluate(memory)));
        m_ResultMatrix = unique_ptr<CMatrix>(memory.At(m_VarName)->Clone());
        m_Result += m_ResultMatrix->ToString();
        return true;
    }
    CCommandTransposeDestructive(string varName):CCommandTranspose(varName){}

};


#endif //SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H
