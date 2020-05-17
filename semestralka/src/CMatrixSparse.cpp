//
// Created by terez on 24.04.2020.
//
#include <vector>
#include "CMatrixSparse.h"


using namespace std;

CMatrix *CMatrixSparse::Convert() const {
    vector<vector<double>> matrix(m_NumRows);
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            matrix[i].push_back(GetNumAtCoords(i, j));
        }
    }
    return new CMatrixStandard(matrix);
}


void CMatrixSparse::Print() const {
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (j != 0) {
                cout << " ";
            }
            if (m_Matrix.find({i, j}) == m_Matrix.end()) {
                cout << 0;
            } else {
                cout << m_Matrix.at(make_pair(i, j));
            }
        }
        cout << endl;
    }
}

double CMatrixSparse::GetNumAtCoords(size_t row, size_t col) const {
    if (m_Matrix.find({row, col}) == m_Matrix.end()) {
        return 0;
    } else {
        return m_Matrix.at({row, col});
    }
}


