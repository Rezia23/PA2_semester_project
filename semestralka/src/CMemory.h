//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_CMEMORY_H
#define SEMESTRALKA_CMEMORY_H

#include <string>
#include <map>
#include <memory>

using namespace std;
class CMemory {
public:
    map<string, unique_ptr<class CMatrix>> m_Variables;
    CMemory() = default;
    ~CMemory() = default;

    bool ExistsVariable(string name) const {
        return m_Variables.find(name) != m_Variables.end();
    }
};


#endif //SEMESTRALKA_CMEMORY_H
