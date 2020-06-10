//
// Created by terez on 06.05.2020.
//

#include "CMergeNextToOperator.h"

CMatrix *CMergeNextToOperator::Evaluate(CMemory &memory) {
    if (m_Left->GetNumRows() != m_Right->GetNumRows()) {
        throw std::runtime_error("Merging incompatible matrices.");
    }
    vector<vector<double>> merged(m_Left->GetNumRows());
    for (size_t i = 0; i < m_Left->GetNumRows(); i++) {
        for (size_t j = 0; j < m_Left->GetNumCols() + m_Right->GetNumCols(); j++) {
            double nextNum;
            if (j < m_Left->GetNumCols()) {
                nextNum = m_Left->GetNumAtCoords(i, j);
            } else {
                nextNum = m_Right->GetNumAtCoords(i, j - m_Left->GetNumCols());
            }
            merged[i].push_back(nextNum);
        }
    }
    if (CMatrixStandard(merged).ShouldBeSparse()) {
        return new CMatrixSparse(merged);
    }
    return new CMatrixStandard(merged);
}
