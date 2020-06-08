//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_ELIMINATION_H
#define SEMESTRALKA_ELIMINATION_H

#include "CMatrix.h"


int SortForElimination(shared_ptr<CMatrix> &matrix);

void Gem(shared_ptr<CMatrix> &matrix, vector<shared_ptr<CMatrix>> &eliminationProcess);

void Gem(shared_ptr<CMatrix> &matrix);


#endif //SEMESTRALKA_ELIMINATION_H
