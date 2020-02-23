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
  
  while(scanf("%c", &temp) == 1 && !isspace(temp)){
    size++;
    
    if(size == 1){
      pattern = calloc(1, sizeof(char));
    }else{
      pattern = realloc(pattern, sizeof(char)*size);
    }
    pattern[size-1]=temp;
    
  }
  pattern = realloc(pattern, sizeof(char)*size+1);
  pattern[size] = '\0';
  return pattern;
  
}

int* find_matches(char pattern[], char text[]){
  int num_matches = 0;
  int n = (int)strlen(pattern);
  int m = (int)strlen(text);
  int* locs;
  for(int i = 0; i < m-n; i++){
    int match = 0;
    for(int j = 0; j < n; j++){
      if(pattern[j] != text[i+j]){
	match = 1;
	break;
      }
    }
    if(match == 0){
      num_matches++;
      if(num_matches == 1){
        locs = malloc(sizeof(int));
      }else{
	locs = realloc(locs, sizeof(int)*num_matches);
      }
      locs[num_matches-1] = i;
    }
  }
  return locs;
}
