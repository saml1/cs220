#include "CTree.h"
#include <iostream>
#include <vector>
#include <map>
using std::vector;
using std::map;
std::ostream& operator<<(std::ostream& os, CTree& rt){
  //TODO: write me
  return os;
}

CTree::CTree(char ch){//head constructor
  data = ch;
  kids = NULL;
  sibs = NULL;
  prev = NULL;
}

bool CTree:: addChild(char ch){
  if(kids == NULL){
    CTree * child = new CTree(ch);
    child->prev = this;
    kids = child;
    return true;
  }else{
    CTree * cur = this->kids;
    while(cur){
      if(cur->data == ch){
	return false;
      }else{
	return cur->addChild(ch);
      }
    }
    return kids->addChild(ch);
  }
}

std::string CTree::toString(){
  //TODO: write me
  //vector<char> chars;
  map<char, char> chars;
  //if(this->kids != NULL){
    CTree * cur = this->kids;
    //}//CTree * cur = this;
  std:: string temp;
  //int temp = 0;
  while(cur){
    //std::cout<<"ok"<<std::endl;
    //temp += cur-> data;
    //temp += "\n";
    //chars.push_back(cur->data);
    chars[cur->data] = cur->data;
    if(cur->kids != NULL){
      cur = cur->kids;
    }else if(cur->sibs != NULL){
	cur = cur->sibs;
      //TODO: fix method to work with everything
      }else{
	cur = NULL;
    }
  }
  temp += this->data;
  temp += "\n";
  for(map<char, char>::iterator it= chars.begin(); it != chars.end(); ++it){
    temp += it->first;
    temp += "\n";
  }
  std::cout << temp << "done" << std::endl;
  return temp;
}

CTree:: ~CTree(){
  //TODO: this could be wrong
}

bool CTree::addSibling(char ch){
  return false;
  //TODO: write me
}

bool CTree::addSibling(CTree *root){
  return false;
  //TODO: write me
}

CTree& CTree::operator^(CTree& rt){
  //TODO: write me
  this->addChild(&rt);
  return *this;
}

bool CTree:: addChild(CTree *root){
  return true;
  //TODO: write me
}

