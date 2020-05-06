//
// Created by terez on 24.04.2020.
//
#include <vector>
#include <memory>
#include "CMatrixSparse.h"
#include "CMatrixStandard.h"

using namespace std;

CMatrix *CMatrixSparse::Convert() const {
    vector<vector<double>> matrix(m_NumRows);
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            matrix[i].push_back(GetNumAtCoords(i, j));
        }
    }
    return new CMatrixStandard(matrix);
}


void CMatrixSparse::Print() const {
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (j != 0) {
                cout << " ";
            }
            if (m_Matrix.find({i, j}) == m_Matrix.end()) {
                cout << 0;
            } else {
                cout << m_Matrix.at(make_pair(i, j));
            }
        }
        cout << endl;
    }
}

double CMatrixSparse::GetNumAtCoords(size_t row, size_t col) const {
    if (m_Matrix.find({row, col}) == m_Matrix.end()) {
        return 0;
    } else {
        return m_Matrix.at({row, col});
    }
}

//CMatrix *CMatrixSparse::Add(const unique_ptr<CMatrix> &other) const {
//    if (m_NumRows != other->m_NumRows || m_NumCols != other->m_NumCols) {
//        throw "Adding incompatible matrices.";
//    }
//    map<pair<size_t, size_t>, double> sum = m_Matrix;
//    for (size_t i = 0; i < m_NumRows; i++) {
//        for (size_t j = 0; j < m_NumCols; j++) {
//            double numToAdd = other->GetNumAtCoords(i, j);
//            if (numToAdd != 0) {
//                if (m_Matrix.find({i, j}) == m_Matrix.end()) {
//                    sum[{i, j}] = 0;
//                }
//                sum[{i, j}] += numToAdd;
//            }
//        }
//    }
//    if (!CMatrixSparse(sum, m_NumRows, m_NumCols).ShouldBeSparse()) {
//        return new CMatrixStandard(sum, m_NumRows, m_NumCols);
//    }
//    return new CMatrixSparse(sum, m_NumRows, m_NumCols);
//}
//
//CMatrix *CMatrixSparse::NegateAllNums() const {
//    map<pair<size_t, size_t>, double> negatedNum = m_Matrix;
//    for (size_t i = 0; i < m_NumRows; i++) {
//        for (size_t j = 0; j < m_NumCols; j++) {
//            if (GetNumAtCoords(i, j) != 0)
//                negatedNum[{i, j}] = -GetNumAtCoords(i, j);
//        }
//    }
//    if (!CMatrixSparse(negatedNum, m_NumRows, m_NumCols).ShouldBeSparse()) {
//        return new CMatrixStandard(negatedNum, m_NumRows, m_NumCols);
//    }
//    return new CMatrixSparse(negatedNum, m_NumRows, m_NumCols);
//}
//
//CMatrix *CMatrixSparse::Subtract(const unique_ptr<CMatrix> &other) const {
//    return this->Add(unique_ptr<CMatrix>(other->NegateAllNums()));
//}
//
//CMatrix *CMatrixSparse::Multiply(const unique_ptr<CMatrix> &other) const {
//    map<pair<size_t, size_t>, double> product;
//    for (auto numA : m_Matrix) {
//        size_t rowIndexA = numA.first.first;
//        size_t colIndexA = numA.first.second;
//        for (size_t colIndexB = 0; colIndexB < other->m_NumCols; colIndexB++) {
//            if (other->GetNumAtCoords(colIndexA, colIndexB) != 0) {
//                if (product.find({rowIndexA, colIndexB}) == product.end()) {
//                    product[{rowIndexA, colIndexB}] = 0;
//                }
//                product[{rowIndexA, colIndexB}] += (numA.second * other->GetNumAtCoords(colIndexA, colIndexB));
//            }
//        }
//    }
//    if (!CMatrixSparse(product, m_NumRows, other->m_NumCols).ShouldBeSparse()) {
//        return new CMatrixStandard(product, m_NumRows, other->m_NumCols);
//    }
//    return new CMatrixSparse(product, m_NumRows, other->m_NumCols);
//}

//void CMatrixSparse::Transpose() {
//    map<pair<size_t, size_t>, double> transposition;
//    for (auto num : m_Matrix) {
//        size_t rowIndex = num.first.first;
//        size_t colIndex = num.first.second;
//        transposition[{colIndex, rowIndex}] = num.second;
//    }
//    switchNumRowsCols();
//    m_Matrix = transposition;
//}

CMatrixSparse *CMatrixSparse::MergeNextTo(const unique_ptr<CMatrix> &other) const {
    if (m_NumRows != other->m_NumRows) {
        throw "Merging incompatible matrices.";
    }
    map<pair<size_t, size_t>, double> merged = m_Matrix;
    for (size_t i = 0; i < other->m_NumRows; i++) {
        for (size_t j = 0; j < other->m_NumCols; j++) {
            double nextNum = other->GetNumAtCoords(i, j);
            if (nextNum != 0) {
                merged[{i, j + m_NumCols}] = nextNum;
            }
        }
    }
    return new CMatrixSparse(merged, m_NumRows, m_NumCols + other->m_NumCols);
}

//CMatrixSparse *CMatrixSparse::MergeUnder(const unique_ptr<CMatrix> &other) const {
//    if (m_NumCols != other->m_NumCols) {
//        throw "Merging incompatible matrices.";
//    }
//    map<pair<size_t, size_t>, double> merged = m_Matrix;
//    for (size_t i = 0; i < other->m_NumRows; i++) {
//        for (size_t j = 0; j < other->m_NumCols; j++) {
//            double nextNum = other->GetNumAtCoords(i, j);
//            if (nextNum != 0) {
//                merged[{i + m_NumRows, j}] = nextNum;
//            }
//        }
//    }
//    return new CMatrixSparse(merged, m_NumRows + other->m_NumRows, m_NumCols);
//}
//
void CMatrixSparse::Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) {
    if (numRows > m_NumRows || numCols > m_NumCols) {
        throw "Wrong dimensions, cannot cut.";
    } else if (startPoint.first > m_NumRows - numRows || startPoint.second > m_NumCols - numCols) {
        throw "Wrong dimensions2, cannot cut.";
    }
    map<pair<size_t, size_t>, double> cut;
    for (auto num : m_Matrix) {
        if ((num.first.first >= startPoint.first && num.first.first < startPoint.first + numRows) &&
            (num.first.second >= startPoint.second && num.first.second < startPoint.second + numRows)) {
            cut[{num.first.first - startPoint.first, num.first.second - startPoint.second}] = num.second;
        }
    }
    m_Matrix = cut;
    m_NumRows = numRows;
    m_NumCols = numCols;
}

void CMatrixSparse::ChangeToIdentity(int size) {
    m_NumRows = size;
    m_NumCols = size;
    m_Matrix.clear();
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (i == j) {
                m_Matrix[{i, j}] = 1;
            }
        }
    }
}