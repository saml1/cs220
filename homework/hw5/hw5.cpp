//Sam Lipschitz
//slipsch3

#include <stdio.h>
#include <iostream>
#include "language_model.h"

int main(int argc, char* argv[]){
  using std::cin;
  using std::cout;
  using std::endl;

  if(isValid(argc, argv) == 1){
    return 1;
  }

  buildModel(argv);

  return 0;
}
