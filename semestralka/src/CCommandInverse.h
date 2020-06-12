//
// Created by hrubate1 on 06.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDINVERSE_H
#define SEMESTRALKA_CCOMMANDINVERSE_H


#include "CCommand.h"
#include "CInverseOperator.h"

class CCommandInverse : public CCommand {
public:
    CCommandInverse() : CCommand() {}

    ~CCommandInverse() override = default;

    CCommandInverse(string varName) : m_VarName(varName) {}

    bool Execute(CMemory &memory) override;

private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDINVERSE_H
