//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDPRINT_H
#define SEMESTRALKA_CCOMMANDPRINT_H

#include "CCommand.h"

class CCommandPrint:public CCommand {
public:
    CCommandPrint():CCommand(){}
    ~CCommandPrint() override = default;
    CCommandPrint(string varName):CCommand(),m_VariableName(varName){}
    bool Execute(map<string, unique_ptr<CMatrix>> &variables)override{
        if(!ExistsVariable(m_VariableName, variables)){
            m_Result = "Variable " + m_VariableName + " does not exist.";
            return false;
        }
        m_Result = variables.at(m_VariableName)->ToString();
        return true;
    }
private:
    string m_VariableName;

};


#endif //SEMESTRALKA_CCOMMANDPRINT_H
