//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDCUT_H
#define SEMESTRALKA_CCOMMANDCUT_H

#include <utility>

#include "CCommand.h"
#include "CCutOperator.h"

class CCommandCut : public CCommand {
public:
    CCommandCut() : CCommand() {}

    ~CCommandCut() override = default;

    CCommandCut(string varName, std::size_t numRows, size_t numCols, pair<std::size_t, std::size_t> startPoint)
            : m_VarName(std::move(varName)), m_NumRows(numRows), m_NumCols(numCols), m_StartPoint(startPoint) {}

    bool Execute(CMemory &memory) override;

protected:
    string m_VarName;
    std::size_t m_NumRows{};
    std::size_t m_NumCols{};
    pair<std::size_t, size_t> m_StartPoint;
};


#endif //SEMESTRALKA_CCOMMANDCUT_H
