//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isvalid_text(char* filename){
  FILE* input = fopen(filename, "r");

  if(input == NULL){
    printf("Error: could not open file\n");
    return 1;
  }

  char tp = 0;
  int count = 0;
  int parse = fscanf(input, "%c", &tp);
  //printf("%c\n", tp);
  if(!isspace(tp)){
    count = parse;
  }
  if(!isupper(tp)){
    tp = toupper(tp);
  }
  
  if(!isspace(tp) && tp != 'A' && tp!= 'C' && tp!= 'G' && tp!= 'T'){
    return 1;
  }

  while(parse == 1){
    parse = fscanf(input, "%c", &tp);
    if(!isspace(tp)){
      count += parse;
    }
    if(!isupper(tp)){
      tp = toupper(tp);
    }
    if(!isspace(tp) && tp != 'A' && tp!= 'C' && tp!= 'G' && tp!= 'T'){
      return 1;
    }
  }

  //printf("%d/n", count);
  if((count == 0) || count > 15000){
    return 1;
  }
  return 0;

  
}

int isvalid_pattern(char pattern[], int length){
  if((int)strlen(pattern) > length){
    return 1;
  }
  for(int i = 0; i < (int)strlen(pattern); i++){
    //pattern[i] = toupper(pattern[i]);
    if(toupper(pattern[i]) != 'A' && toupper(pattern[i]) != 'C' && toupper(pattern[i]) != 'G' && toupper(pattern[i]) != 'T'){
      return 1;
    }
  }
  return 0;
}
