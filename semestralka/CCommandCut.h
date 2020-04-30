//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDCUT_H
#define SEMESTRALKA_CCOMMANDCUT_H

#include <utility>

#include "CCommand.h"

class CCommandCut:public CCommand {
public:
    CCommandCut() : CCommand() {}

    ~CCommandCut() override = default;

    CCommandCut(string varName, std::size_t numRows, size_t numCols, pair<std::size_t, std::size_t> startPoint)
    : m_VarName(std::move(varName)), m_NumRows(numRows), m_NumCols(numCols), m_StartPoint(startPoint) {}

    bool Execute(map<string, unique_ptr<CMatrix>> &variables) override {
        if (!ExistsVariable(m_VarName, variables)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix" + m_VarName + " has been cut to:\n";
        (variables.at(m_VarName)->Cut(m_NumRows, m_NumCols, m_StartPoint));
        m_ResultMatrix = unique_ptr<CMatrix>(variables.at(m_VarName)->Clone());
        m_Result += m_ResultMatrix->ToString();
        return true;
    }

private:
    string m_VarName;
    std::size_t m_NumRows{};
    std::size_t m_NumCols{};
    pair<std::size_t, size_t> m_StartPoint;
};


#endif //SEMESTRALKA_CCOMMANDCUT_H
