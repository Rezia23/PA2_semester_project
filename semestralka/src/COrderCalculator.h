//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CORDERCALCULATOR_H
#define SEMESTRALKA_CORDERCALCULATOR_H


#include "CMatrix.h"
#include "CGaussEliminationOperator.h"

class COrderCalculator {
public:
    /**
     * Calculate order of a matrix.
     * @param matrix matrix to have order calculated
     * @return order of a matrix
     */
    int operator()(const shared_ptr<CMatrix> &matrix) const {
        shared_ptr<CMatrix> tmp = shared_ptr<CMatrix>(matrix->Clone());
        Gem(tmp);
        return matrix->GetNumRows() - GetCountZeroRows(tmp);
    }

private:
    /**
     * Count number of rows in matrix which have only zero values.
     * @param matrix
     * @return number of zero rows
     */
    static int GetCountZeroRows(const shared_ptr<CMatrix> &matrix) {
        int count = 0;
        bool isRowZero;
        for (size_t i = 0; i < matrix->GetNumRows(); i++) {
            isRowZero = true;
            for (size_t j = 0; j < matrix->GetNumCols(); j++) {
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
};


#endif //SEMESTRALKA_CORDERCALCULATOR_H
