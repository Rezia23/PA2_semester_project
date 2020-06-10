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

    /**
     * Subtract two variables.
     */
    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Left->GetNumRows() != m_Right->GetNumRows() || m_Left->GetNumCols() != m_Right->GetNumCols()) {
            throw std::runtime_error("Subtracting incompatible matrices.");
        }
        vector<vector<double>> sum(m_Left->GetNumRows());
        for (size_t i = 0; i < m_Left->GetNumRows(); i++) {
            for (size_t j = 0; j < m_Left->GetNumCols(); j++) {
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
