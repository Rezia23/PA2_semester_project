//
// Created by terez on 24.04.2020.
//

#include "CMatrix.h"


bool CMatrix::operator==(const CMatrix &other) {
    if (m_NumRows != other.m_NumRows || m_NumCols != other.m_NumCols) {
        return false;
    }
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (GetNumAtCoords(i, j) != other.GetNumAtCoords(i, j)) {
                return false;
            }
        }
    }
    return true;
}

string CMatrix::ToString() const {
    string result;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (j != 0) {
                result += " ";
            }
            result += to_string(GetNumAtCoords(i, j));
        }
        result += "\n";
    }
    return result;
}
