//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMERGEUNDEROPERATOR_H
#define SEMESTRALKA_CMERGEUNDEROPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CMergeUnderOperator : public CBinaryOperator {
public:
    CMergeUnderOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Combine two variables into a new one. Variables are combined by placing one below the other.
     */
    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Left->GetNumCols() != m_Right->GetNumCols()) {
            throw std::runtime_error("Merging incompatible matrices.");
        }
        vector<vector<double>> merged(m_Left->GetNumRows() + m_Right->GetNumRows());
        for (size_t i = 0; i < m_Left->GetNumRows() + m_Right->GetNumRows(); i++) {
            for (size_t j = 0; j < m_Left->GetNumCols(); j++) {
                double nextNum;
                if (i < m_Left->GetNumRows()) {
                    nextNum = m_Left->GetNumAtCoords(i, j);
                } else {
                    nextNum = m_Right->GetNumAtCoords(i - m_Left->GetNumRows(), j);
                }
                merged[i].push_back(nextNum);
            }
        }
        if (CMatrixStandard(merged).ShouldBeSparse()) {
            return new CMatrixSparse(merged);
        }
        return new CMatrixStandard(merged);
    }


};

#endif //SEMESTRALKA_CMERGEUNDEROPERATOR_H
