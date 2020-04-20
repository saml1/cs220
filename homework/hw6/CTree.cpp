#include "CTree.h"

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
    kids = child;
    return true;
  }else{
    return kids->addChild(ch);
  }
}

std::string CTree::toString(){
  //TODO: write me
  return "tt";
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

