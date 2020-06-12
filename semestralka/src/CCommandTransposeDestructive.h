//
// Created by terez on 19.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H
#define SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H

#include "CCommandTranspose.h"

class CCommandTransposeDestructive : public CCommandTranspose {
public:
    bool Execute(CMemory &memory) override;

    CCommandTransposeDestructive(string varName) : CCommandTranspose(varName) {}

};


#endif //SEMESTRALKA_CCOMMANDTRANSPOSEDESTRUCTIVE_H
