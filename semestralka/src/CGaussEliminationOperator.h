//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CGAUSSELIMINATIONOPERATOR_H
#define SEMESTRALKA_CGAUSSELIMINATIONOPERATOR_H


#include <iostream>
#include "CMatrix.h"
#include "CMatrixSparse.h"
#include "CUnaryOperator.h"
#include "elimination.h"


class CGaussEliminationOperator : public CUnaryOperator {
public:
    CGaussEliminationOperator(shared_ptr<CMatrix> &operand)
            : CUnaryOperator(operand) {}

    /**
     * Transform variable to upper triangular form.
     */
    CMatrix *Evaluate(CMemory &memory) override {
        shared_ptr<CMatrix> result = unique_ptr<CMatrix>(m_Operand->Clone());
        Gem(result, m_EliminationProcess);
        return new CMatrixSparse(result);
    }
    /**
     * Get matrices from each step of elimination process.
     * @return vector of matrices
     */
    vector<shared_ptr<CMatrix>> GetEliminationProcess() {
        return m_EliminationProcess;
    }

private:
    vector<shared_ptr<CMatrix>> m_EliminationProcess;
};


#endif //SEMESTRALKA_CGAUSSELIMINATIONOPERATOR_H
