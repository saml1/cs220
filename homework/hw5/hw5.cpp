//Sam Lipschitz
//slipsch3

#include <stdio.h>
#include <iostream>
#include "language_model.h"

int main(int argc, char* argv[]){
  using std::cin;
  using std::cout;
  using std::endl;
  using std::map;
  using std::tuple;
  using std::cerr;
  
  map<std::tuple<string, string, string>, int> model = buildModel(argv);

  //checking if buildModel was able to open specified filename
  for(map<tuple<string, string, string>, int>::const_iterator it = model.cbegin(); it != model.cend(); ++it){
    if(it->second < 0){
      cerr << "Invalid file list: " << argv[1] << endl;
      return 1;
    }
  }
  //checking for valid command and argument list
  int error = isValid(argc, argv);
  if(error != 0){
    return error;
  }

  doOperation(model, argv);

  return 0;
}
