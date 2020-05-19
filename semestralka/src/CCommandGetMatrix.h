//
// Created by terez on 19.05.2020.
//

#ifndef SEMESTRALKA_CCOMMANDGETMATRIX_H
#define SEMESTRALKA_CCOMMANDGETMATRIX_H


#include "CMatrix.h"
#include "CCommand.h"

class CCommandGetMatrix: public CCommand {
public:
    unique_ptr<CMatrix> m_ResultMatrix;
};


#endif //SEMESTRALKA_CCOMMANDGETMATRIX_H
