//
// Created by terez on 06.05.2020.
//

#include "CInverseOperator.h"

CMatrixStandard *CInverseOperator::GetIdentity(std::size_t dimension) const {
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

void CInverseOperator::CreateZeroTriangles(shared_ptr<CMatrix> &matrix) {
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

void CInverseOperator::MakeDiagonalsTo1(shared_ptr<CMatrix> &matrix) {
    for (size_t i = 0; i < matrix->GetNumRows(); i++) {

        double temp = matrix->GetNumAtCoords(i, i);
        for (size_t j = 0; j < matrix->GetNumRows() * 2; j++) {
            matrix->SetNumAtCoords(i, j, matrix->GetNumAtCoords(i, j) / temp);
        }
    }
}

CMatrix *CInverseOperator::Evaluate() {
    if (m_Operand->GetNumRows() != m_Operand->GetNumCols()) {
        throw runtime_error("Inverse does not exist.");
    }
    CDeterminantCalculator det;
    if (det(m_Operand) == 0) {
        throw runtime_error("Inverse does not exist.");
    }

    shared_ptr<CMatrix> identity = shared_ptr<CMatrix>(GetIdentity(m_Operand->GetNumRows()));

    shared_ptr<CMatrix> augumented = shared_ptr<CMatrix>(
            CMergeNextToOperator(m_Operand, identity).Evaluate());
    SortForElimination(augumented);

    ConvertToLU(augumented);

    return CCutOperator(augumented, m_Operand->GetNumCols(), m_Operand->GetNumCols(),
                        {0, m_Operand->GetNumCols()}).Evaluate();
}
