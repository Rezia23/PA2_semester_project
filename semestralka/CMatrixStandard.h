//
// Created by terez on 24.04.2020.
//

#ifndef SEMESTRALKA_CMATRIXSTANDARD_H
#define SEMESTRALKA_CMATRIXSTANDARD_H

#include "CMatrix.h"
#include <utility>
#include <vector>
#include "CMatrixSparse.h"
using namespace std;

class CMatrixStandard: public CMatrix {
private:
    vector<vector<double>> m_Matrix;
    void SortForElimination();
    void CreateZeroTriangles();
    void MakeDiagonalsTo1();
    void ConvertToLU();
    void AddDiagonal(vector<double> & diagonal)const;
    void ConvertToUpperTriangular(bool printSteps = false);
    void ConvertToLowerTriangular(bool printSteps = false);
    int GetCountZeroRows()const;

public:
    CMatrixStandard():CMatrix(){
        m_Matrix.resize(0);
    }
    CMatrixStandard (vector<vector<double>>  matrix): CMatrix(), m_Matrix(std::move(matrix)){
        m_NumRows = m_Matrix.size();
        m_NumCols = m_Matrix[0].size();
    }
    virtual CMatrixSparse * Convert() const override {
       size_t  numRows = m_NumRows;
       size_t  numCols = m_NumCols;
       map<pair<size_t , size_t >, double> matrix;
        for(size_t i = 0; i<m_NumRows;i++){
            for(size_t j = 0; j<m_NumCols;j++){
                if(GetNumAtCoords(i,j)!=0){
                    matrix[{i,j}] = GetNumAtCoords(i,j);
                }
            }
        }
        return new CMatrixSparse(matrix, numRows, numCols);
    }
    virtual ~CMatrixStandard() override = default;
    virtual void Print() const override;
    virtual double GetNumAtCoords(size_t row, size_t col) const override { return m_Matrix[row][col];}

    virtual CMatrixStandard* Add (const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixStandard * NegateAllNums() const override;
    virtual CMatrixStandard * Subtract (const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixStandard * Multiply (const unique_ptr<CMatrix> & other) const override;
    virtual void Transpose() override;
    virtual void ChangeToIdentity(int size) override;
    virtual CMatrixStandard * MergeNextTo(const unique_ptr<CMatrix> & other) const override;
    virtual CMatrixStandard * MergeUnder(const unique_ptr<CMatrix> & other) const override;
    virtual void Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) override;
    CMatrixStandard* FindInverse()const;
    double CalculateDeterminant() const;
    int CalculateRank() const;
    virtual bool ShouldBeSparse() const override{
        size_t zeroCount = 0;
        for(size_t i = 0; i<m_NumRows;i++){
            for(size_t j = 0; j<m_NumCols;j++){
                if(GetNumAtCoords(i,j)==0){
                    zeroCount++;
                }
            }
        }
        return zeroCount>(m_NumRows*m_NumCols)-zeroCount;
    }







};


#endif //SEMESTRALKA_CMATRIXSTANDARD_H;;;;
