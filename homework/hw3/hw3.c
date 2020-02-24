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
  text[count] = '\0';
  fclose(input);
  
  char* pattern = scan_pattern();
  //printf("%c", pattern[0]);
  //printf("%c", pattern[1]);
  //printf("%c", pattern[2]);
  /*if(pattern[2]== '\0'){
    printf("yup/n");
  }*/
  int j = 0;
  int pattern_length = 0;
  while(pattern[j] != '\0'){
    pattern_length++;
    j++;
    printf("%d\n", pattern_length);
  }
  char pattern_string[pattern_length];
  for(int k= 0; k < pattern_length+1; k++){
    pattern_string[k] = pattern[k];
  }
  while(pattern != NULL){
    if(isvalid_pattern(pattern_string, strlen(text)) == 0){
      int* matches = find_matches(pattern_string, text);
      printf("%s ", pattern);
      int i = 0;
      /*while(matches[i] >= 0){
	printf("%d ", matches[i]);
	i++;
	}*/
      printf("%d\n", matches[0]);
      pattern = scan_pattern();
    }else{
      free(pattern);
      //free(matches);
      printf("Invalid pattern\n");
      return 4;
    }
  }
  free(pattern);
  //free(matches);
  return 0;
}
