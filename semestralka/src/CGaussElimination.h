//
// Created by terez on 07.05.2020.
//

#ifndef SEMESTRALKA_CGAUSSELIMINATION_H
#define SEMESTRALKA_CGAUSSELIMINATION_H


#include <iostream>
#include "CMatrix.h"
#include "elimination.h"




class CGaussElimination{
public:
    void operator()(shared_ptr<CMatrix> & matrix, vector<shared_ptr<CMatrix>> & eliminationProcess){
        std::cout<<"in\n";
        matrix->Print();
        eliminationProcess.push_back(matrix);
        SortForElimination(matrix);
        eliminationProcess.push_back(matrix);
        for (size_t i = 0; i < matrix->m_NumRows; i++) {
            for (size_t j = 0; j < matrix->m_NumRows; j++) {
                if (i < j) {
                    double temp = matrix->GetNumAtCoords(j, i);
                    for (size_t k = 0; k < matrix->m_NumCols; k++) {
                        matrix->SetNumAtCoords(j,k, matrix->GetNumAtCoords(j,k)*matrix->GetNumAtCoords(i,i));
                        matrix->SetNumAtCoords(j, k, matrix->GetNumAtCoords(j, k)-(matrix->GetNumAtCoords(i,k)*temp));
                    }
                    eliminationProcess.push_back(matrix);
                }
            }
        }
    }
};


#endif //SEMESTRALKA_CGAUSSELIMINATION_H
