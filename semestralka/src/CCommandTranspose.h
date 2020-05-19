//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDTRANSPOSE_H
#define SEMESTRALKA_CCOMMANDTRANSPOSE_H

#include "CCommandGetMatrix.h"
#include "CTransposeOperator.h"

class CCommandTranspose : public CCommandGetMatrix {
public:
    CCommandTranspose() = default;

    ~CCommandTranspose() override = default;

    CCommandTranspose(string varName) : m_VarName(varName) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " would be transposed to:\n";
        shared_ptr<CMatrix> result = shared_ptr<CMatrix>(memory.At(m_VarName)->Clone());
        CTransposeOperator op (result);

        m_ResultMatrix = (unique_ptr<CMatrix>(op.Evaluate(memory)));
        m_Result += m_ResultMatrix->ToString();
        return true;
    }

protected:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDTRANSPOSE_H
