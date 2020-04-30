//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <memory>
#include <sstream>
#include "CApplication.h"
#include "CMatrixSparse.h"
#include "CCommandLoad.h"
#include "CCommandPrint.h"
#include "CCommandAdd.h"
#include "CCommandSubtract.h"
#include "CCommandMultiply.h"
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
    bool ParseCommandWord(string & input, string & in_command){

        std::string::size_type semicolonPosition;
        semicolonPosition = input.find(":");
        if(semicolonPosition == std::string::npos){
            return false;
        }
        in_command = input.substr(0,semicolonPosition);
        input = input.substr(semicolonPosition+1);
        return true;
    }
    bool ParseCommand(string &input, unique_ptr<CCommand> &nextCommand) override {
        string in_command;
        if(!ParseCommandWord(input, in_command)){
            return false;
        }

        if(in_command=="load"){
            string varName;
            vector<vector<double>>matrixNums;
            if(!ParseLoading(input, varName, matrixNums)){
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandLoad>(new CCommandLoad(varName,matrixNums))));
        }else if(in_command == "print") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 1)) {
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandPrint>(new CCommandPrint(operands[0]))));
        }else if(in_command == "add") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 2)) {
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandAdd>(new CCommandAdd(operands[0], operands[1]))));
        }else if(in_command == "subtract") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 2)) {
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandSubtract>(new CCommandSubtract(operands[0], operands[1]))));
        }else if(in_command == "multiply") {
            vector<string> operands;
            if (!ParseOperands(input, operands, 2)) {
                return false;
            }
            stringstream inStream(input);
            if(!(IsSyntaxCorrect(inStream))) {
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandMultiply>(new CCommandMultiply(operands[0], operands[1]))));
        }else if(in_command == "put"){
            string name;
            if(!LoadOperandName(input, name)){
                return false;
            }
            unique_ptr<CCommand> subCommand;
            if(!ParseCommand(input, subCommand)){
                return false;
            }
            nextCommand = (move(std::unique_ptr<CCommandPut>(new CCommandPut(name, subCommand))));

        }
//        }else if(in_command == "add"){
//            command.m_Command = ADD;
//            if(!ParseOperands(input, command,2)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//        }else if(in_command == "subtract"){
//            command.m_Command = SUBTRACT;
//            if(!ParseOperands(input, command,2)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//        }else if(in_command == "multiply"){
//            command.m_Command = MULTIPLY;
//            if(!ParseOperands(input, command,2)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//        }else if(in_command == "transpose"){
//            command.m_Command = TRANSPOSE;
//            if(!ParseOperands(input, command,1)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//            return true;
//        }else if(in_command == "cut"){
//            command.m_Command = CUT;
//            if(!ParseCutting(input, command)){
//                return false;
//            }
//        }else if(in_command == "put"){
//            command.m_Command = PUT;
//            string name;
//            if(!LoadOperandName(input, name)){
//                command.m_Result = "Could not load variable name.";
//            }
//            command.m_Operands.push_back(name);
//            return true;
//        }else if(in_command == "merge_under"){
//            command.m_Command = MERGE_UNDER;
//            if(!ParseOperands(input, command,2)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//        }else if(in_command == "merge_next_to"){
//            command.m_Command = MERGE_NEXT_TO;
//            if(!ParseOperands(input, command,2)){
//                return false;
//            }
//            stringstream inStream(input);
//            if(!(IsSyntaxCorrect(inStream))) {
//                command.m_Result = "Command not properly ended.";
//                return false;
//            }
//        }
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
    bool ParseLoading(string &input, string & varName, vector<vector<double>> &matrixNums ){
        if(!getVariableName(input, varName)){
            return false;
        }
        stringstream inStream(input);
        size_t numRows;
        size_t  numCols;
        if(!ReadSize(numRows, numCols, inStream)){
            return false;
        }
        matrixNums.resize(numRows);
        if(!ReadMatrix(inStream, matrixNums, numRows, numCols)){
            return false;
        }
        if(!(IsSyntaxCorrect(inStream))){
            return false;
        }
        return true;
    }

    bool ParseOperands(string &input, vector<string> &operands, std::size_t numOfOperands = 1){
        for(size_t i = 0;i<numOfOperands;i++){
            string name;
            if(!LoadOperandName(input, name)){
                return false;
            }
            operands.push_back(name);
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


};


#endif //SEMESTRALKA_CAPPLICATIONCONSOLE_H
