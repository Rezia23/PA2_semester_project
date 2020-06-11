//
// Created by terez on 07.05.2020.
//

#include <iostream>
#include "elimination.h"


int SortForElimination(shared_ptr<CMatrix> &matrix) {
    int numSwaps = 0;
    bool isChange = true;
    while (isChange) {
        isChange = false;
        for (size_t i = matrix->GetNumRows() - 1; i > 0; i--) {
            double val1 = matrix->GetNumAtCoords(i - 1, 0);
            double val2 = matrix->GetNumAtCoords(i, 0);
            if (abs(val1) < abs(val2)) {
                matrix->SwapRows(i - 1, i);
                numSwaps++;
                isChange = true;
            } else if(val1 == val2 && IsZero(val1)){
                std::size_t column = 0;
                while(val1 == val2 && IsZero(val1) && column<matrix->GetNumCols()){
                    val1 = matrix->GetNumAtCoords(i-1,column);
                    val2 = matrix->GetNumAtCoords(i, column);
                    column++;
                }
                if(IsZero(val1) && !IsZero(val2)){
                    matrix->SwapRows(i - 1, i);
                    numSwaps++;
                    isChange = true;
                }
            }
        }
    }
    return numSwaps;
}
double FindFirstNonZero(size_t rowFirst,size_t rowSecond, size_t &column, shared_ptr<CMatrix> &matrix) {
    double temp = matrix->GetNumAtCoords(rowSecond, column);
    while(IsZero(matrix->GetNumAtCoords(rowFirst,column)) && IsZero(temp) && column+1<matrix->GetNumCols()){
        column++;
        temp = matrix->GetNumAtCoords(rowSecond, column);
    }
    return temp;
}
bool SubtractRows(shared_ptr<CMatrix> &matrix, size_t firstNonZeroColumn, double multipleToSubtract, size_t rowToBeChanged, size_t subtractingRow) {
    int maxNum = 1000;
    int divideBy = 1;
    int divideSubtractingRow = 1;
    if(IsZero(multipleToSubtract)){
        return false;
    }
    if(abs(multipleToSubtract)>=maxNum){
        multipleToSubtract/=maxNum;
        divideBy = maxNum;
    }
    if(abs(matrix->GetNumAtCoords(subtractingRow,firstNonZeroColumn))>=maxNum){
        cout<<"it is";
        divideSubtractingRow = maxNum/10;
    }
    for (size_t k = 0; k < matrix->GetNumCols(); k++) {
        matrix->SetNumAtCoords(rowToBeChanged, k, matrix->GetNumAtCoords(rowToBeChanged, k)/divideBy * matrix->GetNumAtCoords(subtractingRow, firstNonZeroColumn)/divideSubtractingRow);
        matrix->SetNumAtCoords(rowToBeChanged, k, matrix->GetNumAtCoords(rowToBeChanged, k) - (matrix->GetNumAtCoords(subtractingRow, k)/divideSubtractingRow * multipleToSubtract));
    }
    return true;
}

bool IsZero(double number) {
    return abs(number)<=10e-7 * abs(number);
}

void Gem(shared_ptr<CMatrix> &matrix, vector<shared_ptr<CMatrix>> &eliminationProcess) {
    bool wasMadeChange;
    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));
    SortForElimination(matrix);
    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));

    for (size_t i = 0; i < matrix->GetNumRows(); i++) {
        for (size_t j = 0; j < matrix->GetNumRows(); j++) {
            if (i < j) {
                size_t firstNonZeroColumn = i;
                double temp = FindFirstNonZero(i, j, firstNonZeroColumn,matrix);
                wasMadeChange = SubtractRows(matrix, firstNonZeroColumn, temp, j, i);

                if (wasMadeChange) {
                    eliminationProcess.push_back(shared_ptr<CMatrix>(matrix->Clone()));
                }
            }
        }
    }
}



void Gem(shared_ptr<CMatrix> &matrix) {
    SortForElimination(matrix);

    for (size_t i = 0; i < matrix->GetNumRows(); i++) {
        for (size_t j = 0; j < matrix->GetNumRows(); j++) {
            if (i < j) {
                size_t firstNonZeroColumn = i;
                double temp = FindFirstNonZero(i, j, firstNonZeroColumn,matrix);
                SubtractRows(matrix, firstNonZeroColumn, temp, j, i);
            }
        }
    }
}
