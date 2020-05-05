//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CEXPRESSION_H
#define SEMESTRALKA_CEXPRESSION_H

#include "CMemory.h"

class CExpression {
public:
    CExpression() = default;
    virtual ~CExpression() = default;
    virtual class CExpression * Evaluate(CMemory & memory) = 0;
};


#endif //SEMESTRALKA_CEXPRESSION_H
