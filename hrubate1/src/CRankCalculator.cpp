//
// Created by hrubate1 on 07.05.2020.
//

#include "CRankCalculator.h"

int CRankCalculator::GetCountZeroRows(const shared_ptr<CMatrix> &matrix) {
    int count = 0;
    bool isRowZero;
    for (size_t i = 0; i < matrix->GetNumRows(); i++) {
        isRowZero = true;
        for (size_t j = 0; j < matrix->GetNumCols(); j++) {
            if (!IsZero(matrix->GetNumAtCoords(i, j))) {
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

int CRankCalculator::operator()(const shared_ptr<CMatrix> &matrix) const {
    shared_ptr<CMatrix> tmp = shared_ptr<CMatrix>(matrix->Clone());
    Gem(tmp);
    return matrix->GetNumRows() - GetCountZeroRows(tmp);
}
