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

    bool Execute(CMemory &memory) override {
        if (!memory.ExistsVariable(m_VarName)) {
            m_Result = "Variable does not exist.";
            return false;
        }
        m_Result = "Matrix " + m_VarName + " would be cut to:\n";
        shared_ptr<CMatrix> result = shared_ptr<CMatrix>(memory.At(m_VarName)->Clone());
        CCutOperator op(result, m_NumRows, m_NumCols, m_StartPoint);
        try {
            m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
            m_Result += m_ResultMatrix->ToString();
            return true;
        } catch (const std::runtime_error &e) {
            m_Result = "Matrix " + m_VarName + " cannot be cut.";
            return false;
        }
    }

protected:
    string m_VarName;
    std::size_t m_NumRows{};
    std::size_t m_NumCols{};
    pair<std::size_t, size_t> m_StartPoint;
};


#endif //SEMESTRALKA_CCOMMANDCUT_H
