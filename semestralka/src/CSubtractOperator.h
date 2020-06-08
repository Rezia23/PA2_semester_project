//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CSUBTRACTOPERATOR_H
#define SEMESTRALKA_CSUBTRACTOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CSubtractOperator : public CBinaryOperator {
public:
    CSubtractOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}


    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Left->m_NumRows != m_Right->m_NumRows || m_Left->m_NumCols != m_Right->m_NumCols) {
            throw std::runtime_error("Subtracting incompatible matrices.");
        }
        vector<vector<double>> sum(m_Left->m_NumRows);
        for (size_t i = 0; i < m_Left->m_NumRows; i++) {
            for (size_t j = 0; j < m_Left->m_NumCols; j++) {
                sum[i].push_back(m_Left->GetNumAtCoords(i, j) - m_Right->GetNumAtCoords(i, j));
            }
        }
        if (CMatrixStandard(sum).ShouldBeSparse()) {
            return new CMatrixSparse(sum);
        }
        return new CMatrixStandard(sum);
    }
};


#endif //SEMESTRALKA_CSUBTRACTOPERATOR_H
