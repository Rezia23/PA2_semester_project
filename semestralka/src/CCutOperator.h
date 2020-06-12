//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CCUTOPERATOR_H
#define SEMESTRALKA_CCUTOPERATOR_H


#include <utility>

#include "CUnaryOperator.h"
#include "CMatrixStandard.h"

class CCutOperator : public CUnaryOperator {
private:
    std::size_t m_NumRows;
    std::size_t m_NumCols;
    pair<size_t, size_t> m_StartPoint;
public:

    CCutOperator(shared_ptr<CMatrix> &operand, std::size_t numRows, std::size_t numCols,
                 pair<size_t, size_t> startPoint)
            : CUnaryOperator(operand), m_NumRows(numRows), m_NumCols(numCols), m_StartPoint(std::move(startPoint)) {}

    /**
     *  @copydoc COperator::Evaluate()
     *
     * Cut matrix according to parameters.
     */
    CMatrix *Evaluate() override;

};


#endif //SEMESTRALKA_CCUTOPERATOR_H
