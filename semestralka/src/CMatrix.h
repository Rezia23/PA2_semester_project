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

class CMatrix {
protected:
    size_t m_NumRows = 0;
    size_t m_NumCols = 0;
public:

    CMatrix() = default;

    virtual ~CMatrix() = default;

    size_t GetNumRows() const {
        return m_NumRows;
    }

    size_t GetNumCols() const {
        return m_NumCols;
    }

    /**
     * Debug function to print matrix.
     */
     //todo probably delete
    virtual void Print() const = 0;
    /**
     * Get value from a matrix from given coordinates.
     * @param row index of a row of a value
     * @param col index of a column of a value
     * @return value on indexes [row][col]
     */
    virtual double GetNumAtCoords(size_t row, size_t col) const = 0;
    /**
     * Set value of matrix at given coordinates.
     * @param row index of a row of a value
     * @param col index of a column of a value
     * @param value value to be set
     */
    virtual void SetNumAtCoords(size_t row, size_t col, double value) = 0;

    /**
     * Get empty instance of a matrix.
     * @return new matrix pointer
     */
    virtual CMatrix *GetEmptyInstance() const = 0;

    /**
     * Set sizes of a matrix.
     * @param numRows number of rows to be set
     * @param numCols number of columns to be set
     */
    virtual void Resize(std::size_t numRows, std::size_t numCols) = 0;

    /**
     * Check if matrix should be represented as sparse.
     * If number of zero values is bigger than number of other values, matrix should be sparse.
     * @return true if should be sparse, false otherwise
     */
    virtual bool ShouldBeSparse() const {
        size_t zeroCount = 0;
        for (size_t i = 0; i < m_NumRows; i++) {
            for (size_t j = 0; j < m_NumCols; j++) {
                if (GetNumAtCoords(i, j) == 0) {
                    zeroCount++;
                }
            }
        }
        return zeroCount > (m_NumRows * m_NumCols) - zeroCount;
    }

    /**
     * Convert matrix to different representation.
     * @return
     */
    virtual CMatrix *Convert() const = 0;

    /**
     * Get new instance of the same matrix.
     * @return new instance
     */
    virtual CMatrix *Clone() const = 0;


    /**
     * Swap rows of a matrix.
     * @param a first row to be swapped
     * @param b second row to be swapped
     */
    virtual void SwapRows(std::size_t a, std::size_t b) = 0;

    /**
     * == overload, two matrices are equal if all their values are equal
     * @param other
     * @return true if matrices are equal
     */
    bool operator==(const CMatrix &other);

    /**
     * Convert matrix to string.
     * @return matrix in string
     */
     //todo maybe format somehow better
    string ToString() const;

    int SetCellWidth() const;

    int GetNumLength(std::size_t rows, std::size_t cols) const;
};


#endif //SEMESTRALKA_CMATRIX_H
