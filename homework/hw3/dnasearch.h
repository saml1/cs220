//Sam Lipschitz
//slipsch3

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int isvalid_text(char* filename);

int isvalid_pattern(char pattern[], int length);

char* scan_pattern();

int* find_matches(char pattern[], char text[]);
