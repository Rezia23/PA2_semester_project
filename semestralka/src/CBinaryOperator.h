//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CBINARYOPERATOR_H
#define SEMESTRALKA_CBINARYOPERATOR_H


#include "CExpression.h"
#include "CMatrix.h"
#include <memory>
using namespace std;

class CBinaryOperator: public CExpression {
protected:
    unique_ptr<CExpression> m_Left;
    unique_ptr<CExpression> m_Right;
public:
    CBinaryOperator() = default;
    CBinaryOperator(unique_ptr<CExpression> & left, unique_ptr<CExpression> & right){
        m_Left = move(left);
        m_Right = move(right);
    }
    virtual ~CBinaryOperator() = default;
    virtual CMatrix * Evaluate(CMemory & memory)= 0;
};


#endif //SEMESTRALKA_CBINARYOPERATOR_H
