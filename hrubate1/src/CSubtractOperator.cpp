//
// Created by terez on 06.05.2020.
//

#include "CSubtractOperator.h"

CMatrix *CSubtractOperator::Evaluate() {
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
