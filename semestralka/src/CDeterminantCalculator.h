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
    double operator()(const shared_ptr<CMatrix> &matrix) {
        if (matrix->GetNumRows() != matrix->GetNumCols()) {
            throw runtime_error("Cannot get determinant of non square matrix.");
        }
        if (HasZeroRowOrCol(matrix)) {
            return 0;
        }
        shared_ptr<CMatrix> tmpMatrix = shared_ptr<CMatrix>(matrix->Clone());
        vector<double> diagonal(tmpMatrix->GetNumRows(), 1);
        double det = 1;
        det = CalculateDeterminant(tmpMatrix);

        return det;
    }

private:
    /**
     * Calculate determinant by converting matrix to lower upper triangular form.
     * @param matrix matrix to have determinant calculated
     * @return determinant
     */
    double CalculateDeterminant(shared_ptr<CMatrix> &matrix) {
        double determinant = 1;
        double rowsMultipliedBy = 1;
        int numSwaps = SortForElimination(matrix);
        determinant *= pow(-1, numSwaps);
        for (size_t i = 0; i < matrix->GetNumRows(); i++) {
            for (size_t j = 0; j < matrix->GetNumRows(); j++) {
                if (i < j) {
                    double temp = matrix->GetNumAtCoords(j, i);
                    rowsMultipliedBy *= matrix->GetNumAtCoords(i, i);
                    for (size_t k = 0; k < matrix->GetNumCols(); k++) {
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) * matrix->GetNumAtCoords(i, i));
                        matrix->SetNumAtCoords(j, k,
                                               matrix->GetNumAtCoords(j, k) - (matrix->GetNumAtCoords(i, k) * temp));
                    }
                }
            }
        }
        AddDiagonal(determinant, matrix);
        determinant /= rowsMultipliedBy;
        return determinant;
    }
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
    static bool HasZeroRowOrCol(const shared_ptr<CMatrix> &matrix) {
        bool onlyZeroes = true;
        for (std::size_t i = 0; i < matrix->GetNumRows(); i++) {
            for (std::size_t j = 0; j < matrix->GetNumCols(); j++) {
                if (matrix->GetNumAtCoords(i, j) != 0) {
                    onlyZeroes = false;
                    break;
                }
            }
            if (onlyZeroes) {
                return true;
            }
            onlyZeroes = true;
        }
        for (std::size_t i = 0; i < matrix->GetNumCols(); i++) {
            for (std::size_t j = 0; j < matrix->GetNumRows(); j++) {
                if (matrix->GetNumAtCoords(j, i) != 0) {
                    onlyZeroes = false;
                    break;
                }
            }
            if (onlyZeroes) {
                return true;
            }
            onlyZeroes = true;
        }
        return false;
    }
};


#endif //SEMESTRALKA_CDETERMINANTCALCULATOR_H
