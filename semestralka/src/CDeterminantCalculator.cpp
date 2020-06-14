//
// Created by hrubate1 on 06.05.2020.
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
    if(IsZero(det)){
        det = 0;
    }
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
                if(temp!=0){
                    rowsMultipliedBy *= matrix->GetNumAtCoords(i, i); //store multiples used for elimination
                    for (size_t k = 0; k < matrix->GetNumCols(); k++) {
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) * matrix->GetNumAtCoords(i, i));
                        matrix->SetNumAtCoords(j, k,
                                               matrix->GetNumAtCoords(j, k) - (matrix->GetNumAtCoords(i, k) * temp));
                    }
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
            if (!IsZero(matrix->GetNumAtCoords(i, j))) {
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
            if (!IsZero(matrix->GetNumAtCoords(j, i))) {
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
