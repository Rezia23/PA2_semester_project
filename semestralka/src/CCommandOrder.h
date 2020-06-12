//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDORDER_H
#define SEMESTRALKA_CCOMMANDORDER_H

#include "CCommand.h"
#include "COrderCalculator.h"

class CCommandOrder : public CCommand {
public:
    CCommandOrder() : CCommand() {}

    ~CCommandOrder() override = default;

    CCommandOrder(string varName) : m_VarName(varName) {}

    bool Execute(CMemory &memory) override;

    int m_Order;
private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDORDER_H
