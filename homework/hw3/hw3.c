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
  while(parse == 1){//copying data from text file to text
    if(!isspace(temp)){
      text[count] = toupper(temp);
      count++;
    }
    parse = fscanf(input, "%c", &temp);
  }
  
  text[count] = '\0'; //adding null terminator to end of text
  fclose(input);

  char* pattern = scan_pattern();
  char pattern_arr[15001];
  int i = 0;
  do{//converting pointer from scan_pattern to a pattern_arr[]
    pattern_arr[i] = toupper(pattern[i]);
    i++;
  }while(pattern[i] != '\0');
  pattern_arr[i]='\0';
  int plen = (int)strlen(pattern_arr);
  int tlen = (int)strlen(text);

  //if the pattern is invalid and it's not from user entering ctrl-d
  if(isvalid_pattern(pattern_arr, plen) != 0 && pattern[0] != (char)32){
    printf("Invalid pattern\n");
    free(pattern);
    return 4;
  }

  //repeat process as long as pattern is valid/not from ctrl-d
  while(pattern[0] != (char)32 && pattern != NULL && isvalid_pattern(pattern_arr, plen)==0){
    printf("%s ", pattern_arr);
    int loc = -1;
    int foundmatch = 0;
    for(int j = 0; j < tlen-plen; j++){
      
      if(pattern_match(text, tlen, pattern_arr, plen, j) != loc && pattern_match(text, tlen, pattern_arr, plen, j) >=0){//will print match locationif it's after previous match location 
	printf("%d ", pattern_match(text, tlen, pattern_arr, plen, j));
	loc = pattern_match(text, tlen, pattern_arr, plen, j);
	foundmatch = 1;
      }
    }
    if(foundmatch == 0){
      printf("Not found");
    }
    printf("\n");
    free(pattern);
    
    pattern = scan_pattern();//repeats process of converting pointer from scan_pattern to pattern_arr
    if(pattern != NULL && pattern_arr[0] != (char)32){
      i=0;
      do{
	
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
    
  }
  
  free(pattern);
  return 0;
}
