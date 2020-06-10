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
     //todo is this better in CMatrix?
    CMatrixStandard *GetIdentity(std::size_t dimension) const {
        vector<vector<double>> id(dimension);
        for (size_t i = 0; i < dimension; i++) {
            for (std::size_t j = 0; j < dimension; j++) {
                id[i].push_back(0);
                if (i == j) {
                    id[i][j] = 1;
                }
            }
        }
        return new CMatrixStandard(id);
    }

    /**
     * Convert augumented matrix so that it begins with a square matrix in lower upper triangular form (diagonal).
     * @param matrix matrix to be converted
     */
    void CreateZeroTriangles(shared_ptr<CMatrix> &matrix) {
        for (size_t i = 0; i < matrix->GetNumRows(); i++) {
            for (size_t j = 0; j < matrix->GetNumRows(); j++) {
                if (j != i) {
                    double temp = matrix->GetNumAtCoords(j, i);
                    for (size_t k = 0; k < 2 * matrix->GetNumRows(); k++) {
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(i, i) * matrix->GetNumAtCoords(j, k));
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k) - (matrix->GetNumAtCoords(i, k) * temp));
                    }
                }
            }
        }
    }
    /**
     * Make diagonal of beginning square matrix of augumented matrix to 1.
     * Each row is divided by number on the diagonal of the beginning square matrix.
     * @param matrix augumented matrix to be converted
     */
    void MakeDiagonalsTo1(shared_ptr<CMatrix> &matrix) {
        for (size_t i = 0; i < matrix->GetNumRows(); i++) {

            double temp = matrix->GetNumAtCoords(i, i);
            for (size_t j = 0; j < matrix->GetNumRows() * 2; j++) {
                matrix->SetNumAtCoords(i, j, matrix->GetNumAtCoords(i, j) / temp);
            }
        }
    }

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
    CMatrix *Evaluate(CMemory &memory) override {
        if (m_Operand->GetNumRows() != m_Operand->GetNumCols()) {
            throw runtime_error("Inverse does not exist.");
        }
        CDeterminantCalculator det;
        if (det(m_Operand) == 0) {
            throw runtime_error("Inverse does not exist.");
        }

        shared_ptr<CMatrix> identity = shared_ptr<CMatrix>(GetIdentity(m_Operand->GetNumRows()));

        shared_ptr<CMatrix> augumented = shared_ptr<CMatrix>(
                CMergeNextToOperator(m_Operand, identity).Evaluate(memory));
        SortForElimination(augumented);

        ConvertToLU(augumented);

        return CCutOperator(augumented, m_Operand->GetNumCols(), m_Operand->GetNumCols(), {0, m_Operand->GetNumCols()}).Evaluate(
                memory);
    }
};


#endif //SEMESTRALKA_CINVERSEOPERATOR_H
