//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CMULTIPLYOPERATOR_H
#define SEMESTRALKA_CMULTIPLYOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMemory.h"
#include "CMatrixStandard.h"

class CMultiplyOperator : public CBinaryOperator {
public:
    CMultiplyOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * Multiply variables.
     */
    CMatrix *Evaluate(CMemory &memory) override;
};


#endif //SEMESTRALKA_CMULTIPLYOPERATOR_H
