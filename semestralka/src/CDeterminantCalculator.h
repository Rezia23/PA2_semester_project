//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CDETERMINANTCALCULATOR_H
#define SEMESTRALKA_CDETERMINANTCALCULATOR_H


#include "CMatrix.h"
#include <math.h>
#include <iostream>
#include "elimination.h"


class CDeterminantCalculator {
public:
    /**
     * Calculate determinant of a matrix.
     * @param matrix matrix to have determinant calculated
     * @return determinant
     */
    double operator()(const shared_ptr<CMatrix> &matrix);

private:
    /**
     * Calculate determinant by converting matrix to lower upper triangular form.
     * @param matrix matrix to have determinant calculated
     * @return determinant
     */
    double CalculateDeterminant(shared_ptr<CMatrix> &matrix);

    /**
     * Multiply diagonal values of a square matrix.
     * @param det
     * @param matrix
     */
    void AddDiagonal(double &det, shared_ptr<CMatrix> &matrix) const {
        for (size_t i = 0; i < matrix->GetNumRows(); i++) {
            det *= matrix->GetNumAtCoords(i, i);
        }
    }

    /**
     * Check if matrix has a row or a column with only zeroes.
     * @param matrix input matrix
     * @return true if has only zero row or column, false otherwise
     */
    static bool HasZeroRowOrCol(const shared_ptr<CMatrix> &matrix);
};


#endif //SEMESTRALKA_CDETERMINANTCALCULATOR_H
