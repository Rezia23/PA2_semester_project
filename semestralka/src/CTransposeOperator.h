//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CTRANSPOSEOPERATOR_H
#define SEMESTRALKA_CTRANSPOSEOPERATOR_H

#include "CUnaryOperator.h"
#include "CMatrixStandard.h"

class CTransposeOperator : public CUnaryOperator {
public:
    CTransposeOperator(shared_ptr<CMatrix> &operand)
            : CUnaryOperator(operand) {}

    /**
     * Perform matrix transposition on a variable.
     */
    CMatrix *Evaluate() override;

};


#endif //SEMESTRALKA_CTRANSPOSEOPERATOR_H
