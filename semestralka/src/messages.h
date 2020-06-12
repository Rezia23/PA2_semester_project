//
// Created by hrubate1 on 19.05.2020.
//

#include <string>

#ifndef SEMESTRALKA_MESSAGES_H
#define SEMESTRALKA_MESSAGES_H
const char *const COMMAND_HELP = "help";
const char *const COMMAND_EXIT = "exit";

const char *const COMMAND_ADD = "add";
const char *const COMMAND_LOAD = "load";
const char *const COMMAND_SUBTRACT = "subtract";
const char *const COMMAND_MULTIPLY = "multiply";
const char *const COMMAND_MERGE_NEXT_TO = "merge_next_to";
const char *const COMMAND_MERGE_UNDER = "merge_under";
const char *const COMMAND_ORDER = "order";
const char *const COMMAND_DETERMINANT = "determinant";
const char *const COMMAND_PRINT = "print";
const char *const COMMAND_INVERSE = "inverse";

const char *const COMMAND_CUT = "cut";
const char *const COMMAND_CUT_DESTRUCTIVE = "Cut";
const char *const COMMAND_TRANSPOSE = "transpose";
const char *const COMMAND_TRANSPOSE_DESTRUCTIVE = "Transpose";
const char *const COMMAND_GAUSS_ELIMINATION = "gem";
const char *const COMMAND_GAUSS_ELIMINATION_DESTRUCTIVE = "Gem";

const char *const COMMAND_PUT = "put";

const char DELIMITER_PARAMETERS = ' ';
const char DELIMITER_END_COMMAND = ';';
const char DELIMITER_COMMAND_WORD = ':';
const char DELIMITER_MATRIX_SIZE = '|';

const char *const MSG_COMMAND_NOT_PARSED = "Command could not be parsed.";
const char *const MSG_EXIT = "Closing the app.";
const char *const MSG_FAILED_OPERATION = "Operation failed.";

const char *const MSG_NOT_EXISTING_VARIABLE = "Variable does not exist.";

const vector<vector<string>> HELP = {
        {{"Command name"},                        {"description"},                                                                                                   {"usage"}},
        {{COMMAND_EXIT},                          {"exit the app"},                                                                                                  {"'" +
                                                                                                                                                                      string(COMMAND_EXIT) +
                                                                                                                                                                      "'"}},
        {{COMMAND_HELP},                          {"show this help"},                                                                                                {"'" +
                                                                                                                                                                      string(COMMAND_HELP) +
                                                                                                                                                                      "'"}},
        {{COMMAND_LOAD},                          {"load matrix to a variable"},                                                                                     {"'" +
                                                                                                                                                                      string(COMMAND_LOAD) +
                                                                                                                                                                      ":var_name num_rows num_cols|val-1-1 val-1-2 ... val-num_rows-num_cols ;', e.g. '" +
                                                                                                                                                                      string(COMMAND_LOAD) +
                                                                                                                                                                      ":neo 2 3|4 5 6 7 8 9 ;' "}},
        {{COMMAND_ADD},                           {"create new matrix by adding two variables"},                                                                     {"'" +
                                                                                                                                                                      string(COMMAND_ADD) +
                                                                                                                                                                      ":var_name1 var_name2 ;'"}},
        {{COMMAND_SUBTRACT},                      {"create new matrix by subtracting two variables"},                                                                {"'" +
                                                                                                                                                                      string(COMMAND_SUBTRACT) +
                                                                                                                                                                      ":var_name1 var_name2 ;'"}},
        {{COMMAND_MULTIPLY},                      {"create new matrix by multiplying two variables"},                                                                {"'" +
                                                                                                                                                                      string(COMMAND_MULTIPLY) +
                                                                                                                                                                      ":var_name1 var_name2 ;'"}},
        {{COMMAND_MERGE_NEXT_TO},                 {"create new matrix by placing two variables next to each other"},                                                 {"'" +
                                                                                                                                                                      string(COMMAND_MERGE_NEXT_TO) +
                                                                                                                                                                      ":left_var_name right_var_name ;'"}},
        {{COMMAND_MERGE_UNDER},                   {"create new matrix by placing two variables one under other"},                                                    {"'" +
                                                                                                                                                                      string(COMMAND_MERGE_UNDER) +
                                                                                                                                                                      ":top_var_name bottom_var_name ;'"}},
        {{COMMAND_PRINT},                         {"print variable"},                                                                                                {"'" +
                                                                                                                                                                      string(COMMAND_PRINT) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_INVERSE},                       {"create new matrix as inverse of a variable"},                                                                    {"'" +
                                                                                                                                                                      string(COMMAND_INVERSE) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_CUT},                           {"create new matrix by cutting variable according to given parameters"},                                           {"'" +
                                                                                                                                                                      string(COMMAND_CUT) +
                                                                                                                                                                      ":var_name new_num_rows new_num_cols|start_row end_row ;'"}},
        {{COMMAND_CUT_DESTRUCTIVE},               {"same as '" + string(COMMAND_CUT) +
                                                   "' but replaces input variable by the output matrix"},                                                            {"'" +
                                                                                                                                                                      string(COMMAND_CUT_DESTRUCTIVE) +
                                                                                                                                                                      ":var_name new_num_rows new_num_cols|start_row end_row ;'"}},
        {{COMMAND_TRANSPOSE},                     {"create new matrix by transposing input variable"},                                                               {"'" +
                                                                                                                                                                      string(COMMAND_TRANSPOSE) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_TRANSPOSE_DESTRUCTIVE},         {"same as '" + string(COMMAND_TRANSPOSE) +
                                                   "' but replaces input variable by the output matrix"},                                                            {"'" +
                                                                                                                                                                      string(COMMAND_TRANSPOSE_DESTRUCTIVE) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_GAUSS_ELIMINATION},             {"create new matrix as input variable transformed to upper triangular form"},                                      {"'" +
                                                                                                                                                                      string(COMMAND_GAUSS_ELIMINATION) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_GAUSS_ELIMINATION_DESTRUCTIVE}, {"same as '" + string(COMMAND_GAUSS_ELIMINATION) +
                                                   "' but replaces input variable by the output matrix"},                                                            {"'" +
                                                                                                                                                                      string(COMMAND_GAUSS_ELIMINATION_DESTRUCTIVE) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_PUT},                           {"stores output matrix of a operation into variable, used only with operations with outputs in form of matrices"}, {"'" +
                                                                                                                                                                      string(COMMAND_PUT) +
                                                                                                                                                                      ":var_name other_command params_of_other_command ;', e.g. put:cypher add:morpheus trinity ;"}},

        {{COMMAND_ORDER},                         {"calculate order of a variable"},                                                                                 {"'" +
                                                                                                                                                                      string(COMMAND_ORDER) +
                                                                                                                                                                      ":var_name ;'"}},
        {{COMMAND_DETERMINANT},                   {"calculate determinant of a variable"},                                                                           {"'" +
                                                                                                                                                                      string(COMMAND_DETERMINANT) +
                                                                                                                                                                      ":var_name ;'"}},
};


const string USAGE_INSTRUCTIONS =
        "Welcome to the MATRIX! calculator.\nFor exit type '" + string(COMMAND_EXIT) + "' for help type '" +
        string(COMMAND_HELP) + "'.\n-------------------------------------------\n";


#endif //SEMESTRALKA_MESSAGES_H
