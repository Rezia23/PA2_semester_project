//
// Created by terez on 06.05.2020.
//

#include "CDeterminantCalculator.h"

double CDeterminantCalculator::operator()(const shared_ptr<CMatrix> &matrix) {
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

double CDeterminantCalculator::CalculateDeterminant(shared_ptr<CMatrix> &matrix) {
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

bool CDeterminantCalculator::HasZeroRowOrCol(const shared_ptr<CMatrix> &matrix) {
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
