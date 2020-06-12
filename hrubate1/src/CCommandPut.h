//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDPUT_H
#define SEMESTRALKA_CCOMMANDPUT_H

#include "CCommand.h"
#include "CMatrixStandard.h"

class CCommandPut : public CCommand {
public:
    CCommandPut() : CCommand() {}

    ~CCommandPut() override = default;

    CCommandPut(string varName, unique_ptr<CCommand> &subCommand) : m_VariableName(varName),
                                                                    m_Subcommand(move(subCommand)) {}

    bool Execute(CMemory &memory) override;

private:
    string m_VariableName;
    unique_ptr<CCommand> m_Subcommand;
};


#endif //SEMESTRALKA_CCOMMANDPUT_H
