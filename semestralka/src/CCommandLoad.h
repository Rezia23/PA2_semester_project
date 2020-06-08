//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDLOAD_H
#define SEMESTRALKA_CCOMMANDLOAD_H


#include "CCommand.h"
#include "CMatrix.h"
#include "CMatrixStandard.h"

class CCommandLoad : public CCommand {
public:
    CCommandLoad() : CCommand() {}

    ~CCommandLoad() override = default;

    CCommandLoad(string varName, vector<vector<double>> matrixNums) : CCommand(), m_VariableName(varName) {
        m_ResultMatrix = (make_unique<CMatrixStandard>(CMatrixStandard(matrixNums)));
        if (m_ResultMatrix->ShouldBeSparse()) {
            m_ResultMatrix = unique_ptr<CMatrix>(m_ResultMatrix->Convert());
        }
    }

    bool Execute(CMemory &memory) override {
        if (memory.ExistsVariable(m_VariableName)) {
            m_Result = "Cannot create variable with same name as existing.";
            return false;
        }
        m_Result = "Matrix " + m_VariableName + " successfully loaded.\n";
        m_Result += m_ResultMatrix->ToString();
        memory.Insert(m_VariableName, move(m_ResultMatrix));
        return true;
    }

private:
    string m_VariableName;

};


#endif //SEMESTRALKA_CCOMMANDLOAD_H
