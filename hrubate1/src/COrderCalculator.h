//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CORDERCALCULATOR_H
#define SEMESTRALKA_CORDERCALCULATOR_H


#include "CMatrix.h"
#include "CGaussEliminationOperator.h"

class COrderCalculator {
public:
    /**
     * Calculate order of a matrix.
     * @param matrix matrix to have order calculated
     * @return order of a matrix
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


#endif //SEMESTRALKA_CORDERCALCULATOR_H
