//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDORDER_H
#define SEMESTRALKA_CCOMMANDORDER_H

#include "CCommand.h"
#include "GetOrder.h"

class CCommandOrder:public CCommand {
public:
    CCommandOrder() : CCommand() {}

    ~CCommandOrder() override = default;

    CCommandOrder(string varName) : m_VarName(varName) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " has order:\n";

        GetOrder order;
        m_Order = order(memory.m_Variables.at(m_VarName));
        m_Result += to_string(m_Order);
        return true;

    }
    int m_Order;
private:
    string m_VarName;
};


#endif //SEMESTRALKA_CCOMMANDORDER_H
