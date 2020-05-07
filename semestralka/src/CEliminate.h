//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CELIMINATE_H
#define SEMESTRALKA_CELIMINATE_H


#include "CMatrix.h"

class CEliminate {
protected:
    int SortForElimination(shared_ptr<CMatrix> & matrix) {
        int numSwaps = 0;
        for (size_t i = matrix->m_NumRows - 1; i > 0; i--) {
            if (matrix->GetNumAtCoords(i - 1, 0) < matrix->GetNumAtCoords(i, 0)) {
                matrix->SwapRows(i-1,i);
                numSwaps++;
            }
        }
        return numSwaps;
    }
};


#endif //SEMESTRALKA_CELIMINATE_H
