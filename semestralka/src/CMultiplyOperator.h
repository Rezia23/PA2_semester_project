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


    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Left->m_NumCols != m_Right->m_NumRows) {
            throw std::runtime_error("Multiplying incompatible matrices.");
        }
        vector<vector<double>> product(m_Left->m_NumRows, vector<double>(m_Right->m_NumCols, 0));

        for (size_t i = 0; i < m_Left->m_NumRows; i++) {
            for (size_t j = 0; j < m_Right->m_NumCols; j++) {
                for (size_t k = 0; k < m_Right->m_NumRows; k++) {
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
