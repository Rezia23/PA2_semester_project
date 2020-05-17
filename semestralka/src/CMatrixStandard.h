//
// Created by terez on 24.04.2020.
//

#ifndef SEMESTRALKA_CMATRIXSTANDARD_H
#define SEMESTRALKA_CMATRIXSTANDARD_H

#include "CMatrix.h"
#include <utility>
#include <vector>
#include "CMatrixSparse.h"
#include "elimination.h"

using namespace std;

class CMatrixStandard : public CMatrix {
private:
    vector<vector<double>> m_Matrix;


public:

    CMatrixStandard() : CMatrix() {
        m_Matrix.resize(0);
    }
    CMatrixStandard(vector<vector<double>> matrix) : CMatrix(), m_Matrix(std::move(matrix)) {
        m_NumRows = m_Matrix.size();
        m_NumCols = m_Matrix[0].size();
    }

    CMatrixStandard(map<pair<size_t, size_t>, double> matrix, size_t numRows, size_t numCols) : CMatrix() {
        m_NumRows = numRows;
        m_NumCols = numCols;
        m_Matrix.resize(m_NumRows);
        for (size_t i = 0; i < m_NumRows; i++) {
            for (size_t j = 0; j < m_NumCols; j++) {
                if (matrix.find({i, j}) != matrix.end()) {
                    m_Matrix[i].push_back(matrix[{i, j}]);
                } else {
                    m_Matrix[i].push_back(0);
                }
            }
        }
    }
    virtual void SwapRows(std::size_t a, std::size_t b)override{
        swap(m_Matrix[a], m_Matrix[b]);
    }

    CMatrix *Clone() const override {
        return new CMatrixStandard(m_Matrix);
    }

    virtual CMatrix *Convert() const override;

    virtual ~CMatrixStandard() override = default;

    virtual void Print() const override;

    virtual double GetNumAtCoords(size_t row, size_t col) const override { return m_Matrix[row][col]; }
    virtual void SetNumAtCoords(size_t row, size_t col, double value) override{
        m_Matrix[row][col] = value;
    }
    CMatrix * GetEmptyInstance() const override{
        return new CMatrixStandard();
    }
    void Resize(std::size_t numRows, std::size_t numCols) override{
        m_NumRows = numRows;
        m_NumCols = numCols;
        m_Matrix.resize(numRows);
        for(std::size_t i = 0; i<m_NumRows; i++){
            m_Matrix[i].resize(m_NumCols);
        }
    }



    virtual bool ShouldBeSparse() const override {
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
};


#endif //SEMESTRALKA_CMATRIXSTANDARD_H;;;;
