//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CUNARYOPERATOR_H
#define SEMESTRALKA_CUNARYOPERATOR_H

#include "COperator.h"
#include "CMatrix.h"

using namespace std;

class CUnaryOperator : public COperator {
protected:
    shared_ptr<CMatrix> m_Operand;
public:
    CUnaryOperator() = default;

    CUnaryOperator(shared_ptr<CMatrix> &operand) {
        m_Operand = (operand);
    }

    virtual ~CUnaryOperator() = default;

};


#endif //SEMESTRALKA_CUNARYOPERATOR_H
