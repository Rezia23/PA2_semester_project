//
// Created by terez on 24.04.2020.
//

#ifndef SEMESTRALKA_CMATRIX_H
#define SEMESTRALKA_CMATRIX_H


#include <glob.h>
#include <memory>
#include <vector>


using namespace std;

class CMatrix {

public:
    size_t m_NumRows = 0;
    size_t m_NumCols = 0;

    CMatrix() = default;
    virtual ~CMatrix() {};

    virtual void Print() const = 0;

    virtual double GetNumAtCoords(size_t row, size_t col) const = 0;

    virtual CMatrix *Add(const unique_ptr<CMatrix> & other) const = 0;

    virtual CMatrix *NegateAllNums() const = 0;

    virtual CMatrix *Subtract(const unique_ptr<CMatrix> & other) const = 0;

    virtual CMatrix *Multiply(const unique_ptr<CMatrix> & other) const = 0;

    virtual void Transpose() = 0;

    virtual CMatrix *MergeNextTo(const unique_ptr<CMatrix> & other) const = 0;

    virtual CMatrix *MergeUnder(const unique_ptr<CMatrix> & other) const = 0;
    virtual void ChangeToIdentity(int size) = 0;

    virtual void Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) = 0;
    virtual bool ShouldBeSparse() const = 0;
    virtual CMatrix * Convert()const = 0;
    virtual CMatrix * Clone()const = 0;

    //must copy matrix and call on the copy!
//    double CalculateDeterminant(const unique_ptr<CMatrix> other){
//        //getUpperTriangular
//        //getLowerTriangular
//        //det = sum of products of diagonals
//    }


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

    string ToString(){
        string result;
        for(size_t i = 0; i<m_NumRows;i++){
            for(size_t j = 0;j<m_NumCols;j++){
                if(j!=0){
                    result+=" ";
                }
                result+=to_string(GetNumAtCoords(i,j));
            }
            result+="\n";
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
