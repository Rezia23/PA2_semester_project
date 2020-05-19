//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDDETERMINANT_H
#define SEMESTRALKA_CCOMMANDDETERMINANT_H
#include "CCommand.h"
#include "CDeterminantCalculator.h"

class CCommandDeterminant:public CCommand {
public:
    CCommandDeterminant() : CCommand() {}

    ~CCommandDeterminant() override = default;

    CCommandDeterminant(string varName) : m_VarName(move(varName)) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has determinant:\n";


        try{
            CDeterminantCalculator det;
            m_Determinant = det(memory.At(m_VarName));
            m_Result += to_string(m_Determinant);
            return true;
        }catch(const std::runtime_error& e){
            m_Result = "Matrix " + m_VarName + " is not square - cannot get determinant.";
            return false;
        }

    }
    double m_Determinant;
private:
    string m_VarName;

};


#endif //SEMESTRALKA_CCOMMANDDETERMINANT_H
