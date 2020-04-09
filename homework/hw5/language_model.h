//Sam Lipschitz
//slipsch3

#ifndef LANGUAGE_MODEL_H
#define LANGUAGE_MODEL_H

#include <map>
#include <string>

using std::string;

/* Returns 0 if valid input, 1 if invalid input */
int isValid(int argc, char* argv[]);

/* Calls method to do specified operation */
void doOperation(std::map<std::tuple<string, string, string>, int> model, char* argv[]);

/* Returns map of trigraphs from text files mentioned in argv[1] */
std::map<std::tuple<string, string, string>, int> buildModel(char* argv[]);

#endif
