//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDSUBTRACT_H
#define SEMESTRALKA_CCOMMANDSUBTRACT_H


#include "CMatrix.h"
#include "CCommand.h"
#include "CSubtractOperator.h"

class CCommandSubtract : public CCommand {
public:
    CCommandSubtract() : CCommand() {}

    ~CCommandSubtract() override = default;

    CCommandSubtract(string operand1, string operand2) : m_Operand1(std::move(operand1)),
                                                         m_Operand2(std::move(operand2)) {}

    bool Execute(CMemory &memory) override;

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDSUBTRACT_H