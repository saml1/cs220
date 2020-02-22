//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int main(){
  /*if(argc != 2){
    printf("Error: must include input file name\n");
    return 1;
    }*/

  char* filename = "test.txt";

  if(isvalid_text(filename) != 0){
    printf("Invalid text\n");
    return 1;
  }

  
  
  return 0;
}
