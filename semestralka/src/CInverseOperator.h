//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CINVERSEOPERATOR_H
#define SEMESTRALKA_CINVERSEOPERATOR_H


#include "CUnaryOperator.h"
#include "CMatrixStandard.h"
#include "CMergeNextToOperator.h"
#include "CCutOperator.h"
#include "CDeterminantCalculator.h"


class CInverseOperator : public CUnaryOperator {
public:
    CInverseOperator(shared_ptr<CMatrix> &operand)
            : CUnaryOperator(operand) {}

    /**
     * Get new identity matrix.
     * @param dimension size of matrix to be created
     * @return new identity matrix
     */
    CMatrixStandard *GetIdentity(std::size_t dimension) const;

    /**
     * Convert augumented matrix so that it begins with a square matrix in lower upper triangular form (diagonal).
     * @param matrix matrix to be converted
     */
    void CreateZeroTriangles(shared_ptr<CMatrix> &matrix);

    /**
     * Make diagonal of beginning square matrix of augumented matrix to 1.
     * Each row is divided by number on the diagonal of the beginning square matrix.
     * @param matrix augumented matrix to be converted
     */
    void MakeDiagonalsTo1(shared_ptr<CMatrix> &matrix);

    /**
     * Convert augumented matrix so that it begins with an identity matrix.
     * @param matrix matrix to be converted
     */
    void ConvertToLU(shared_ptr<CMatrix> &matrix) {
        CreateZeroTriangles(matrix);
        MakeDiagonalsTo1(matrix);
    }

    /**
     * Find inverse of a variable.
     */
    CMatrix *Evaluate() override;
};


#endif //SEMESTRALKA_CINVERSEOPERATOR_H
