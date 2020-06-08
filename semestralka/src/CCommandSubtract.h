//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDSUBTRACT_H
#define SEMESTRALKA_CCOMMANDSUBTRACT_H


#include "CMatrix.h"
#include "CCommand.h"
#include "CSubtractOperator.h"

class CCommandSubtract : public CCommand {
public:
    CCommandSubtract() : CCommand() {}

    ~CCommandSubtract() override = default;

    CCommandSubtract(string operand1, string operand2) : m_Operand1(std::move(operand1)),
                                                         m_Operand2(std::move(operand2)) {}

    bool Execute(CMemory &memory) override {
        if (!memory.ExistsVariable(m_Operand1) || !memory.ExistsVariable(m_Operand2)) {
            m_Result = "Variables do not exist.";
            return false;
        }
        m_Result = "Result of subtraction is:\n";
        CSubtractOperator op(memory.At(m_Operand1), memory.At(m_Operand2));
        try {
            m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
            m_Result += m_ResultMatrix->ToString();
            return true;
        } catch (const std::runtime_error &e) {
            m_Result = "Matrices " + m_Operand1 + " and " + m_Operand2 + " are not compatible for subtraction.";
            return false;
        }
    }

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDSUBTRACT_H