//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMERGENEXTTOOPERATOR_H
#define SEMESTRALKA_CMERGENEXTTOOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMatrixStandard.h"

class CMergeNextToOperator : public CBinaryOperator {
public:
    CMergeNextToOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Combine two variables into a new one. Variables are combined by placing next to each other.
     */
    CMatrix *Evaluate() override;


};


#endif //SEMESTRALKA_CMERGENEXTTOOPERATOR_H
