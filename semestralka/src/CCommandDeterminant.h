//
// Created by terez on 06.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDDETERMINANT_H
#define SEMESTRALKA_CCOMMANDDETERMINANT_H

#include "CCommand.h"
#include "CDeterminantCalculator.h"

class CCommandDeterminant : public CCommand {
public:
    CCommandDeterminant() : CCommand() {}

    ~CCommandDeterminant() override = default;

    CCommandDeterminant(string varName) : m_VarName(move(varName)) {}

    bool Execute(CMemory &memory) override;

    double m_Determinant;
private:
    string m_VarName;

};


#endif //SEMESTRALKA_CCOMMANDDETERMINANT_H
