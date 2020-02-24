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
  assert(pattern[0]=='a');//assuming user types in abc
  assert(pattern[1]=='b');//assuming user types in abc
  assert(pattern[2]=='c');//assuming user types in abc
  assert(pattern[3]=='\0');//assuming user types in abc 
  assert(strlen(pattern)==3);//assuming user types in abc
  free(pattern);
  printf("All tests passed!\n");
  
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
  pattern=scan_pattern();
  char pattern_arr[15001];
  int i = 0;
  do{
    pattern_arr[i] = pattern[i];
    i++;
  }while(pattern[i] != '\0');
  pattern_arr[i]='\0';
  //int* matches = find_matches(pattern, text);
  //assert(matches[0] == 4 && matches[1] == 14);
  //free(matches);
  //matches = find_matches("CTG\0", text);
  //assert(matches[0] == 4 && matches[1] == 14);
  //free(matches);
  free(pattern);
  /*printf("%d\n", (int)strlen(text));
    printf("%d\n", (int)strlen(pattern_arr));*/
  int plen = (int)strlen(pattern_arr);
  int tlen = (int)strlen(text);
  /*int match = pattern_match(text, tlen, pattern_arr, plen, 5);
    printf("%d\n", match);*/
  assert(pattern_match(text, tlen, pattern_arr, plen, 5)==14);//assuming pattern is ctg
  assert(pattern_match(text, tlen, pattern_arr, plen, 0) == 4);//assuming pattern is ctg
  return 0;
}
