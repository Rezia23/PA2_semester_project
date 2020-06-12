//
// Created by hrubate1 on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDTRANSPOSE_H
#define SEMESTRALKA_CCOMMANDTRANSPOSE_H

#include "CCommand.h"
#include "CTransposeOperator.h"

class CCommandTranspose : public CCommand {
public:
    CCommandTranspose() : CCommand() {}

    ~CCommandTranspose() override = default;

    CCommandTranspose(string varName) : m_VarName(varName) {}

    bool Execute(CMemory &memory) override;

protected:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDTRANSPOSE_H
