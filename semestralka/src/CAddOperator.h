//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CADDOPERATOR_H
#define SEMESTRALKA_CADDOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CAddOperator: public CBinaryOperator {
public:
    CAddOperator(unique_ptr<CExpression> & left, unique_ptr<CExpression> & right)
    :CBinaryOperator(left, right){}

    //todo: fix - cannot
    CExpression * Evaluate(CMemory & memory) override{
        unique_ptr<CExpression> left = unique_ptr<CExpression>(m_Left->Evaluate(memory));
        unique_ptr<CExpression> right = unique_ptr<CExpression>(m_Left->Evaluate(memory));
        if (left->m_NumRows != right->m_NumRows || left->m_NumCols != right->m_NumCols) {
            throw "Adding incompatible matrices.";
        }
        vector<vector<double>> sum(left->m_NumRows);
        for (size_t i = 0; i < left->m_NumRows; i++) {
            for (size_t j = 0; j < left->m_NumCols; j++) {
                sum[i].push_back(left->GetNumAtCoords(i, j) + right->GetNumAtCoords(i, j));
            }
        }
        if (CMatrixStandard(sum).ShouldBeSparse()) {
            return new CMatrixSparse(sum);
        }
        return new CMatrixStandard(sum);
    }


};


#endif //SEMESTRALKA_CADDOPERATOR_H
