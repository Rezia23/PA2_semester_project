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
    map<string, shared_ptr<class CMatrix>> m_Variables;

    CMemory() = default;

    ~CMemory() = default;

    bool ExistsVariable(string name) const {
        return m_Variables.find(name) != m_Variables.end();
    }

    shared_ptr<CMatrix> &At(const string &name) {
        return m_Variables.at(name);
    }

    void Insert(const string &name, shared_ptr<CMatrix> matrix) {
        if (ExistsVariable(name)) {
            m_Variables.at(name) = matrix;
        } else {
            m_Variables[name] = matrix;
        }
    }

};


#endif //SEMESTRALKA_CMEMORY_H
