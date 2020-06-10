//
// Created by terez on 07.05.2020.
//

#include "elimination.h"

int SortForElimination(shared_ptr<CMatrix> &matrix) {
    int numSwaps = 0;
    bool isChange = true;
    while (isChange) {
        isChange = false;
        for (size_t i = matrix->GetNumRows() - 1; i > 0; i--) {
            if (matrix->GetNumAtCoords(i - 1, 0) < matrix->GetNumAtCoords(i, 0)) {
                matrix->SwapRows(i - 1, i);
                numSwaps++;
                isChange = true;
            }
        }
    }
    return numSwaps;
}


void Gem(shared_ptr<CMatrix> &matrix, vector<shared_ptr<CMatrix>> &eliminationProcess) {
    bool wasMadeChange = false;
    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));
    SortForElimination(matrix);
    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));

    for (size_t i = 0; i < matrix->GetNumRows(); i++) {
        for (size_t j = 0; j < matrix->GetNumRows(); j++) {
            if (i < j) {
                double temp = matrix->GetNumAtCoords(j, i);
                for (size_t k = 0; k < matrix->GetNumCols(); k++) {
                    if (temp == 0) {
                        wasMadeChange = true;
                        break;
                    }
                    matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) * matrix->GetNumAtCoords(i, i));
                    matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) - (matrix->GetNumAtCoords(i, k) * temp));
                }
                if (!wasMadeChange) {
                    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));
                }
                wasMadeChange = false;
            }
        }
    }
}

void Gem(shared_ptr<CMatrix> &matrix) {
    SortForElimination(matrix);

    for (size_t i = 0; i < matrix->GetNumRows(); i++) {
        for (size_t j = 0; j < matrix->GetNumRows(); j++) {
            if (i < j) {
                double temp = matrix->GetNumAtCoords(j, i);
                for (size_t k = 0; k < matrix->GetNumCols(); k++) {
                    matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) * matrix->GetNumAtCoords(i, i));
                    matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) - (matrix->GetNumAtCoords(i, k) * temp));
                }
            }
        }
    }
}
