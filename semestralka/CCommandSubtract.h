//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDSUBTRACT_H
#define SEMESTRALKA_CCOMMANDSUBTRACT_H


#include "CMatrix.h"
#include "CCommand.h"

class CCommandSubtract:public CCommand {
public:
    CCommandSubtract():CCommand(){}
    ~CCommandSubtract() override = default;
    CCommandSubtract(string operand1, string operand2):m_Operand1(operand1), m_Operand2(operand2){}
    bool Execute(map<string, unique_ptr<CMatrix>>& variables)override{
        if(!ExistsVariable(m_Operand1, variables) || !ExistsVariable(m_Operand2, variables)){
            m_Result = "Variables do not exist.";
            return false;
        }
        m_Result = "Result of subtraction is:\n";
        m_ResultMatrix = unique_ptr<CMatrix> (variables.at(m_Operand1)->Subtract(variables.at(m_Operand2)));
        m_Result += m_ResultMatrix->ToString();
        return true;
    }
private:
    string m_Operand1;
    string m_Operand2;
    unique_ptr<CMatrix> m_ResultMatrix;
};


#endif //SEMESTRALKA_CCOMMANDSUBTRACT_H
