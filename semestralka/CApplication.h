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
class CApplication {
protected:
    map<string,unique_ptr<CMatrix>> m_Variables;
    enum e_Command {LOAD, ADD}; //tbd others
public:
    CApplication() = default;
    virtual ~CApplication() = default;
    virtual void PrintInstructions()const = 0;
    virtual string GetInput()const = 0;
    bool LoadMatrices(string input, string result){
        //tbd read name of variable
        //to be read size
        size_t numRows;
        size_t  numCols;
        stringstream inStream(input);
        //readSize()
        //readName()
        //readMatrix()
        char c;
        if(!(inStream >> c) || c!='s'){
            return false;
        }
        inStream>>numRows;
        inStream>>numCols;
        vector<vector<double>> matrix(numRows);
        for(size_t i = 0;i<numRows;i++){
            for(size_t j = 0; j<numCols;j++){
                double nextNum;
                //if se nenacte atd.
                inStream>>nextNum;
                matrix[i].push_back(nextNum);
            }
        }
        m_Variables[string("asd")] = (make_unique<CMatrixStandard>(CMatrixStandard(matrix)));
        result = "succesfully loaded\n";
        return true;
        //TODO parse mtf input!!!!!!!!

        //to be metoda ParseMatrix

    }
    bool Evaluate(string input, string & result){
        e_Command command;
        if(!ParseCommand(input, command)){
            return false;
        }
        if(command == LOAD){
            if(!LoadMatrices(input, result)){
                return false;
            }
            return true;
        }
        //if addition... AddMatrices(mat1, mat2)
        //.........
        //
        return true;
    }
    virtual bool ParseCommand(string & input, e_Command &command) = 0;
    void Run(){
        while(true){
            string input = GetInput();
            string result;
            if(!Evaluate(input, result)){
//            //  ShowWrongInputMessage();
//            //  continue;
                cout<<"wrong wrong";
              }
//            if(m_Variables.at("asd"))
            m_Variables["asd"]->Print();
            //ShowResult(result);
        }
    }
};


#endif //SEMESTRALKA_CAPPLICATION_H
