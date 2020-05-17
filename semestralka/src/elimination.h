//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_ELIMINATION_H
#define SEMESTRALKA_ELIMINATION_H

#include "CMatrix.h"


int SortForElimination(shared_ptr<CMatrix> &matrix) {
    int numSwaps = 0;
    bool isChange = true;
    while (isChange) {
        isChange = false;
        for (size_t i = matrix->m_NumRows - 1; i > 0; i--) {
            if (matrix->GetNumAtCoords(i - 1, 0) < matrix->GetNumAtCoords(i, 0)) {
                matrix->SwapRows(i - 1, i);
                numSwaps++;
                isChange = true;
            }
        }
    }
    return numSwaps;
}



#endif //SEMESTRALKA_ELIMINATION_H
