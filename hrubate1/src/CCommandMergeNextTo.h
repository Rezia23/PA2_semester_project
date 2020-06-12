//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDMERGENEXTTO_H
#define SEMESTRALKA_CCOMMANDMERGENEXTTO_H

#include "CCommand.h"
#include "CMergeNextToOperator.h"

class CCommandMergeNextTo : public CCommand {
public:
    CCommandMergeNextTo() : CCommand() {}

    ~CCommandMergeNextTo() override = default;

    CCommandMergeNextTo(string operand1, string operand2) : m_Operand1(operand1), m_Operand2(operand2) {}

    bool Execute(CMemory &memory) override;

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDMERGENEXTTO_H
