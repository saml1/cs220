//Sam Lipschitz
//slipsch3

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int isvalid_text(char* filename);

int isvalid_pattern(char pattern[], int length);

char* scan_pattern();

int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at);
