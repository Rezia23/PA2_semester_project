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
class CMatrixSparse: public CMatrix {
private:
    map<pair<size_t, size_t>, double> m_Matrix;
public:
    CMatrixSparse():CMatrix(){}
    CMatrixSparse(map<pair<size_t, size_t>, double> matrix, size_t numRows, size_t numCols) : m_Matrix(matrix) {
        m_NumRows = numRows;
        m_NumCols = numCols;
    }
    virtual ~CMatrixSparse() override = default;
    virtual double GetNumAtCoords(size_t row, size_t col) const override;
    virtual void Print() const override;
    virtual CMatrixSparse * Add(const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixSparse * NegateAllNums() const override;
    virtual CMatrixSparse * Subtract (const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixSparse * Multiply (const unique_ptr<CMatrix> & other) const override;
    virtual void Transpose() override;
    virtual void ChangeToIdentity(int size) override;
    virtual CMatrixSparse * MergeNextTo(const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixSparse * MergeUnder(const unique_ptr<CMatrix> & other) const override;
    virtual void Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) override;

};

#endif //SEMESTRALKA_CMATRIXSPARSE_H
