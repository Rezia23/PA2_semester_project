//
// Created by hrubate1 on 07.05.2020.
//

#ifndef SEMESTRALKA_CRANKCALCULATOR_H
#define SEMESTRALKA_CRANKCALCULATOR_H


#include "CMatrix.h"
#include "CGaussEliminationOperator.h"

class CRankCalculator {
public:
    /**
     * Calculate rank of a matrix.
     * @param matrix matrix to have rank calculated
     * @return rank of a matrix
     */
    int operator()(const shared_ptr<CMatrix> &matrix) const;

private:
    /**
     * Count number of rows in matrix which have only zero values.
     * @param matrix
     * @return number of zero rows
     */
    static int GetCountZeroRows(const shared_ptr<CMatrix> &matrix);
};


#endif //SEMESTRALKA_CRANKCALCULATOR_H
