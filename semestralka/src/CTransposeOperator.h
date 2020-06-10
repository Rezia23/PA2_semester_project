//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CTRANSPOSEOPERATOR_H
#define SEMESTRALKA_CTRANSPOSEOPERATOR_H

#include "CUnaryOperator.h"
#include "CMatrixStandard.h"

class CTransposeOperator : public CUnaryOperator {
public:
    CTransposeOperator(shared_ptr<CMatrix> &operand)
            : CUnaryOperator(operand) {}

    /**
     * Perform matrix transposition on a variable.
     */
    CMatrix *Evaluate(CMemory &memory) override {
        CMatrix *transposed = m_Operand->GetEmptyInstance();
        transposed->Resize(m_Operand->GetNumCols(), m_Operand->GetNumRows());
        for (size_t i = 0; i < transposed->GetNumRows(); i++) {
            for (size_t j = 0; j < transposed->GetNumCols(); j++) {
                transposed->SetNumAtCoords(i, j, m_Operand->GetNumAtCoords(j, i));
            }
        }
        return transposed;
    }

};


#endif //SEMESTRALKA_CTRANSPOSEOPERATOR_H
