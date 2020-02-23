//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isvalid_text(char* filename){
  FILE* input = fopen(filename, "r");

  if(input == NULL){
    printf("Error: could not open file\n");
    return 1;
  }

  char tp = 0;
  int count = 0;
  int parse = fscanf(input, "%c", &tp);
  
  if(!isspace(tp)){
    count = parse;
  }
  if(!isupper(tp)){
    tp = toupper(tp);
  }
  
  if(!isspace(tp) && tp != 'A' && tp!= 'C' && tp!= 'G' && tp!= 'T'){
    fclose(input);
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
      fclose(input);
      return 1;
    }
  }

  if((count == 0) || count > 15000){
    fclose(input);
    return 1;
  }
  fclose(input);
  return 0;

  
}

int isvalid_pattern(char pattern[], int length){
  if((int)strlen(pattern) > length){
    return 1;
  }
  for(int i = 0; i < (int)strlen(pattern); i++){
    if(toupper(pattern[i]) != 'A' && toupper(pattern[i]) != 'C' && toupper(pattern[i]) != 'G' && toupper(pattern[i]) != 'T'){
      return 1;
    }
  }
  return 0;
}

char* scan_pattern(){
  char temp;
  char* pattern;
  int size = 0;
  //pattern = malloc(sizeof(char)
  //int run = scanf("%c", &temp);
  while(scanf("%c", &temp) == 1 && !isspace(temp)){
    size++;
    //printf("q");
    if(size == 1){
      pattern = calloc(1, sizeof(char));
    }else{
      pattern = realloc(pattern, sizeof(char)*size);
    }
    pattern[size-1]=temp;
    
    //TODO: dynamically allocate with each char
  }
  pattern = realloc(pattern, sizeof(char)*size+1);
  pattern[size] = '\0';
  return pattern;
  
  /*char* pattern = malloc(sizeof(char)*strlen(temp));
  if(pattern == null){
    printf("Could not allocate fresh memory\n");
    return NULL;
  }
  for(int i = 0; i < strlen(temp); i++){
    pattern[i] = temp[i];
    }*/
  
}
