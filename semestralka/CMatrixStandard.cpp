//
// Created by terez on 24.04.2020.
//

#include <iostream>
#include <exception>
#include <memory>
#include <vector>

#include "CMatrixStandard.h"
#include "CMatrixSparse.h"

CMatrix *CMatrixStandard::Convert() const {
    size_t numRows = m_NumRows;
    size_t numCols = m_NumCols;
    map<pair<size_t, size_t>, double> matrix;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (GetNumAtCoords(i, j) != 0) {
                matrix[{i, j}] = GetNumAtCoords(i, j);
            }
        }
    }
    return new CMatrixSparse(matrix, numRows, numCols);
}

void CMatrixStandard::Print() const {
    for (auto row : m_Matrix) {
        for (size_t i = 0; i < row.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << row[i];
        }
        cout << endl;
    }
}

CMatrix *CMatrixStandard::Add(const unique_ptr<CMatrix> &other) const {
    if (m_NumRows != other->m_NumRows || m_NumCols != other->m_NumCols) {
        throw "Adding incompatible matrices, should be checked before.";
    }
    vector<vector<double>> sum(m_NumRows);
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            sum[i].push_back(GetNumAtCoords(i, j) + other->GetNumAtCoords(i, j));
        }
    }
    if(CMatrixStandard(sum).ShouldBeSparse()){
        return new CMatrixSparse(sum);
    }
    return new CMatrixStandard(sum);
}

CMatrix * CMatrixStandard::Subtract(const unique_ptr<CMatrix> &other) const {
    return (this->Add(unique_ptr<CMatrix>(other->NegateAllNums())));
}

CMatrix *CMatrixStandard::NegateAllNums() const {
    vector<vector<double>> negatedMat(m_NumRows);
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            negatedMat[i].push_back(-GetNumAtCoords(i, j));
        }
    }
    if(CMatrixStandard(negatedMat).ShouldBeSparse()){
        return new CMatrixSparse(negatedMat);
    }
    return new CMatrixStandard(negatedMat);
}

CMatrix *CMatrixStandard::Multiply(const unique_ptr<CMatrix> &other) const {
    if (m_NumCols != other->m_NumRows) {
        throw "Multiplying incompatible matrices, should be checked before.";
    }
    vector<vector<double>> product(m_NumRows, vector<double>(other->m_NumCols, 0));

    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < other->m_NumCols; j++) {
            for (size_t k = 0; k < other->m_NumRows; k++) {
                product[i][j] += GetNumAtCoords(i, k) * other->GetNumAtCoords(k, j);
            }
        }
    }
    if(CMatrixStandard(product).ShouldBeSparse()){
        return new CMatrixSparse(product);
    }
    return new CMatrixStandard(product);
}

void CMatrixStandard::Transpose() {
    vector<vector<double>> transposition(m_NumCols, vector<double>(m_NumRows, 0));
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            transposition[j][i] = m_Matrix[i][j];
        }
    }
    switchNumRowsCols();
    m_Matrix = transposition;
}

CMatrixStandard *CMatrixStandard::MergeNextTo(const unique_ptr<CMatrix> &other) const {
    if (m_NumRows != other->m_NumRows) {
        throw "Merging incompatible matrices. Should be checked before.";
    }
    vector<vector<double>> merged = m_Matrix;
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < other->m_NumCols; j++) {
            merged[i].push_back(other->GetNumAtCoords(i, j));
        }
    }
    return new CMatrixStandard(merged);
}

CMatrixStandard *CMatrixStandard::MergeUnder(const unique_ptr<CMatrix> &other) const {
    if (m_NumCols != other->m_NumCols) {
        throw "Merging incompatible matrices. Should be checked before.";
    }
    vector<vector<double>> merged = m_Matrix;
    for (size_t i = 0; i < other->m_NumRows; i++) {
        merged.push_back(vector<double>());
        for (size_t j = 0; j < other->m_NumCols; j++) {
            merged[m_NumRows + i].push_back(other->GetNumAtCoords(i, j));
        }
    }
    return new CMatrixStandard(merged);
}

void CMatrixStandard::Cut(size_t numRows, size_t numCols, pair<size_t, size_t> startPoint) {
    if (numRows > m_NumRows || numCols > m_NumCols) {
        throw "Wrong dimensions, cannot cut.";
    } else if (startPoint.first > m_NumRows - numRows || startPoint.second > m_NumCols - numCols) {
        throw "Wrong dimensions2, cannot cut.";
    }
    vector<vector<double>> cut(numRows, vector<double>(numCols, 0));
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < numCols; j++) {
            cut[i][j] = m_Matrix[startPoint.first + i][startPoint.second + j];
        }
    }
    m_Matrix = cut;
    m_NumRows = numRows;
    m_NumCols = numCols;
}

void CMatrixStandard::ChangeToIdentity(int size) {
    m_NumRows = size;
    m_NumCols = size;
    m_Matrix.clear();
    for (size_t i = 0; i < m_NumRows; i++) {
        m_Matrix.push_back(vector<double>());
        for (size_t j = 0; j < m_NumCols; j++) {
            if (i == j) {
                m_Matrix[i].push_back(1);
            } else {
                m_Matrix[i].push_back(0);
            }
        }
    }
}

void CMatrixStandard::SortForElimination() {
    for (size_t i = m_NumRows - 1; i > 0; i--) {
        if (GetNumAtCoords(i - 1, 0) < GetNumAtCoords(i, 0)) {
            swap(m_Matrix[i - 1], m_Matrix[i]);
        }
    }
}

void CMatrixStandard::CreateZeroTriangles() {
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumRows; j++) {
            if (j != i) {
                double temp = GetNumAtCoords(j, i);
                for (size_t k = 0; k < 2 * m_NumRows; k++) {
                    m_Matrix[j][k] *= GetNumAtCoords(i, i);
                    m_Matrix[j][k] -= GetNumAtCoords(i, k) * temp;
                }
            }
        }
    }
}

void CMatrixStandard::MakeDiagonalsTo1() {
    for (size_t i = 0; i < m_NumRows; i++) {

        double temp = GetNumAtCoords(i, i);
        for (size_t j = 0; j < m_NumRows * 2; j++) {

            m_Matrix[i][j] = GetNumAtCoords(i, j) / temp;
        }
    }
}

void CMatrixStandard::ConvertToLU() {
    CreateZeroTriangles();
    MakeDiagonalsTo1();
}

CMatrixStandard *CMatrixStandard::FindInverse() const {
    if (m_NumRows != m_NumCols) {
        throw "nope";
    }
    //if determinant = 0 inverz neexistuje TODO!!!!!!!!!!!!!!!!

    unique_ptr<CMatrix> identity = make_unique<CMatrixStandard>(CMatrixStandard());
    identity->ChangeToIdentity(m_NumRows);
    identity->Print();

//    CMatrixStandard augumented = new CMatrixStandard();
//    augumented = *(this->MergeNextTo(identity));
    CMatrixStandard *augumented = (this->MergeNextTo(identity));
    augumented->Print();
    augumented->SortForElimination();
    augumented->Print();
    augumented->ConvertToLU();

    augumented->Print();
    augumented->Cut(m_NumCols, m_NumCols, {0, m_NumCols});
    return augumented;
}

void CMatrixStandard::AddDiagonal(vector<double> &diagonal) const {
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumCols; j++) {
            if (i == j) {
                diagonal[i] *= GetNumAtCoords(i, j);
            }
        }
    }
}

void CMatrixStandard::ConvertToUpperTriangular(bool printSteps) {
    if (printSteps) {
        Print();
        cout << endl;
    }
    SortForElimination();
    for (size_t i = 0; i < m_NumRows; i++) {
        for (size_t j = 0; j < m_NumRows; j++) {
            if (i < j) {
                double temp = GetNumAtCoords(j, i);
                for (size_t k = 0; k < m_NumCols; k++) {
                    m_Matrix[j][k] *= GetNumAtCoords(i, i);
                    m_Matrix[j][k] -= GetNumAtCoords(i, k) * temp;
                }
                if (printSteps) {
                    Print();
                    cout << endl;
                }
            }
        }
    }

}

void CMatrixStandard::ConvertToLowerTriangular(bool printSteps) {
    if (printSteps) {
        Print();
        cout << endl;
    }
    SortForElimination();
    for (size_t i = m_NumRows; i > 0; i--) {
        for (size_t j = m_NumRows; j > 0; j--) {
            if (i > j) {
                double temp = GetNumAtCoords(j - 1, i - 1);
                for (size_t k = 0; k < m_NumCols; k++) {
                    m_Matrix[j - 1][k] *= GetNumAtCoords(i - 1, i - 1);
                    m_Matrix[j - 1][k] -= GetNumAtCoords(i - 1, k) * temp;
                }
                if (printSteps) {
                    Print();
                    cout << endl;
                }
            }
        }
    }
}

double CMatrixStandard::CalculateDeterminant() const {
    if (m_NumRows != m_NumCols) {
        throw "Invalid matrix.";
    }
    vector<double> diagonal(m_NumRows, 1);
    CMatrixStandard tmp = *this;
    tmp.ConvertToUpperTriangular();
    tmp.AddDiagonal(diagonal);
    tmp.ConvertToLowerTriangular();
    tmp.AddDiagonal(diagonal);
    double det = 0;
    for (size_t i = 0; i < diagonal.size(); i++) {
        det += diagonal[i];
    }

    return det;
}

int CMatrixStandard::GetCountZeroRows() const {
    int count = 0;
    bool isRowZero;
    for (size_t i = 0; i < m_NumRows; i++) {
        isRowZero = true;
        for (size_t j = 0; j < m_NumCols; j++) {
            if (GetNumAtCoords(i, j) != 0) {
                isRowZero = false;
                break;
            }
        }
        if (isRowZero) {
            count++;
        }
    }
    return count;
}

int CMatrixStandard::CalculateRank() const {
    CMatrixStandard tmp = *this;
    tmp.ConvertToUpperTriangular();
    tmp.Print();
    return m_NumRows - tmp.GetCountZeroRows();
}