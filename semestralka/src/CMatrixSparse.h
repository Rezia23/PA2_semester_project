//
// Created by terez on 24.04.2020.
//

#ifndef SEMESTRALKA_CMATRIXSPARSE_H
#define SEMESTRALKA_CMATRIXSPARSE_H

#include <map>
#include <iostream>
#include "CMatrix.h"
#include "CMatrixStandard.h"


using namespace std;

class CMatrixSparse : public CMatrix {
private:
    map<pair<size_t, size_t>, double> m_Matrix;
public:
    CMatrixSparse() : CMatrix() {}

    CMatrixSparse(const shared_ptr<CMatrix> &other) : CMatrix() {
        m_NumRows = other->GetNumRows();
        m_NumCols = other->GetNumCols();
        for (size_t i = 0; i < m_NumRows; i++) {
            for (size_t j = 0; j < m_NumCols; j++) {
                SetNumAtCoords(i, j, other->GetNumAtCoords(i, j));
            }
        }
    }

    CMatrixSparse(map<pair<size_t, size_t>, double> matrix, size_t numRows, size_t numCols) : m_Matrix(matrix) {
        m_NumRows = numRows;
        m_NumCols = numCols;
    }

    /**
     * Construct matrix from values in two dimensional vector
     * @param matrix values of matrix to be constructed
     */
    CMatrixSparse(vector<vector<double>> matrix) : CMatrix() {
        m_NumRows = matrix.size();
        m_NumCols = matrix[0].size();
        for (size_t i = 0; i < m_NumRows; i++) {
            for (size_t j = 0; j < m_NumCols; j++) {
                if (matrix[i][j] != 0) {
                    m_Matrix[{i, j}] = matrix[i][j];
                }
            }
        }
    }

    CMatrix *Clone() const override {
        return new CMatrixSparse(m_Matrix, m_NumRows, m_NumCols);
    }

    virtual CMatrix *Convert() const override;

    virtual ~CMatrixSparse() override = default;

    virtual double GetNumAtCoords(size_t row, size_t col) const override;

    virtual void SetNumAtCoords(size_t row, size_t col, double value) override;

    CMatrix *GetEmptyInstance() const override {
        return new CMatrixSparse();
    }

    void Resize(std::size_t numRows, std::size_t numCols) override {
        m_NumRows = numRows;
        m_NumCols = numCols;
    }

    virtual void Print() const override;


    virtual bool ShouldBeSparse() const override {
        return (m_NumRows * m_NumCols) - m_Matrix.size() > m_Matrix.size();
    }

    virtual void SwapRows(std::size_t a, std::size_t b) override;


};

#endif //SEMESTRALKA_CMATRIXSPARSE_H
