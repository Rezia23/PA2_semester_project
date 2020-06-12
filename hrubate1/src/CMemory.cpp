//
// Created by terez on 05.05.2020.
//

#include "CMemory.h"
#include "CMatrix.h"

void CMemory::Insert(const string &name, shared_ptr<CMatrix> matrix) {
    if (ExistsVariable(name)) {
        m_Variables.at(name) = matrix;
    } else {
        m_Variables[name] = matrix;
    }
}

shared_ptr<CMatrix> &CMemory::At(const string &name) {
    if (!ExistsVariable(name)) {
        throw runtime_error("Variable does not exist");
    }
    return m_Variables.at(name);
}
