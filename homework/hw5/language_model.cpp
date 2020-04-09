//Sam Lipschitz
//slipsch3

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <tuple>
#include "language_model.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::tuple;

/* Returns 0 if valid input (buildModel/main check for invalid file list) */
int isValid(int argc, char* argv[]){
  if((argc < 3) || (*argv[2] != 'a' && *argv[2] != 'd' && *argv[2] != 'c' && *argv[2] != 'f')){
    cout << "Invalid command: valid options are a, d, c, and f" << endl;
    return 2;
  }
  if(*argv[2] == 'f' && argc < 5){
    cout << "Invalid argument list: f requires two additional command-line arguments" << endl;
    return 3;
  }
  return 0;
}

/* Calls method to do specified operation */
void doOperation(std::map<std::tuple<string, string, string>, int> model, char* argv[]){
  if(*argv[2] == 'a'){
    for(map<tuple<string, string, string>, int>::const_iterator it = model.cbegin(); it != model.cend(); ++it){
      cout << it->second << " - [" << std::get<0>(it->first) << " " << std::get<1>(it->first) << " " << std::get<2>(it->first) << "]" << endl;
    }
  }
  if(*argv[2] == 'd'){
    for(map<tuple<string, string, string>, int>::reverse_iterator it = model.rbegin(); it != model.rend(); ++it){
      cout << it->second << " - [" << std::get<0>(it->first) << " " << std::get<1>(it->first) << " " << std::get<2>(it->first) << "]" << endl;
    }
  }
}

/* Returns map of trigraphs from text files mentioned in argv[1] */
std::map<std::tuple<string, string, string>, int> buildModel(char* argv[]){
  //create map where key is trigraph and value is its frequency
  map<tuple<string, string, string>, int> model;
  
  std::ifstream ifile(argv[1]);
  if(!ifile.is_open()){//returns certain map if error occurs
    model[std::make_tuple("error", "error", "error")] = -1;
    return model;
  }

  string temp;
  vector<string> filenames;//vector with list of filenames
  while(ifile >> temp){
    filenames.push_back(temp);
  }
  
  //going through each filename and adding trigraphs to model
  for(vector<string>::iterator it = filenames.begin(); it != filenames.end(); ++it){
    std::ifstream tempfile(*it);
    if(!tempfile.is_open()){
      cout << "Invalid file: " << *it << endl;
    }
    string word_t;
    vector<string> words;
    while(tempfile >> word_t){//adding all words from current txt file to vector words
      words.push_back(word_t);
    }
    for(int i = -2; i <(int) words.size(); i++){
      //temp1, temp2, and temp3 are 3 words in each trigram
      string temp1;
      string temp2;
      string temp3;
      if(i == -2){
	temp1 = "<START_1>";
	temp2 = "<START_2>";
	temp3 = words[0];
      }else if(i == -1){
	temp1 = "<START_2>";
	temp2 = words[0];
	temp3 = words[1];
      }else if(i == (int)words.size() - 1){
	temp1 = words[i];
	temp2 = "<END_1>";
	temp3 = "<END_2>";
      }else if(i == (int)words.size() - 2){
	temp1 = words[i];
	temp2 = words[i+1];
	temp3 = "<END_1>";
      }else{
	temp1 = words[i];
	temp2 = words[i + 1];
	temp3 = words[i + 2];
      }
      //adding trigram to model
      if(model.map::find(std::make_tuple(temp1, temp2, temp3)) == model.end()){
	model[std::make_tuple(temp1, temp2, temp3)] = 1;
      }else{
	model[std::make_tuple(temp1, temp2, temp3)] += 1;
      }
    }
  }
  
  return model;
}
