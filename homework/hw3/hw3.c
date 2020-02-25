//Sam Lipschitz
//slipsch3

#include "dnasearch.h"

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Error: must include input filename\n");
    return 1;
  }
  char* filename = argv[1];

  if(isvalid_text(filename) == 1){
    printf("Invalid text\n");
    return 2;
  }else if(isvalid_text(filename) == 2){
    return 3;
  }
  FILE* input = fopen(filename, "r");
  char text[15001];
  char temp = 0;
  int parse = fscanf(input, "%c", &temp);
  int count = 0;
  while(parse == 1){
    if(!isspace(temp)){
      text[count] = toupper(temp);
      count++;
    }
    parse = fscanf(input, "%c", &temp);
  }
  /*for(int z = 0; z < 16; z++){
    printf("%c ", text[z]);
    }*/
  //printf("\n");
  text[count] = '\0';
  fclose(input);

  char* pattern = scan_pattern();
  char pattern_arr[15001];
  int i = 0;
  do{
    pattern_arr[i] = toupper(pattern[i]);
    i++;
  }while(pattern[i] != '\0');
  pattern_arr[i]='\0';
  int plen = (int)strlen(pattern_arr);
  int tlen = (int)strlen(text);
  //printf("%d\n", plen);
  //printf("%s\n", pattern_arr);
  //printf("%d\n", isvalid_pattern(pattern_arr, plen));
  //printf("%d\n", pattern_match(text, tlen, pattern_arr, plen, 0));
  if(isvalid_pattern(pattern_arr, plen) != 0){
    printf("Invalid pattern\n");
    free(pattern);
    return 4;
  }
  while(pattern[0] != (char)32 && pattern != NULL && isvalid_pattern(pattern_arr, plen)==0){
    printf("%s ", pattern_arr);
    int loc = -1;
    int foundmatch = 0;
    for(int j = 0; j < tlen-plen; j++){
      
      if(pattern_match(text, tlen, pattern_arr, plen, j) != loc && pattern_match(text, tlen, pattern_arr, plen, j) >=0){
	//printf("%d\n", loc);
	printf("%d ", pattern_match(text, tlen, pattern_arr, plen, j));
	loc = pattern_match(text, tlen, pattern_arr, plen, j);
	foundmatch = 1;
      }
    }
    if(foundmatch == 0){
      printf("Not found");
    }
    printf("\n");
    //printf("%d\n", pattern_match(text, tlen, pattern_arr, plen, 0));
    //printf("%c pat0\n", pattern[0]);
    free(pattern);
    //printf("ss\n");
    pattern = scan_pattern();
    if(pattern != NULL && pattern_arr[0] != (char)32){
      i=0;
      do{
	//printf("%d is I\n", i);
	pattern_arr[i] = toupper(pattern[i]);
	i++;
      }while(pattern[i] != '\0');
      pattern_arr[i]='\0';
      plen = (int)strlen(pattern_arr);
      tlen = (int)strlen(text);
      if(isvalid_pattern(pattern_arr, plen) != 0 && pattern_arr[0] != (char)32){
	printf("Invalid pattern\n");
	free(pattern);
	return 4;
      }
    }
    //free(pattern);
  }
  
  /*int* matches = find_matches(pattern, text);
  printf("%d\n", matches[0]);
  printf("%d\n", matches[1]);*/
  free(pattern);
  //free(matches);
  return 0;
}
