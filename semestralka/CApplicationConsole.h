//
// Created by terez on 27.04.2020.
//

#ifndef SEMESTRALKA_CAPPLICATIONCONSOLE_H
#define SEMESTRALKA_CAPPLICATIONCONSOLE_H

#include <cstdio>
#include <sstream>
#include "CApplication.h"
using namespace std;

class CApplicationConsole : public CApplication{
public:
    CApplicationConsole():CApplication(){};
    ~CApplicationConsole() override = default;
    void PrintInstructions() const override{
        cout<<"some shit";
    }
    string GetInput() const override {
        string input;
        getline(cin, input);
        return input;
    }
    bool ParseCommand(string & input, e_Command &command)override {
        std::string::size_type semicolonPosition;
        semicolonPosition = input.find(":");
        if(semicolonPosition == std::string::npos){
            return false;
        }
        string in_command = input.substr(0,semicolonPosition);
        input = input.substr(semicolonPosition+1);
        if(in_command=="load"){
            command = LOAD;
        }else if(in_command == "add"){
            command = ADD;
        }
        //////////tbd
        return true;
    }

};


#endif //SEMESTRALKA_CAPPLICATIONCONSOLE_H
