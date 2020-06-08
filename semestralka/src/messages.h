//
// Created by terez on 19.05.2020.
//

#include <string>

#ifndef SEMESTRALKA_MESSAGES_H
#define SEMESTRALKA_MESSAGES_H
const char *const COMMAND_ADD = "add";
const char *const COMMAND_CUT = "cut";
const char *const COMMAND_CUT_DESTRUCTIVE = "Cut";
const char *const COMMAND_DETERMINANT = "determinant";
const char *const COMMAND_GAUSS_ELIMINATION = "gem";
const char *const COMMAND_GAUSS_ELIMINATION_DESTRUCTIVE = "Gem";
const char *const COMMAND_INVERSE = "inverse";
const char *const COMMAND_LOAD = "load";
const char *const COMMAND_MERGE_NEXT_TO = "merge_next_to";
const char *const COMMAND_MERGE_UNDER = "merge_under";
const char *const COMMAND_MULTIPLY = "multiply";
const char *const COMMAND_ORDER = "order";
const char *const COMMAND_PRINT = "print";
const char *const COMMAND_PUT = "put";
const char *const COMMAND_SUBTRACT = "subtract";
const char *const COMMAND_TRANSPOSE = "transpose";
const char *const COMMAND_TRANSPOSE_DESTRUCTIVE = "Transpose";
//todo create command help
const char *const COMMAND_HELP = "help";

const string DESC_COMMAND_HELP = "show description and usage of a particular command | usage: 'help:command_name ;'";
const string DESC_COMMAND_LOAD = "store a variable into memory";
const string DESC_COMMAND_PUT = "store result of operation to a variable";

const string USAGE_INSTRUCTIONS =
        "Welcome to the MATRIX! calculator.\nCalculator is controlled by commands listed below.\n--------------------------------------\n" +
        string(COMMAND_HELP) + ": " + DESC_COMMAND_HELP + "\n" +
        string(COMMAND_LOAD) + ": " + DESC_COMMAND_LOAD + "\n" +
        string(COMMAND_PUT) + ": " + DESC_COMMAND_PUT + "\n";
#endif //SEMESTRALKA_MESSAGES_H
