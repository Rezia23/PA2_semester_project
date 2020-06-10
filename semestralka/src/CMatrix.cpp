//
// Created by terez on 24.04.2020.
//

#include "CMatrix.h"
#include <sstream>
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
    int width = SetCellWidth();
    stringstream ss;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            ss<<setw(width)<<GetNumAtCoords(i,j);
        }
        ss<<'\n';
    }
    return ss.str();
}

int CMatrix::SetCellWidth() const {
    for(size_t i = 0;i<m_NumRows;i++){
        for(std::size_t j = 0; j<m_NumCols;j++){
            int numLength = GetNumLength(i,j);
            if(numLength>=5){
                return 14;
            }
        }
    }
    return 6;
}

int CMatrix::GetNumLength(std::size_t row, std::size_t column) const {
    string number = to_string(GetNumAtCoords(row,column));
    int length = number.length();
    std::size_t it = number.length()-1;
    char digit = number[it];
    while(digit=='0'){
        length--;
        it--;
        digit=number[it];
    }
    return length;
}
