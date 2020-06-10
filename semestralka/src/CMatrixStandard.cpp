//
// Created by terez on 24.04.2020.
//

#include <iostream>
#include <exception>
#include <memory>
#include <vector>

#include "CMatrixStandard.h"

CMatrix *CMatrixStandard::Convert() const {
    size_t numRows = m_NumRows;
    size_t numCols = m_NumCols;
    map<pair<size_t, size_t>, double> matrix;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (GetNumAtCoords(i, j) != 0) {
                matrix[{i, j}] = GetNumAtCoords(i, j);
            }
        }
    }
    return new CMatrixSparse(matrix, numRows, numCols);
}

void CMatrixStandard::Print() const {
    for (auto row : m_Matrix) {
        for (size_t i = 0; i < row.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << row[i];
        }
        cout << endl;
    }
}

void CMatrixStandard::Resize(std::size_t numRows, std::size_t numCols) {
    m_NumRows = numRows;
    m_NumCols = numCols;
    m_Matrix.resize(numRows);
    for (std::size_t i = 0; i < m_NumRows; i++) {
        m_Matrix[i].resize(m_NumCols);
    }
}
