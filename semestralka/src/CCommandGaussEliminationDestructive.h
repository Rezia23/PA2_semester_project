//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H
#define SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H


#include "CCommandGaussElimination.h"


class CCommandGaussEliminationDestructive : public CCommandGaussElimination {
public:
    bool Execute(CMemory &memory) override;

    CCommandGaussEliminationDestructive(string varName) : CCommandGaussElimination(varName) {}


};


#endif //SEMESTRALKA_CCOMMANDGAUSSELIMINATIONDESTRUCTIVE_H
