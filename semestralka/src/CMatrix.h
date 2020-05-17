//
// Created by terez on 24.04.2020.
//

#ifndef SEMESTRALKA_CMATRIX_H
#define SEMESTRALKA_CMATRIX_H


#include <glob.h>
#include <memory>
#include <vector>
#include "COperator.h"


using namespace std;

class CMatrix{

public:
    size_t m_NumRows = 0;
    size_t m_NumCols = 0;


    CMatrix() = default;

    virtual ~CMatrix() = default;

    virtual void Print() const = 0;

    virtual double GetNumAtCoords(size_t row, size_t col) const = 0;
    virtual void SetNumAtCoords(size_t row, size_t col, double value) = 0;
    virtual CMatrix * GetEmptyInstance() const = 0;
    virtual void Resize(std::size_t numRows, std::size_t numCols) = 0;



    virtual bool ShouldBeSparse() const = 0;

    virtual CMatrix *Convert() const = 0;

    virtual CMatrix *Clone() const = 0;
    std::size_t GetNumRows() const{
        return m_NumRows;
    }
    std::size_t GetNumCols() const {
        return m_NumCols;
    }
    virtual void SwapRows(std::size_t a, std::size_t b) = 0;

    bool operator==(const CMatrix &other) {
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

    string ToString() {
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

protected:
    void switchNumRowsCols() {
        size_t tmp = m_NumRows;
        m_NumRows = m_NumCols;
        m_NumCols = tmp;
    };


};


#endif //SEMESTRALKA_CMATRIX_H
