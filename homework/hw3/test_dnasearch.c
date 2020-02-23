//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

  assert(isvalid_text("test.txt") == 0); //checking valid txt
  assert(isvalid_text("badtxt.txt") != 0); //checking invalid txt
  assert(isvalid_text("asfdf") != 0);//checking nonexistent file
  assert(isvalid_text("badtxt2.txt") != 0);

  assert(isvalid_pattern("Gtc",10) == 0);
  assert(isvalid_pattern("gAtCGaTc", 9) == 0);
  assert(isvalid_pattern("GTAC", 2) != 0);
  assert(isvalid_pattern("gtBc", 130) != 0);
  assert(isvalid_pattern("bgTc", 134) != 0);

  char* pattern = scan_pattern();
  //printf("%lu", strlen(pattern));
  //printf("%c\n", *pattern);
  assert(pattern[0]=='a');//assuming user types in abc
  assert(pattern[1]=='b');//assuming user types in abc
  assert(pattern[2]=='c');//assuming user types in abc
  assert(pattern[3]=='\0');//assuming user types in abc 
  assert(strlen(pattern)==3);//assuming user types in abc
  //printf("%s", pattern);
  free(pattern);
  printf("All tests passed!\n");
  return 0;
}
