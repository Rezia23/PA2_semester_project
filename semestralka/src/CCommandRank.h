//
// Created by hrubate1 on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDRANK_H
#define SEMESTRALKA_CCOMMANDRANK_H

#include "CCommand.h"
#include "CRankCalculator.h"

class CCommandRank : public CCommand {
public:
    CCommandRank() : CCommand() {}

    ~CCommandRank() override = default;

    CCommandRank(string varName) : m_VarName(varName) {}

    bool Execute(CMemory &memory) override;

    int m_Rank;
private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDRANK_H
