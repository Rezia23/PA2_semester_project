//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CGETDETERMINANT_H
#define SEMESTRALKA_CGETDETERMINANT_H


#include "CMatrix.h"
#include <math.h>
#include <iostream>
#include "elimination.h"


class CGetDeterminant{
public:
    double ConvertToUpperTriangular(shared_ptr<CMatrix> & matrix) {
        double determinant = 1;
        double rowsMultipliedBy = 1;
        int numSwaps = SortForElimination(matrix);
        determinant*=pow(-1, numSwaps);
        matrix->Print();
        for (size_t i = 0; i < matrix->m_NumRows; i++) {
            for (size_t j = 0; j < matrix->m_NumRows; j++) {
                if (i < j) {
                    double temp = matrix->GetNumAtCoords(j, i);
                    rowsMultipliedBy*=matrix->GetNumAtCoords(i,i);
                    for (size_t k = 0; k < matrix->m_NumCols; k++) {
                        matrix->SetNumAtCoords(j,k, matrix->GetNumAtCoords(j,k)*matrix->GetNumAtCoords(i,i));
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k)-(matrix->GetNumAtCoords(i,k)*temp));
                    }
                    matrix->Print();
                    std::cout<<std::endl;
                }
            }
        }
        AddDiagonal(determinant, matrix);
        determinant/=rowsMultipliedBy;
        return determinant;
    }

    void AddDiagonal(double & det, shared_ptr<CMatrix> & matrix) const {
        for (size_t i = 0; i < matrix->m_NumRows; i++) {
            for (size_t j = 0; j < matrix->m_NumCols; j++) {
                if (i == j) {
                    det *= matrix->GetNumAtCoords(i, j);
                }
            }
        }
    }
    static bool HasZeroRowOrCol(const shared_ptr<CMatrix> & matrix){
        bool onlyZeroes = true;
        for(std::size_t i = 0; i<matrix->m_NumRows;i++){
            for(std::size_t j = 0;j<matrix->m_NumCols;j++){
                if(matrix->GetNumAtCoords(i,j)!=0){
                    onlyZeroes = false;
                    break;
                }
            }
            if(onlyZeroes){
                return true;
            }
            onlyZeroes = true;
        }
        for(std::size_t i = 0; i<matrix->m_NumCols;i++){
            for(std::size_t j = 0;j<matrix->m_NumRows;j++){
                if(matrix->GetNumAtCoords(j,i)!=0){
                    onlyZeroes = false;
                    break;
                }
            }
            if(onlyZeroes){
                return true;
            }
            onlyZeroes = true;
        }
        return false;
    }


    double operator()(const shared_ptr<CMatrix> & matrix){
        if (matrix->m_NumRows != matrix->m_NumCols) {
            throw runtime_error("Cannot get determinant of non square matrix.");
        }
        if(HasZeroRowOrCol(matrix)){
            return 0;
        }
        shared_ptr<CMatrix> tmpMatrix = shared_ptr<CMatrix>(matrix->Clone());
        vector<double> diagonal(tmpMatrix->m_NumRows, 1);
        //CMatrixStandard tmp = *this;
        double det = 1;
        det = ConvertToUpperTriangular(tmpMatrix);

        tmpMatrix->Print();
        //AddDiagonal(diagonal, tmpMatrix);
        //det *= ConvertToLowerTriangular(tmpMatrix);
        tmpMatrix->Print();
        //AddDiagonal(diagonal, tmpMatrix);

//        for (size_t i = 0; i < diagonal.size(); i++) {
//            det *= diagonal[i];
//        }

        return det;
    }
};


#endif //SEMESTRALKA_CGETDETERMINANT_H
