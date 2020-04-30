//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDMULTIPLY_H
#define SEMESTRALKA_CCOMMANDMULTIPLY_H

#include "CCommand.h"

class CCommandMultiply:public CCommand {
public:
    CCommandMultiply():CCommand(){}
    ~CCommandMultiply() override = default;
    CCommandMultiply(string operand1, string operand2):m_Operand1(operand1), m_Operand2(operand2){}
    bool Execute(map<string, unique_ptr<CMatrix>>& variables)override{
        if(!ExistsVariable(m_Operand1, variables) || !ExistsVariable(m_Operand2, variables)){
            m_Result = "Variables do not exist.";
            return false;
        }
        m_Result = "Result of multiplication is:\n";
        m_ResultMatrix = unique_ptr<CMatrix> (variables.at(m_Operand1)->Multiply(variables.at(m_Operand2)));
        m_Result += m_ResultMatrix->ToString();
        return true;
    }
private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDMULTIPLY_H
