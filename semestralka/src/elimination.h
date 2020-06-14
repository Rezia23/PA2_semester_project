//
// Created by hrubate1 on 07.05.2020.
//

#ifndef SEMESTRALKA_ELIMINATION_H
#define SEMESTRALKA_ELIMINATION_H

#include "CMatrix.h"

/**
 * Sort rows of a matrix so that first number (or next if the same) decreases with increasing row index.
 * @param matrix matrix to be sorted
 * @return number of row swaps made
 */
int SortForElimination(shared_ptr<CMatrix> &matrix);

/**
 * Convert matrix to upper triangular form, store steps (matrices) of elimination process.
 * @param matrix matrix to be converted
 * @param eliminationProcess vector of steps (matrices) of elimination
 */
void Gem(shared_ptr<CMatrix> &matrix, vector<shared_ptr<CMatrix>> &eliminationProcess);

/**
 * Convert matrix to upper triangular form.
 * @param matrix matrix to be converted
 */
void Gem(shared_ptr<CMatrix> &matrix);

/**
 * Perform step of elimination on a matrix.
 * Subtract multiple of a row from a multiple of another.
 * Multiple may be optimized so it does not create too big numbers.
 * @param matrix matrix to have rows subtracted
 * @param firstNonZeroColumn index of first column in row with non zero value
 * @param multipleToSubtract this multiple of row will be subtracted
 * @param rowToBeChanged index of row to be changed
 * @param subtractingRow index of subtracting row
 * @param optimizeBigNums if true, big numbers are optimized
 * @return true if elimination step performed, false if it cannot be - multiplying row by zero
 */
bool SubtractRows(shared_ptr<CMatrix> &matrix, size_t firstNonZeroColumn, double multipleToSubtract, size_t rowToBeChanged,
             size_t subtractingRow, bool optimizeBigNums=false);

/**
 * Compare double to zero.
 * @param number
 * @return true if equals zero, false otherwise
 */
bool IsZero(double number);

/**
 * Find first non zero element in two rows, starting from column given as parameter.
 * @param rowFirst index of first row
 * @param rowSecond index of second row
 * @param column column where to start
 * @param matrix
 * @return value of first non zero element
 */
double FindFirstNonZero(size_t rowFirst, size_t rowSecond, size_t &column, shared_ptr<CMatrix> &matrix);

#endif //SEMESTRALKA_ELIMINATION_H
