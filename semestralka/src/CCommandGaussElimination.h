//
// Created by hrubate1 on 19.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H
#define SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H

#include "CCommand.h"
#include "CGaussEliminationOperator.h"

class CCommandGaussElimination : public CCommand {
public:
    CCommandGaussElimination() : CCommand() {}

    ~CCommandGaussElimination() override = default;

    bool Execute(CMemory &memory) override;

    CCommandGaussElimination(string varName) : m_VarName(varName) {};

protected:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDGAUSSELIMINATION_H
