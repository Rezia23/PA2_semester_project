//
// Created by terez on 19.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDCUTDESTRUCTIVE_H
#define SEMESTRALKA_CCOMMANDCUTDESTRUCTIVE_H

#include "CCommandCut.h"

class CCommandCutDestructive : public CCommandCut {
public:
    CCommandCutDestructive(string varName, std::size_t numRows, size_t numCols,
                           pair<std::size_t, std::size_t> startPoint)
            : CCommandCut(varName, numRows, numCols, startPoint) {}

    bool Execute(CMemory &memory) override;
};


#endif //SEMESTRALKA_CCOMMANDCUTDESTRUCTIVE_H
