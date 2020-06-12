//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CSUBTRACTOPERATOR_H
#define SEMESTRALKA_CSUBTRACTOPERATOR_H


#include "CMatrix.h"
#include "CBinaryOperator.h"
#include "CMatrixStandard.h"

class CSubtractOperator : public CBinaryOperator {
public:
    CSubtractOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right)
            : CBinaryOperator(left, right) {}

    /**
     * @copydoc COperator::Evaluate()
     *
     * Subtract two variables.
     */
    CMatrix *Evaluate() override;
};


#endif //SEMESTRALKA_CSUBTRACTOPERATOR_H
