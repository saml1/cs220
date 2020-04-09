//Sam Lipschitz
//slipsch3

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using std::string;

/* Returns 0 if valid input, 1 if invalid input */
int isValid(int argc, char* argv[]){
  //TODO: write me! make this method do cout stuff)
  return 0;
}

/* Calls method to do specified operation */
void doOperation(int argc, char* argv[]){
  //TODO: write me! (buildModel is helping)
}

/* Returns map of trigraphs from text files mentioned in argv[1] */
std::map<string, int> buildModel(char* argv[]){
  using std::cin;
  using std::cout;
  using std::endl;
  using std::map;
  using std::string;
  using std::vector;

  //create map where key is trigraph and value is its frequency
  map<string, int> model;
  
  std::ifstream ifile(argv[1]);
  if(!ifile.is_open()){//returns certain map if error occurs
    cout << "Invalid file list: " << argv[1] << endl;
    model["error"] = -1;
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
      // vector<string> words;
      words.push_back(word_t);
    }
    for(int i = -2; i <(int) words.size(); i++){
      string temp1;
      string temp2;
      string temp3;
      if(i == -2){
	temp1 = "<START_1>";
	temp2 = "<START_2>";
	temp3 = words[0];
      }else if(i == 1){
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
    }
  }
  
  return model;
}
