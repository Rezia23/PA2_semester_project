//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CADDOPERATOR_H
#define SEMESTRALKA_CADDOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CAddOperator : public CBinaryOperator {
public:
    CAddOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Add two variables from memory.
     */
    CMatrix *Evaluate(CMemory &memory) override;


};


#endif //SEMESTRALKA_CADDOPERATOR_H
