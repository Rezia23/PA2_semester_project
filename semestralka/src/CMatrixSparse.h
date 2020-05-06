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

    CMatrixSparse(map<pair<size_t, size_t>, double> matrix, size_t numRows, size_t numCols) : m_Matrix(matrix) {
        m_NumRows = numRows;
        m_NumCols = numCols;
    }

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
    virtual void SetNumAtCoords(size_t row, size_t col, double value) override{
        if(GetNumAtCoords(row, col)!=0){
            m_Matrix.erase({row, col});
        }
        if(value!=0){
            m_Matrix[{row, col}] = value;
        }
    }
    CMatrix * GetEmptyInstance() const override{
        return new CMatrixSparse();
    }
    void Resize(std::size_t numRows, std::size_t numCols) override{
        m_NumRows = numRows;
        m_NumCols = numCols;
    }

    virtual void Print() const override;

//    virtual CMatrix *Add(const unique_ptr<CMatrix> &other) const override;
//    virtual CMatrix *NegateAllNums() const override;
//    virtual CMatrix *Subtract(const unique_ptr<CMatrix> &other) const override;
//    virtual CMatrix *Multiply(const unique_ptr<CMatrix> &other) const override;

//    virtual void Transpose() override;

    virtual void ChangeToIdentity(int size) override;

    virtual CMatrixSparse *MergeNextTo(const unique_ptr<CMatrix> &other) const override;
//
//    virtual CMatrixSparse *MergeUnder(const unique_ptr<CMatrix> &other) const override;
//
    virtual void Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) override;

    virtual bool ShouldBeSparse() const {
        return (m_NumRows * m_NumCols) - m_Matrix.size() > m_Matrix.size();
    }
    virtual void SwapRows(std::size_t a, std::size_t b)override{
        map<pair<std::size_t, size_t>, double> nums;
        for(size_t i = 0; i<m_NumCols;i++){
            double nextNum = GetNumAtCoords(a,i);
            if(nextNum!=0){
                nums[{a,i}] = nextNum;
                m_Matrix.erase({a,i});
            }
        }
        for(std::size_t i = 0; i<m_NumCols;i++){
            double nextNum = GetNumAtCoords(b,i);
            if(nextNum!=0){
                m_Matrix.erase({b,i});
                m_Matrix[{a,i}] = nextNum;
            }
        }
        for(auto a : nums){
            m_Matrix[{b, a.first.second}] = a.second;
        }
    }

    /*tbd
     * CMatrixSparse* FindInverse()const;
     * double CalculateDeterminant() const;
     * int CalculateRank() const;
     */

};

#endif //SEMESTRALKA_CMATRIXSPARSE_H
