//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CBINARYOPERATOR_H
#define SEMESTRALKA_CBINARYOPERATOR_H


#include "COperator.h"
#include "CMatrix.h"

using namespace std;

class CBinaryOperator : public COperator {
protected:
    shared_ptr<CMatrix> m_Left;
    shared_ptr<CMatrix> m_Right;
public:
    CBinaryOperator() = default;

    CBinaryOperator(shared_ptr<CMatrix> &left, shared_ptr<CMatrix> &right) {
        m_Left = (left);
        m_Right = (right);
    }

    virtual ~CBinaryOperator() = default;

    virtual CMatrix *Evaluate() = 0;
};


#endif //SEMESTRALKA_CBINARYOPERATOR_H
