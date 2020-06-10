//
// Created by terez on 07.05.2020.
//

#include "CGaussEliminationOperator.h"

CMatrix *CGaussEliminationOperator::Evaluate(CMemory &memory) {
    shared_ptr<CMatrix> result = unique_ptr<CMatrix>(m_Operand->Clone());
    Gem(result, m_EliminationProcess);
    return new CMatrixSparse(result);
}
