//
// Created by hrubate1 on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDMERGEUNDER_H
#define SEMESTRALKA_CCOMMANDMERGEUNDER_H

#include "CCommand.h"
#include "CMergeUnderOperator.h"

class CCommandMergeUnder : public CCommand {
public:
    CCommandMergeUnder() : CCommand() {}

    ~CCommandMergeUnder() override = default;

    CCommandMergeUnder(string operand1, string operand2) : m_Operand1(operand1), m_Operand2(operand2) {}

    bool Execute(CMemory &memory) override;

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDMERGEUNDER_H
