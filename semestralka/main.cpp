#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <assert.h>
#include "CMatrixStandard.h"
#include "CMatrixSparse.h"
#include "CApplicationConsole.h"

using namespace std;
int main() {

    CApplicationConsole app;
    app.PrintInstructions();
    app.Run();
    app.ShowVariables();

    //lets do some tests
//    vector<vector<double>> a = {{1,2,3},
//                                {4,5,6},
//                                {7,8,9}};
//    vector<vector<double>> c = {{0,1,-3},
//                                {1,8,2},
//                                {5,8,-8}};
//    vector<vector<double>> b = {{-1.0,-2},
//                                {4.0,5},
//                                {0,-0}};
//    vector<vector<double>> r = {{1,3,3},
//                                {1,4,3},
//                                {1,3,4}};
//    vector<vector<double>> noInv = {{1,2,3},
//                                {4,5,6},
//                                {7,8,9}};
//    CMatrixStandard mat1 = CMatrixStandard(a);
//    CMatrixStandard matr = CMatrixStandard(noInv);
//    assert(matr.CalculateDeterminant()==0);
//
//    cout<<matr.CalculateRank();
////    matr.ConvertToLowerTriangular(true);
////    cout<<"lower";
////    matr.ConvertToUpperTriangular(true);
//    CMatrixStandard mat2 = CMatrixStandard(b);
//
//    unique_ptr <CMatrix> mat3ptr = unique_ptr<CMatrix>(mat1.Add((make_unique<CMatrixStandard>(CMatrixStandard(c)))));
//    assert(*mat3ptr==CMatrixStandard({{1,3,0},
//                                  {5,13,8},
//                                  {12,16,1}}));
//    unique_ptr <CMatrix> mat4ptr =unique_ptr<CMatrix>(mat1.Multiply(make_unique<CMatrixStandard>(CMatrixStandard(c))));
//    assert(*mat4ptr==CMatrixStandard({{17,41,-23},
//                                  {35,92,-50},
//                                  {53,143,-77}}));
//    mat4 = *mat1.MergeNextTo(make_unique<CMatrixStandard>(CMatrixStandard(b)));
//    assert(mat4==CMatrixStandard({{1,2,3,-1,-2},
//                                  {4,5,6,4,5},
//                                  {7,8,9,0,0}}));
//    mat4 = *mat1.MergeUnder(make_unique<CMatrixStandard>(CMatrixStandard(c)));
//    assert(mat4==CMatrixStandard({{1,2,3},
//                                  {4,5,6},
//                                  {7,8,9},
//                                  {0,1,-3},
//                                  {1,8,2},
//                                  {5,8,-8}}));
//
//    mat4.Cut(1,1,{1,0});
//    vector<vector<double>> alp ={{4}};
//    assert(mat4 == CMatrixStandard(alp));
//    mat4.ChangeToIdentity(3);
//    assert(mat4 ==CMatrixStandard({{1,0,0},
//                                   {0,1,0},
//                                   {0,0,1}}));
//
//
//    map<pair<size_t , size_t >, double> e = {{{0,0},1},{{1,2},2},{{2,1},3}};
//    map<pair<size_t , size_t >, double> f = {{{0,1},4},{{1,0},2},{{2,1},3}};
//    CMatrixSparse mat5 = CMatrixSparse(e, 3,3);
//    CMatrixSparse mat6 = *mat5.Multiply(make_unique<CMatrixSparse>(CMatrixSparse(f, 3,2)));
//    assert(mat6 ==CMatrixStandard({{0,4},
//                                   {0,6},
//                                   {6,0}}));
//    mat6.Transpose();
//    assert(mat6 ==CMatrixStandard({{0,0,6},
//                                   {4,6,0}}));
//
//
//    CMatrixSparse mat7 = *mat6.MergeUnder(make_unique<CMatrixSparse>(CMatrixSparse(e, 3,3)));
//    assert(mat7 ==CMatrixStandard({{0,0,6},
//                                   {4,6,0},
//                                   {1,0,0},
//                                   {0,0,2},
//                                   {0,3,0}}));
//    mat7 = *mat5.MergeNextTo(make_unique<CMatrixSparse>(CMatrixSparse(f, 3,2)));
//
//    assert(mat7 == CMatrixStandard({{1,0,0,0,4},
//                                    {0,0,2,2,0},
//                                    {0,3,0,0,3}}));
//    mat7.Cut(2,1,{0,2});
//    assert(mat7 == CMatrixStandard({{0},
//                                    {2}}));
//    mat7.ChangeToIdentity(3);
//    assert(mat7 ==CMatrixStandard({{1,0,0},
//                                   {0,1,0},
//                                   {0,0,1}}));
//
//

    return 0;
}
// dobry