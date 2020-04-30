//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDLOAD_H
#define SEMESTRALKA_CCOMMANDLOAD_H


#include "CCommand.h"
#include "CMatrix.h"
#include "CMatrixStandard.h"

class CCommandLoad: public CCommand {
public:
    CCommandLoad():CCommand(){}
    ~CCommandLoad() override = default;
    CCommandLoad(string varName, vector<vector<double>> matrixNums):CCommand(), m_VariableName(varName), m_MatrixToLoad(make_unique<CMatrixStandard>(CMatrixStandard(matrixNums))){
        if(m_MatrixToLoad->ShouldBeSparse()){
            m_MatrixToLoad = unique_ptr<CMatrix>(m_MatrixToLoad->Convert());
        }
    }

    bool Execute(map<string, unique_ptr<CMatrix>> &variables) override{
        if(ExistsVariable(m_VariableName, variables)){
            m_Result = "Cannot create variable with same name as existing.";
            return false;
        }
        m_Result = "Matrix " + m_VariableName + " successfully loaded.\n";
        m_Result+=m_MatrixToLoad->ToString();
        variables.insert(make_pair(m_VariableName, move(m_MatrixToLoad)));
        return true;
    }
private:
    string m_VariableName;
    unique_ptr<CMatrix> m_MatrixToLoad;
};


#endif //SEMESTRALKA_CCOMMANDLOAD_H
