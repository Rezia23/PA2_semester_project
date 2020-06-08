//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_COPERATOR_H
#define SEMESTRALKA_COPERATOR_H

#include "CMemory.h"

class COperator {
public:
    COperator() = default;

    virtual ~COperator() = default;

    virtual class CMatrix *Evaluate(CMemory &memory) = 0;
};


#endif //SEMESTRALKA_COPERATOR_H
