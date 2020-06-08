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

    CMatrix *Evaluate(CMemory &memory) override {
        CMatrix *transposed = m_Operand->GetEmptyInstance();
        transposed->Resize(m_Operand->m_NumCols, m_Operand->m_NumRows);
        for (size_t i = 0; i < transposed->m_NumRows; i++) {
            for (size_t j = 0; j < transposed->m_NumCols; j++) {
                transposed->SetNumAtCoords(i, j, m_Operand->GetNumAtCoords(j, i));
            }
        }
        return transposed;
    }

};


#endif //SEMESTRALKA_CTRANSPOSEOPERATOR_H
