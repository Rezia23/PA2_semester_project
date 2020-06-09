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
const char *const COMMAND_EXIT = "exit";

const vector<vector<string>> HELP = {
        {{"Command name"},{"description"},{"usage"}},
        {{COMMAND_EXIT},{"exit the app"},{"exit"}},
        {{COMMAND_HELP},{"show this help"},{"help"}},
        {{"really long name"},{"the description is even longer"},{"and the usage too"}}


};
//        "Command name         description           usage\n" +
//        string(COMMAND_EXIT) + " - " + "exit the app" +
//        string(COMMAND_HELP) + " - " + "exit the app" +
//        string(COMMAND_EXIT) + " - " + "exit the app" +
//        string(COMMAND_EXIT) + " - " + "exit the app" +
//        "show description and usage of a particular command | usage: 'help:command_name ;'";


const string USAGE_INSTRUCTIONS =
        "Welcome to the MATRIX! calculator.\nFor exit type '" + string(COMMAND_EXIT) + "' for help type '" + string(COMMAND_HELP) + "'.\n-------------------------------------------\n";
#endif //SEMESTRALKA_MESSAGES_H
