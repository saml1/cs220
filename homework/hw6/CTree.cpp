#include "CTree.h"
#include <iostream>

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
  CTree * cur = this;
  std:: string temp;
  while(cur){
    //std::cout<<"ok"<<std::endl;
    temp += cur-> data;
    temp += "\n";
    if(cur->kids != NULL){
      cur = cur->kids;
    }else{
      cur = NULL;
      //TODO: fix method to work with everything
    }
  }
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

