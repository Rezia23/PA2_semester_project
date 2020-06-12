//
// Created by hrubate1 on 06.05.2020.
//

#include "CTransposeOperator.h"

CMatrix *CTransposeOperator::Evaluate() {
    CMatrix *transposed = m_Operand->GetEmptyInstance();
    transposed->Resize(m_Operand->GetNumCols(), m_Operand->GetNumRows());
    for (size_t i = 0; i < transposed->GetNumRows(); i++) {
        for (size_t j = 0; j < transposed->GetNumCols(); j++) {
            transposed->SetNumAtCoords(i, j, m_Operand->GetNumAtCoords(j, i));
        }
    }
    return transposed;
}
