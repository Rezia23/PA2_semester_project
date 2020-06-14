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
 * @return multiple of numbers used for multiplying rows in gauss elimination
 */
int Gem(shared_ptr<CMatrix> &matrix);

/**
 * Perform step of elimination on a matrix.
 * Subtract multiple of a row from a multiple of another.
 * Multiple is optimized so it does not create too big numbers.
 * @param matrix matrix to have rows subtracted
 * @param firstNonZeroColumn index of first column in row with non zero value
 * @param multipleToSubtract this multiple of row will be subtracted
 * @param rowToBeChanged index of row to be changed
 * @param subtractingRow index of subtracting row
 * @return
 */
bool SubtractRows(shared_ptr<CMatrix> &matrix, size_t firstNonZeroColumn, double multipleToSubtract, size_t rowToBeChanged,
             size_t subtractingRow);

/**
 * Compare double to zero.
 * @param number
 * @return true if equals zero, false otherwise
 */
bool IsZero(double number);

#endif //SEMESTRALKA_ELIMINATION_H
