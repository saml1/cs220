//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

  printf("It should say \"Error: could not open file\" after this:\n");
  assert(isvalid_text("test.txt") == 0); //checking valid txt
  assert(isvalid_text("badtxt.txt") != 0); //checking invalid txt
  assert(isvalid_text("asfdf") != 0);//checking nonexistent file
  assert(isvalid_text("badtxt2.txt") != 0);

  assert(isvalid_pattern("Gtc",10) == 0);
  assert(isvalid_pattern("gAtCGaTc", 9) == 0);
  assert(isvalid_pattern("GTAC", 2) != 0);
  assert(isvalid_pattern("gtBc", 130) != 0);
  assert(isvalid_pattern("bgTc", 134) != 0);

  printf("Enter \"abc\" for assertions to work\n");
  char* pattern = scan_pattern();
  
  assert(pattern[0]=='a');//assuming user types in abc
  assert(pattern[1]=='b');//assuming user types in abc
  assert(pattern[2]=='c');//assuming user types in abc
  assert(pattern[3]=='\0');//assuming user types in abc 
  assert(strlen(pattern)==3);//assuming user types in abc
  free(pattern);
  
  FILE* input = fopen("test.txt", "r");
  char text[15001];
  char temp = 0;
  int parse = fscanf(input, "%c", &temp);
  int count = 0;
  while(parse == 1){
    if(!isspace(temp)){
      text[count] = temp;
      count++;
    }
    parse = fscanf(input, "%c", &temp);
  }
  text[count] = '\0';
  fclose(input);
  printf("Enter \"ctg\" for assertions to work:\n");
  printf("(Assuming file test.txt with \"gtatctgatcgatgctggtc\")\n");
  pattern=scan_pattern();
  char pattern_arr[15001];
  int i = 0;
  do{//converting pointer from scan_pattern to pattern_arr
    pattern_arr[i] = pattern[i];
    i++;
  }while(pattern[i] != '\0');
  pattern_arr[i]='\0';
  free(pattern);
  
  int plen = (int)strlen(pattern_arr);
  int tlen = (int)strlen(text);
  //assuming test.txt contains: gtatctgatcgatgctggtc
  assert(pattern_match(text, tlen, pattern_arr, plen, 5)==14);//assuming pattern is ctg
  assert(pattern_match(text, tlen, pattern_arr, plen, 0) == 4);//assuming pattern is ctg
  printf("All tests passed!\n");
  return 0;
}
