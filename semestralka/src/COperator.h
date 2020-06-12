//
// Created by terez on 05.05.2020.
//

#ifndef SEMESTRALKA_COPERATOR_H
#define SEMESTRALKA_COPERATOR_H


class COperator {
public:
    COperator() = default;

    virtual ~COperator() = default;

    /**
     * Evaluate matrix operation.
     * @param memory memory with variables
     * @return result of operation
     * @throw exception operation could not be performed
     */
    virtual class CMatrix *Evaluate() = 0;
};


#endif //SEMESTRALKA_COPERATOR_H
