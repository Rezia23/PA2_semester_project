//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMERGEUNDEROPERATOR_H
#define SEMESTRALKA_CMERGEUNDEROPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMatrixStandard.h"

class CMergeUnderOperator : public CBinaryOperator {
public:
    CMergeUnderOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Combine two variables into a new one. Variables are combined by placing one below the other.
     */
    CMatrix *Evaluate() override;


};

#endif //SEMESTRALKA_CMERGEUNDEROPERATOR_H
