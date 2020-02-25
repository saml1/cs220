//Sam Lipschitz
//slipsch3

#include "dnasearch.h"


int isvalid_text(char* filename){
  FILE* input = fopen(filename, "r");

  if(input == NULL){
    printf("Error: could not open file\n");
    return 2;
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
  //printf("in isvalid_pattern\n");
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
  int a = 0;
  if(scanf("%c", &temp) == 1){
    a = 1;
    while(isspace(temp)){
      scanf("%c", &temp);
    }
  }
  if(a == 0){
    //printf("end\n");
    pattern = malloc(sizeof(char)*2);
    pattern[0] = (char)32;
    pattern[1] = '\0';
    return pattern;
  }
  do{
    
    size++;
    
    if(size == 1){
      pattern = calloc(1, sizeof(char));
    }else{
      pattern = realloc(pattern, sizeof(char)*size);
    }
    pattern[size-1]=temp;
    
  }while(scanf("%c", &temp) == 1 && !isspace(temp));
  //printf("%d\n", size);
  // if(pattern!=NULL){printf("notnull\n");}
  //printf("%d\n", size);
  if(size > 0){
    pattern = realloc(pattern, sizeof(char)*size+1);
    pattern[size] = '\0';
    //printf("not eof\n");
    //printf("%lu size\n", sizeof(pattern));
    return pattern;
    }
  //if(size == 0){
    //printf("recursive\n");
    //scan_pattern();
    // }
  //printf("%lu size\n", sizeof(pattern));
  
  return NULL;
  
}

/*int* find_matches(char pattern[], char text[]){
  int num_matches = 0;
  int n = (int)strlen(pattern);
  int m = (int)strlen(text);
  //printf("%d %d\n", n, m);
  int* locs;
  for(int i = 0; i < m-n; i++){
    int match = 0;
    for(int j = 0; j < n; j++){
      if(toupper(pattern[j]) != toupper(text[i+j])){
	//printf("got here\n");
	match = 1;
	//printf("%c %c\n", pattern[j], text[i+j]);
	break;
      }
      
    }
    //printf("got here\n");
    if(match == 0){
      printf("got herematch == 0\n");
      num_matches++;
      if(num_matches == 1){
        locs = malloc(sizeof(int));
      }else{
	locs = realloc(locs, sizeof(int)*num_matches);
      }
      locs[num_matches-1] = i;
      }
  }
  //locs = realloc(locs, sizeof(int)*(num_matches+1));
  //locs[num_matches]=-1;
  return locs;
  }*/

int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at){
  //printf("%d\n", tlen);
  //printf("%d\n", plen);
  for(int i = start_at; i < tlen-plen+1; i++){
    int match = 0;
    for(int j = 0; j < plen; j++){
      if(toupper(p[j]) != toupper(t[i+j])){
	  match = 1;
	  break;
	}
    }
    //printf("here\n");
    if(match == 0) {
      //printf("%d\n", start_at);
      return i;
    }
  }
  /*if((match == 0) && i >= start_at) {
      return i;
      }*/
  /*for(int i = 0; i < tlen; i++){
    //printf("%c", t[i]);
  }
  for(int i = 0; i < plen; i++){
    //printf("%c", p[i]);
    }*/
      
  return -1;
}
