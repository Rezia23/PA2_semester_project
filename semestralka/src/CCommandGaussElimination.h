//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H
#define SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H


#include "CCommand.h"
#include "CGaussElimination.h"

class CCommandGaussElimination: public CCommand {
public:
    CCommandGaussElimination() : CCommand() {}

    ~CCommandGaussElimination() override = default;

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has been eliminated in these steps:";

        CGaussElimination eliminate;
        eliminate(memory.m_Variables.at(m_VarName), m_EliminationProcess);
        for(std::size_t i = 0 ; i<m_EliminationProcess.size();i++){
            m_Result+="\n" + m_EliminationProcess[i]->ToString();
        }
        return true;
    }
    vector<shared_ptr<CMatrix>> m_EliminationProcess;
public:
    CCommandGaussElimination(string varName) : m_VarName(varName) {}

private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H
