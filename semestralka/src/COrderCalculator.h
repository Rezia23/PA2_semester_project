//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CORDERCALCULATOR_H
#define SEMESTRALKA_CORDERCALCULATOR_H


#include "CMatrix.h"
#include "CGaussEliminationOperator.h"

class COrderCalculator {
public:
    int GetCountZeroRows(const shared_ptr<CMatrix> &matrix) const {
        int count = 0;
        bool isRowZero;
        for (size_t i = 0; i < matrix->m_NumRows; i++) {
            isRowZero = true;
            for (size_t j = 0; j < matrix->m_NumCols; j++) {
                if (matrix->GetNumAtCoords(i, j) != 0) {
                    isRowZero = false;
                    break;
                }
            }
            if (isRowZero) {
                count++;
            }
        }
        return count;
    }

    int operator()(const shared_ptr<CMatrix> &matrix) const {
        shared_ptr<CMatrix> tmp = shared_ptr<CMatrix>(matrix->Clone());
        Gem(tmp);
        return matrix->m_NumRows - GetCountZeroRows(tmp);
    }
};


#endif //SEMESTRALKA_CORDERCALCULATOR_H
