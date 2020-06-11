//
// Created by terez on 06.05.2020.
//

#include "CCutOperator.h"

CMatrix *CCutOperator::Evaluate() {
    if (m_NumRows > m_Operand->GetNumRows() || m_NumCols > m_Operand->GetNumCols()) {
        throw runtime_error("Wrong dimensions, cannot cut.");
    } else if (m_StartPoint.first > m_Operand->GetNumRows() - m_NumRows ||
               m_StartPoint.second > m_Operand->GetNumCols() - m_NumCols) {
        throw runtime_error("Wrong dimensions2, cannot cut.");
    }
    vector<vector<double>> cut(m_NumRows);
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            cut[i].push_back(m_Operand->GetNumAtCoords(i + m_StartPoint.first, j + m_StartPoint.second));
        }
    }
    if (CMatrixStandard(cut).ShouldBeSparse()) {
        return new CMatrixSparse(cut);
    }
    return new CMatrixStandard(cut);
}
