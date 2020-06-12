//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDADD_H
#define SEMESTRALKA_CCOMMANDADD_H


#include "CCommand.h"
#include "CAddOperator.h"

class CCommandAdd : public CCommand {
public:
    CCommandAdd() : CCommand() {}

    ~CCommandAdd() override = default;

    CCommandAdd(string operand1, string operand2) : m_Operand1(std::move(operand1)), m_Operand2(std::move(operand2)) {}

    bool Execute(CMemory &memory) override;

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDADD_H
