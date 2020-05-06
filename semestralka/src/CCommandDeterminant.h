//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDDETERMINANT_H
#define SEMESTRALKA_CCOMMANDDETERMINANT_H
#include "CCommand.h"
#include "GetDeterminant.h"

class CCommandDeterminant:public CCommand {
public:
    CCommandDeterminant() : CCommand() {}

    ~CCommandDeterminant() override = default;

    CCommandDeterminant(string varName) : m_VarName(varName) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has determinant:\n";

        GetDeterminant det;
        m_Determinant = det(memory.m_Variables.at(m_VarName));
        m_Result += to_string(m_Determinant);
        return true;
    }
    double m_Determinant;
private:
    string m_VarName;

};


#endif //SEMESTRALKA_CCOMMANDDETERMINANT_H
