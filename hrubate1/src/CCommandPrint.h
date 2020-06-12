//
// Created by hrubate1 on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDPRINT_H
#define SEMESTRALKA_CCOMMANDPRINT_H

#include "CCommand.h"

class CCommandPrint : public CCommand {
public:
    CCommandPrint() : CCommand() {}

    ~CCommandPrint() override = default;

    CCommandPrint(string varName) : CCommand(), m_VariableName(varName) {}

    bool Execute(CMemory &memory) override;

private:
    string m_VariableName;

};


#endif //SEMESTRALKA_CCOMMANDPRINT_H
