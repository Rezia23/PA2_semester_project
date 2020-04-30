//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATION_H
#define SEMESTRALKA_CAPPLICATION_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <sstream>
#include "CMatrix.h"
#include "CMatrixStandard.h"
#include "CCommand.h"

class CApplication {

public:
    enum e_Command {LOAD1, ADD, SUBTRACT, TRANSPOSE, MULTIPLY, PUT, PRINT, MERGE_UNDER, MERGE_NEXT_TO, CUT}; //tbd others
    struct s_Command{
        e_Command m_Command;
        vector<string> m_Operands;
        string m_Result;
        unique_ptr<CMatrix> m_ResultMatrix;
        pair<std::size_t, std::size_t> m_StartPoint;
        pair<std::size_t, std::size_t> m_Size;
    };
protected:
    map<string,unique_ptr<CMatrix>> m_Variables;
    virtual void PrintInstructions()const = 0;
    virtual string GetInput()const = 0;
//    virtual bool getVariableName(string & input, string & varName) const = 0;
//    virtual bool ReadSize(std::size_t & numRows, std::size_t & numCols,istream & inStream) const = 0;
//    virtual bool ReadMatrix(istream & inStream,vector<vector<double>> & matrix, size_t numRows, size_t numCols) const = 0;
//    virtual bool IsSyntaxCorrect(istream & inStream) const = 0;


    virtual bool ParseCommand(string & input, unique_ptr<CCommand> & nextCommand) = 0;

    bool AddMatrices(string input, string & result){

        //check addition conditions

        return true;
    }

    virtual void ShowResult(string result) = 0;
    bool existsVariable(string name) const{
        return m_Variables.find(name)!=m_Variables.end();
    }
public:


    CApplication() = default;
    virtual ~CApplication() = default;


    bool Evaluate(string input, string & result, s_Command &command, unique_ptr<CCommand> & nextCommand){

        if(!ParseCommand(input, nextCommand)){
            result = "Command could not be parsed.";
            return false;
        }
        if(!nextCommand->Execute(m_Variables)){
            result = nextCommand->m_Result;
            return false;
        }
        result = nextCommand->m_Result;
//        if(command.m_Command == PRINT){
//            if(m_Variables.find(command.m_Operands[0])==m_Variables.end()){
//                result = "Cannot print non existent variable.";
//                return false;
//            }
//            result = m_Variables.at(command.m_Operands[0])->ToString();
//            return true;
//        }else if(nextCommand->m_CommandName == CCommand::LOAD){
//           if(m_Variables.find(nextCommand->m_VariableName)!=m_Variables.end()){
//               result = "Cannot create variable with same name as existing.";
//               return false;
//           }
//           m_Variables.insert(make_pair(command.m_Operands[0], move(command.m_ResultMatrix)));
//           result = command.m_Result;
//           return true;
//        } else if(command.m_Command== ADD){
//           if(!existsVariable(command.m_Operands[0]) || !existsVariable(command.m_Operands[1])){
//               result = "Variables do not exist.";
//               return false;
//           }
//           result = "Result of addition is:\n";
//           command.m_ResultMatrix = unique_ptr<CMatrix> (m_Variables.find(command.m_Operands[0])->second->Add(m_Variables.find(command.m_Operands[1])->second));
//           result += command.m_ResultMatrix->ToString();
//           return true;
//        }else if(command.m_Command== SUBTRACT){
//           if(!existsVariable(command.m_Operands[0]) || !existsVariable(command.m_Operands[1])){
//               result = "Variables do not exist.";
//               return false;
//           }
//           result = "Result of subtraction is:\n";
//           command.m_ResultMatrix = unique_ptr<CMatrix> (m_Variables.find(command.m_Operands[0])->second->Subtract(m_Variables.find(command.m_Operands[1])->second));
//           result += command.m_ResultMatrix->ToString();
//           return true;
//       }else if(command.m_Command== MULTIPLY){
//           if(!existsVariable(command.m_Operands[0]) || !existsVariable(command.m_Operands[1])){
//               result = "Variables do not exist.";
//               return false;
//           }
//           result = "Result of multiplication is:\n";
//           command.m_ResultMatrix = unique_ptr<CMatrix> (m_Variables.find(command.m_Operands[0])->second->Multiply(m_Variables.find(command.m_Operands[1])->second));
//           result += command.m_ResultMatrix->ToString();
//       }else if(command.m_Command== TRANSPOSE){
//           if(!existsVariable(command.m_Operands[0])){
//               result = "Variable does not exist.";
//               return false;
//           }
//           m_Variables.find(command.m_Operands[0])->second->Transpose();
//           result = command.m_Operands[0] + " has been transposed:\n";
//           result+=m_Variables.find(command.m_Operands[0])->second->ToString();
//       }else if(command.m_Command== CUT){
//            if(!existsVariable(command.m_Operands[0])){
//                result = "Variable does not exist.";
//                return false;
//            }
//            m_Variables.find(command.m_Operands[0])->second->Cut(command.m_Size.first, command.m_Size.second, command.m_StartPoint);
//            result = command.m_Operands[0] + " has been cut:\n";
//            result+=m_Variables.find(command.m_Operands[0])->second->ToString();
//        }else if(command.m_Command== PUT){
//           if(m_Variables.find(command.m_Operands[0])==m_Variables.end()){
//               result = "Variable does not exist.";
//               return false;
//           }
//           s_Command subCommand;
//           if(!Evaluate(input, result, subCommand)){
//               return false;
//           }
//           m_Variables.at(command.m_Operands[0]) = (move(subCommand.m_ResultMatrix));
//       }else if(command.m_Command== MERGE_UNDER){
//            if(!existsVariable(command.m_Operands[0]) || !existsVariable(command.m_Operands[1])){
//                result = "Variables do not exist.";
//                return false;
//            }
//            result = "Result is:\n";
//            command.m_ResultMatrix = unique_ptr<CMatrix> (m_Variables.find(command.m_Operands[0])->second->MergeUnder(m_Variables.find(command.m_Operands[1])->second));
//            result += command.m_ResultMatrix->ToString();
//        }else if(command.m_Command== MERGE_NEXT_TO){
//            if(!existsVariable(command.m_Operands[0]) || !existsVariable(command.m_Operands[1])){
//                result = "Variables do not exist.";
//                return false;
//            }
//            result = "Result is:\n";
//            command.m_ResultMatrix = unique_ptr<CMatrix> (m_Variables.find(command.m_Operands[0])->second->MergeNextTo(m_Variables.find(command.m_Operands[1])->second));
//            result += command.m_ResultMatrix->ToString();
//        }
        //if addition... AddMatrices(mat1, mat2)
        //.........
        //
        return true;
    }

    void Run(){
        while(true){
            string input = GetInput();
            if(input == "exit ;"){
                ShowMsg("Closing the app.");
                break;
            }
            string result;
            s_Command command;
            unique_ptr<CCommand> nextCommand;
            if(!Evaluate(input, result, command, nextCommand)){
//            //  ShowWrongInputMessage();
//            //  continue;
                cout<<"wrong wrong";
              }

//            if(m_Variables.at("asd"))
            //ShowVariables();
            ShowResult(result);

        }
    }

    virtual void ShowVarName(string name) const= 0;
    virtual void ShowMatrix(unique_ptr<CMatrix> & matrix) const= 0;
    virtual void ShowMsg(string msg) const= 0;
    void ShowVariables() const{
        if(m_Variables.size()==0){
            ShowMsg("No variables to be shown.");
        }
        for(auto a = m_Variables.begin(); a!=m_Variables.end();a++){
            ShowVarName(a->first);
            //getstring representation
            //show
            a->second->Print();
        }
    }
};


#endif //SEMESTRALKA_CAPPLICATION_H
