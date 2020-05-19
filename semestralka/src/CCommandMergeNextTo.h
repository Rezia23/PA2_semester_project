//
// Created by terez on 30.04.2020.
//

#ifndef SEMESTRALKA_CCOMMANDMERGENEXTTO_H
#define SEMESTRALKA_CCOMMANDMERGENEXTTO_H

#include "CCommand.h"
#include "CMergeNextToOperation.h"

class CCommandMergeNextTo : public CCommand {
public:
    CCommandMergeNextTo() : CCommand() {}

    ~CCommandMergeNextTo() override = default;

    CCommandMergeNextTo(string operand1, string operand2) : m_Operand1(operand1), m_Operand2(operand2) {}

    bool Execute(CMemory & memory) override {
        if (!memory.ExistsVariable(m_Operand1) || !memory.ExistsVariable(m_Operand2)) {
            m_Result = "Variables do not exist.";
            return false;
        }
        m_Result = "Result of merge is:\n";
        CMergeNextToOperator op (memory.At(m_Operand1),memory.At(m_Operand2));
        try{
            m_ResultMatrix = unique_ptr<CMatrix>(op.Evaluate(memory));
            m_Result += m_ResultMatrix->ToString();
            return true;
        }catch(const std::runtime_error& e){
            m_Result = "Matrices " + m_Operand1 + " and " + m_Operand2 + " are not compatible for merging.";
            return false;
        }
    }

private:
    string m_Operand1;
    string m_Operand2;
};


#endif //SEMESTRALKA_CCOMMANDMERGENEXTTO_H
