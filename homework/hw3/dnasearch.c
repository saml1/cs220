//Sam Lipschitz
//slipsch3

#include "dnasearch.h"


int isvalid_text(char* filename){
  FILE* input = fopen(filename, "r");

  if(input == NULL){
    printf("Error: could not open file\n");
    return 2;
  }

  char tp = 0;//char to take scanf's chars
  int count = 0;//total number of chars
  int parse = fscanf(input, "%c", &tp);
  
  if(!isspace(tp)){//doesn't include whitespaces
    count = parse;
  }
  if(!isupper(tp)){//makes everything uppercase
    tp = toupper(tp);
  }

  //checks for invalid chars
  if(!isspace(tp) && tp != 'A' && tp!= 'C' && tp!= 'G' && tp!= 'T'){
    fclose(input);
    return 1;
  }

  while(parse == 1){//while scanf picked up a char
    parse = fscanf(input, "%c", &tp);
    if(!isspace(tp)){//repeats above process
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

  if((count == 0) || count > 15000){//maximum count is 15000
    fclose(input);
    return 1;
  }
  fclose(input);
  return 0;//if text is valid

  
}

int isvalid_pattern(char pattern[], int length){
  if((int)strlen(pattern) > length){//pattern is invalid if it's longer than text
    return 1;
  }
  for(int i = 0; i < (int)strlen(pattern); i++){//loops through every char in pattern
    if(toupper(pattern[i]) != 'A' && toupper(pattern[i]) != 'C' && toupper(pattern[i]) != 'G' && toupper(pattern[i]) != 'T'){//if there's an invlid char
      return 1;
    }
  }
  return 0;
}

char* scan_pattern(){
  char temp; //char to take scanf's chars
  char* pattern;//pointer for scan_pattern to return
  int size = 0;//total size of pattern
  int end = 0; //1 means not ctrl-d (scanf coud pick up a char); 0 is otherwise 
  if(scanf("%c", &temp) == 1){//makes sure there's a pattern for scanf
    end = 1;
    while(isspace(temp)){//skips over whitespaces
      scanf("%c", &temp);
    }
  }
  if(end == 0){//returns pattern with (char)32 '\0' to signify that there's no pattern to scan
    pattern = malloc(sizeof(char)*2);
    pattern[0] = (char)32;
    pattern[1] = '\0';
    return pattern;
  }
  do{
    
    size++;
    
    if(size == 1){//must allocate memory if it's the first char
      pattern = calloc(1, sizeof(char));
    }else{
      pattern = realloc(pattern, sizeof(char)*size);//increase memory allocated to include new char
    }
    pattern[size-1]=temp;
    
  }while(scanf("%c", &temp) == 1 && !isspace(temp));//while there's a non-whitespace char to scan
  
  if(size > 0){//adds on a null terminator to end of pattern
    pattern = realloc(pattern, sizeof(char)*size+1);
    pattern[size] = '\0';
    return pattern;
    }
  
  return NULL;
  
}

//This was made before I read the entire hw3 doc
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
  for(int i = start_at; i < tlen-plen+1; i++){//looking for match starting at index start_at
    int match = 0;
    for(int j = 0; j < plen; j++){
      if(toupper(p[j]) != toupper(t[i+j])){//if it's not a match
	match = 1;
	break;
      }
    }
    if(match == 0) {//means match was found at index i
      return i;
    }
  }
      
  return -1;
}
