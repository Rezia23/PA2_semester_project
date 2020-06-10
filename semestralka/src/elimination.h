//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_ELIMINATION_H
#define SEMESTRALKA_ELIMINATION_H

#include "CMatrix.h"


int SortForElimination(shared_ptr<CMatrix> &matrix);

/**
 * Convert matrix to upper triangular form, store steps (matrices) of elimination process.
 * @param matrix matrix to be converted
 * @param eliminationProcess vector of steps (matrices) of elimination
 */
void Gem(shared_ptr<CMatrix> &matrix, vector<shared_ptr<CMatrix>> &eliminationProcess);
/**
 * Convert matrix to upper triangular form.
 * @param matrix matrix to be converted
 */
void Gem(shared_ptr<CMatrix> &matrix);


#endif //SEMESTRALKA_ELIMINATION_H
