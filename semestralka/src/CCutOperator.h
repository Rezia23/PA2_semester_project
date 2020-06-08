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


    CMatrix *Evaluate(CMemory &memory) override {
        if (m_NumRows > m_Operand->m_NumRows || m_NumCols > m_Operand->m_NumCols) {
            throw runtime_error("Wrong dimensions, cannot cut.");
        } else if (m_StartPoint.first > m_Operand->m_NumRows - m_NumRows ||
                   m_StartPoint.second > m_Operand->m_NumCols - m_NumCols) {
            throw runtime_error("Wrong dimensions2, cannot cut.");
        }
        vector<vector<double>> cut(m_NumRows);
        for (size_t i = 0; i < m_NumRows; i++) {
            for (size_t j = 0; j < m_NumCols; j++) {
                cut[i].push_back(m_Operand->GetNumAtCoords(i + m_StartPoint.first, j + m_StartPoint.second));
            }
        }
        if (CMatrixStandard(cut).ShouldBeSparse()) {
            return new CMatrixSparse(cut);
        }
        return new CMatrixStandard(cut);
    }

};


#endif //SEMESTRALKA_CCUTOPERATOR_H
