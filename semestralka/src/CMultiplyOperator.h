//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMULTIPLYOPERATOR_H
#define SEMESTRALKA_CMULTIPLYOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CMultiplyOperator : public CBinaryOperator {
public:
    CMultiplyOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Multiply variables.
     */
    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Left->GetNumCols() != m_Right->GetNumRows()) {
            throw std::runtime_error("Multiplying incompatible matrices.");
        }
        vector<vector<double>> product(m_Left->GetNumRows(), vector<double>(m_Right->GetNumCols(), 0));

        for (size_t i = 0; i < m_Left->GetNumRows(); i++) {
            for (size_t j = 0; j < m_Right->GetNumCols(); j++) {
                for (size_t k = 0; k < m_Right->GetNumRows(); k++) {
                    product[i][j] += m_Left->GetNumAtCoords(i, k) * m_Right->GetNumAtCoords(k, j);
                }
            }
        }
        if (CMatrixStandard(product).ShouldBeSparse()) {
            return new CMatrixSparse(product);
        }
        return new CMatrixStandard(product);
    }
};


#endif //SEMESTRALKA_CMULTIPLYOPERATOR_H
