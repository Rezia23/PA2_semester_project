//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <sstream>
#include "CApplication.h"
#include "CMatrixSparse.h"
using namespace std;

class CApplicationConsole : public CApplication{
public:
    CApplicationConsole():CApplication(){};
    ~CApplicationConsole() override = default;
    void PrintInstructions() const override{
        cout<<"some shit"<<endl;
    }
private:
    string GetInput() const override;

    void ShowMsg(string msg)const override{
        cout<<msg<<endl;
    }
   void ShowVarName(string name)const override{
        cout<<name<<":"<< endl;
    }
   void ShowMatrix(unique_ptr<CMatrix> & matrix)const override{
        //to be corrected
        matrix->Print();
    }

    bool getVariableName(string & input, string & varName) const ;
    bool ReadSize(std::size_t & numRows, std::size_t & numCols,istream & inStream) const ;
    bool ReadMatrix(istream & inStream,vector<vector<double>> & matrix, size_t numRows, size_t numCols) const ;
    bool IsSyntaxCorrect(istream & inStream)const {
        char delimiter;
        return (inStream>>delimiter) && delimiter==';';
    }
    void ShowResult(string result){
        cout<<result<<endl;
    }
    bool ParseCommand(string &input, CApplication::s_Command &command) override {

        std::string::size_type semicolonPosition;
        semicolonPosition = input.find(":");
        if(semicolonPosition == std::string::npos){
            return false;
        }
        string in_command = input.substr(0,semicolonPosition);
        input = input.substr(semicolonPosition+1);
        if(in_command == "print"){
            command.m_Command = PRINT;
            if(!ParseOperands(input, command,1)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
            return true;
        }else if(in_command=="load"){
            command.m_Command = LOAD;
            if(!ParseLoading(input, command)){
                return false;
            }
        }else if(in_command == "add"){
            command.m_Command = ADD;
            if(!ParseOperands(input, command,2)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
        }else if(in_command == "subtract"){
            command.m_Command = SUBTRACT;
            if(!ParseOperands(input, command,2)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
        }else if(in_command == "multiply"){
            command.m_Command = MULTIPLY;
            if(!ParseOperands(input, command,2)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
        }else if(in_command == "transpose"){
            command.m_Command = TRANSPOSE;
            if(!ParseOperands(input, command,1)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
            return true;
        }else if(in_command == "cut"){
            command.m_Command = CUT;
            if(!ParseCutting(input, command)){
                return false;
            }
        }else if(in_command == "put"){
            command.m_Command = PUT;
            string name;
            if(!LoadOperandName(input, name)){
                command.m_Result = "Could not load variable name.";
            }
            command.m_Operands.push_back(name);
            return true;
        }else if(in_command == "merge_under"){
            command.m_Command = MERGE_UNDER;
            if(!ParseOperands(input, command,2)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
        }else if(in_command == "merge_next_to"){
            command.m_Command = MERGE_NEXT_TO;
            if(!ParseOperands(input, command,2)){
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                command.m_Result = "Command not properly ended.";
                return false;
            }
        }
//        else if(in_command == "put"){
//            command.m_Command = PUT;
//        }
        //////////tbd
        return true;
    }
    bool LoadOperandName(string & input, string & name){
        std::string::size_type spacePosition;
        spacePosition = input.find(" ");
        if(spacePosition == std::string::npos){
            return false;
        }
        name = input.substr(0, spacePosition);
        if(name==""){
            return false;
        }
        input = input.substr(spacePosition+1);
        return true;
    }
    bool ParseOperands(string &input, s_Command &command, std::size_t numOfOperands = 1){

        for(size_t i = 0;i<numOfOperands;i++){
            string name;
            if(!LoadOperandName(input, name)){
                command.m_Result = "Could not load variable name.";
                return false;
            }
            command.m_Operands.push_back(name);
        }
        return true;
    }
    bool ParseCutting(string &input, s_Command &command){
        string varName;
        if(!getVariableName(input, varName)){
            command.m_Result = "Could not get variable name.";
            return false;
        }
        command.m_Operands.push_back(varName);
        stringstream inStream(input);
        size_t numRows;
        size_t  numCols;
        if(!ReadSize(numRows, numCols, inStream)){
            command.m_Result = "Could not read size of matrix.";
        }
        command.m_Size.first=numRows;
        command.m_Size.second=numCols;
        if(!(inStream>>command.m_StartPoint.first) || !(inStream>>command.m_StartPoint.second)){
            return false;
        }
        if(!(IsSyntaxCorrect(inStream))){
            command.m_Result = "Command not properly ended.";
            return false;
        }
        return true;
    }
    bool ParseLoading(string &input, s_Command &command){
        string varName;
        if(!getVariableName(input, varName)){
            command.m_Result = "Could not get variable name.";
            return false;
        }
        stringstream inStream(input);
        size_t numRows;
        size_t  numCols;
        if(!ReadSize(numRows, numCols, inStream)){
            command.m_Result = "Could not read size of matrix.";
        }
        vector<vector<double>> matrix(numRows);
        if(!ReadMatrix(inStream, matrix, numRows, numCols)){
            command.m_Result = "Could not read numbers of matrix.";
            return false;
        }
        if(!(IsSyntaxCorrect(inStream))){
            command.m_Result = "Command not properly ended.";
            return false;
        }

        command.m_ResultMatrix = (make_unique<CMatrixStandard>(CMatrixStandard(matrix)));
        if(command.m_ResultMatrix->ShouldBeSparse()){
            command.m_ResultMatrix = unique_ptr<CMatrix>(command.m_ResultMatrix->Convert());
        }
        command.m_Operands.push_back(varName);
        command.m_Result = "Matrix " + varName + " was loaded.";
        return true;
    }



};


#endif //SEMESTRALKA_CAPPLICATIONCONSOLE_H
