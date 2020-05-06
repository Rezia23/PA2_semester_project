//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CEXPRESSION_H
#define SEMESTRALKA_CEXPRESSION_H

#include "CMemory.h"

class CExpression {
public:
    size_t m_NumRows = 0;
    size_t m_NumCols = 0;
    CExpression() = default;
    virtual ~CExpression() = default;
    virtual class CExpression * Evaluate(CMemory & memory) = 0;
    virtual string ToString() const = 0;
    virtual double GetNumAtCoords(size_t row, size_t col) const = 0;
};


#endif //SEMESTRALKA_CEXPRESSION_H
