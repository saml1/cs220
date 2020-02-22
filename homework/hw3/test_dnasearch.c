//Sam Lipschitz
//slipsch3

#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int main(){
  
  //char* filename = "test.txt";

  assert(isvalid_text("test.txt") == 0); //checking valid txt
  assert(isvalid_text("badtxt.txt") != 0); //checking invalid txt
  assert(isvalid_text("asfdf") != 0);//checking nonexistent file
  assert(isvalid_text("badtxt2.txt") != 0);
  
  /*if(isvalid_text(filename) != 0){
    printf("Invalid text\n");
    return 1;
    }*/

  assert(isvalid_pattern("Gtc",10) == 0);
  assert(isvalid_pattern("gAtCGaTc", 9) == 0);
  assert(isvalid_pattern("GTAC", 2) != 0);
  assert(isvalid_pattern("gtBc", 130) != 0);
  assert(isvalid_pattern("bgTc", 134) != 0);

  printf("All tests passed!\n");
  return 0;
}
