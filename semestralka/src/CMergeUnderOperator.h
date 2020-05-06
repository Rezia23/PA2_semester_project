//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMERGEUNDEROPERATOR_H
#define SEMESTRALKA_CMERGEUNDEROPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CMergeUnderOperator: public CBinaryOperator {
public:
    CMergeUnderOperator(shared_ptr<CMatrix> & left, shared_ptr<CMatrix> & right)
            :CBinaryOperator(left, right){}


    CMatrix * Evaluate(CMemory & memory) override{
        if (m_Left->m_NumCols != m_Right->m_NumCols) {
            throw std::runtime_error("Merging incompatible matrices.");
        }
        vector<vector<double>> merged(m_Left->m_NumRows + m_Right->m_NumRows);
        for (size_t i = 0; i < m_Left->m_NumRows + m_Right->m_NumRows; i++) {
            for (size_t j = 0; j < m_Left->m_NumCols; j++) {
                double nextNum;
                if(i<m_Left->m_NumRows){
                    nextNum = m_Left->GetNumAtCoords(i,j);
                }else{
                    nextNum = m_Right->GetNumAtCoords(i-m_Left->m_NumRows, j);
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

#endif //SEMESTRALKA_CMERGEUNDEROPERATOR_H
