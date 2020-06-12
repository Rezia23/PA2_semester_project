//
// Created by hrubate1 on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMAND_H
#define SEMESTRALKA_CCOMMAND_H

#include <string>
#include "CMatrix.h"
#include <map>
#include "CMemory.h"

class CCommand {

public:
    string m_Result;
    unique_ptr<CMatrix> m_ResultMatrix = nullptr;

    CCommand() = default;

    /**
     * Execute command.
     * @param memory
     * @return true if execution successful, false otherwise (command cannot be performed)
     */
    virtual bool Execute(CMemory &memory) = 0;

    virtual ~CCommand() = default;


};


#endif //SEMESTRALKA_CCOMMAND_H
