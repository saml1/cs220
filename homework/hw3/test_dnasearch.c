//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Error: must include input file name\n");
    return 1;
  }

  char* filename = argv[1];

  if(isvalid_text(filename) != 0){
    printf("Invalid text\n");
    return 1;
  }

  
  
  return 0;
}
