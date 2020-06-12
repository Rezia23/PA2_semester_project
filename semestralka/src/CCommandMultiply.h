//
// Created by hrubate1 on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDMULTIPLY_H
#define SEMESTRALKA_CCOMMANDMULTIPLY_H

#include "CCommand.h"
#include "CMultiplyOperator.h"

class CCommandMultiply : public CCommand {
public:
    CCommandMultiply() : CCommand() {}

    ~CCommandMultiply() override = default;

    CCommandMultiply(string operand1, string operand2) : m_Operand1(operand1), m_Operand2(operand2) {}

    bool Execute(CMemory &memory) override;

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDMULTIPLY_H
