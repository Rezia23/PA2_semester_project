//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMAND_H
#define SEMESTRALKA_CCOMMAND_H

#include <string>
#include "CMatrix.h"
#include <map>

class CCommand {

public:
    string m_Result;
    CCommand() = default;
    virtual bool Execute(map<string, unique_ptr<CMatrix>> &variables) = 0;
    virtual ~CCommand() = default;
    bool ExistsVariable(string name, map<string, unique_ptr<CMatrix>> & variables) const{
        return variables.find(name)!=variables.end();
    }



};


#endif //SEMESTRALKA_CCOMMAND_H
