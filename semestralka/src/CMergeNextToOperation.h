//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMERGENEXTTOOPERATION_H
#define SEMESTRALKA_CMERGENEXTTOOPERATION_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CMergeNextToOperator: public CBinaryOperator {
public:
    CMergeNextToOperator(shared_ptr<CMatrix> & left, shared_ptr<CMatrix> & right)
            :CBinaryOperator(left, right){}


    CMatrix * Evaluate(CMemory & memory) override{
        if (m_Left->m_NumRows != m_Right->m_NumRows) {
            throw std::runtime_error("Merging incompatible matrices.");
        }
        vector<vector<double>> merged(m_Left->m_NumRows);
        for (size_t i = 0; i < m_Left->m_NumRows; i++) {
            for (size_t j = 0; j < m_Left->m_NumCols + m_Right->m_NumCols; j++) {
                double nextNum;
                if(j<m_Left->m_NumCols){
                    nextNum = m_Left->GetNumAtCoords(i,j);
                }else{
                    nextNum = m_Right->GetNumAtCoords(i, j-m_Left->m_NumCols);
                }
                merged[i].push_back(nextNum);
            }
        }
        if (CMatrixStandard(merged).ShouldBeSparse()) {
            return new CMatrixSparse(merged);
        }
        return new CMatrixStandard(merged);
    }


};


#endif //SEMESTRALKA_CMERGENEXTTOOPERATION_H
