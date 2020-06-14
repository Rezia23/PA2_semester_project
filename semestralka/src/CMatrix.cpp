//
// Created by hrubate1 on 24.04.2020.
//

#include "CMatrix.h"
#include <iomanip>
#include <iostream>



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
    int width = GetCellWidth();
    stringstream ss;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            ss << setw(width) << GetNumAtCoords(i, j);
        }
        ss << '\n';
    }
    return ss.str();
}

int CMatrix::GetCellWidth() const {
    const int bigCellWidth = 14; //should be bigger or equal to 14, since double longest value has 13 digits
    const int smallCellWidth = 6;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (std::size_t j = 0; j < m_NumCols; j++) {
            int numLength = GetNumLength(i, j);
            if (numLength >= smallCellWidth) {
                return bigCellWidth;
            }
        }
    }
    return smallCellWidth;
}

int CMatrix::GetNumLength(std::size_t row, std::size_t column) const {
    string number = to_string(GetNumAtCoords(row, column));
    int length = number.length();
    std::size_t it = number.length() - 1;
    char digit = number[it];
    while (digit == '0') {
        length--;
        it--;
        digit = number[it];
    }
    return length;
}
