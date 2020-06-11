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

    /**
     * Check if variable exists in memory.
     * @param name variable name to be checked
     * @return true if exists, false otherwise
     */
    bool ExistsVariable(const string &name) const {
        return m_Variables.find(name) != m_Variables.end();
    }

    /**
     * Access variable by name.
     * @param name variable name
     * @return found matrix
     * @throw exception variable does not exist
     */
    shared_ptr<CMatrix> &At(const string &name);

    /**
     * Insert variable into memory, replace if variable with such name already exists.
     * @param name variable name
     * @param matrix matrix to be inserted
     */
    void Insert(const string &name, shared_ptr<CMatrix> matrix);
};


#endif //SEMESTRALKA_CMEMORY_H
