//Sam Lipschitz
//slipsch3

#include <stdio.h>
#include <iostream>
#include "language_model.h"

int main(int argc, char* argv[]){
  using std::cin;
  using std::cout;
  using std::endl;

  std::map<std::tuple<string, string, string>, int> model = buildModel(argv);
  if(model[std::make_tuple("error", "error", "error")] == -1 || argc == 1){
    cout << "Invalid file list: " << argv[1] << endl;
    return 1;
  }

  int error = isValid(argc, argv);
  if(error != 0){
    return error;
  }

  //dooperation

  return 0;
}
