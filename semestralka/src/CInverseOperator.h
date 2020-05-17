//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CINVERSEOPERATOR_H
#define SEMESTRALKA_CINVERSEOPERATOR_H


#include "CUnaryOperator.h"
#include "CMatrixStandard.h"
#include "CMergeNextToOperation.h"
#include "CCutOperator.h"
#include "CGetDeterminant.h"
#include "elimination.h"

class CInverseOperator:  public CUnaryOperator {
public:
    CInverseOperator(shared_ptr<CMatrix> & operand)
    :CUnaryOperator(operand){}

    CMatrixStandard * GetIdentity(std::size_t dimension)const{
        vector<vector<double>> id(dimension);
        for(size_t i = 0; i<dimension;i++){
            for(std::size_t j = 0; j<dimension; j++){
                id[i].push_back(0);
                if(i==j){
                    id[i][j] = 1;
                }
            }
        }
        return new CMatrixStandard(id);
    }

    void CreateZeroTriangles(shared_ptr<CMatrix> & matrix) {
        for (size_t i = 0; i < matrix->m_NumRows; i++) {
            for (size_t j = 0; j < matrix->m_NumRows; j++) {
                if (j != i) {
                    double temp = matrix->GetNumAtCoords(j, i);
                    for (size_t k = 0; k < 2 * matrix->m_NumRows; k++) {
                        matrix->SetNumAtCoords(j, k,matrix->GetNumAtCoords(i, i) * matrix->GetNumAtCoords(j, k));
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k)-(matrix->GetNumAtCoords(i, k) * temp));
                    }
                }
            }
        }
    }

    void MakeDiagonalsTo1(shared_ptr<CMatrix> & matrix) {
        for (size_t i = 0; i < matrix->m_NumRows; i++) {

            double temp = matrix->GetNumAtCoords(i, i);
            for (size_t j = 0; j < matrix->m_NumRows * 2; j++) {
                matrix->SetNumAtCoords(i,j, matrix->GetNumAtCoords(i, j) / temp);
            }
        }
    }

    void ConvertToLU(shared_ptr<CMatrix> & matrix) {
        CreateZeroTriangles(matrix);
        MakeDiagonalsTo1(matrix);
    }


    CMatrix * Evaluate(CMemory & memory) override{
        if (m_Operand->m_NumRows != m_Operand->m_NumCols) {
           throw runtime_error("Inverse does not exist.");
        }
        //todo: check if inverse exists (non zero determinant)
        CGetDeterminant det;
        if(det(m_Operand)==0){
            throw runtime_error("Inverse does not exist.");
        }

        shared_ptr<CMatrix> identity = shared_ptr<CMatrix> (GetIdentity(m_Operand->m_NumRows));

        shared_ptr<CMatrix> augumented = shared_ptr<CMatrix>(CMergeNextToOperator(m_Operand, identity).Evaluate(memory));
        SortForElimination(augumented);

        ConvertToLU(augumented);

        return CCutOperator(augumented, m_Operand->m_NumCols, m_Operand->m_NumCols, {0, m_Operand->m_NumCols}).Evaluate(memory);
    }
};


#endif //SEMESTRALKA_CINVERSEOPERATOR_H
