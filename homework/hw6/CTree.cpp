#include "CTree.h"
#include <iostream>
#include <vector>
#include <map>
using std::vector;
using std::map;
using std::cout;
using std::endl;
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
  if(kids == NULL){//has no children so will always be successful
    CTree * child = new CTree(ch);
    child->prev = this;
    kids = child;
    return true;
  }else{
    CTree * cur = this->kids;
    while(cur){
      if(cur->data == ch){//if child already exists
	return false;
      }else if(cur->data < ch){//new child should go after cur
	if(cur->sibs == NULL){//will always be successful if cur doesn't have siblings
	  CTree* child = new CTree(ch);
	  child->prev = cur;
	  cur->sibs = child;
	  //cout<<"here"<<endl;
	  return true;
	}else if((cur->sibs)->data > ch){//if child's data fits after cur
	  CTree* child = new CTree(ch);
	  child->prev = cur;
	  child->sibs = cur->sibs;
	  (cur->sibs)->prev = child;
	  cur->sibs = child;
	  return true;
	}else if((cur->sibs)->data == ch){
	  return false;
	}else{
	  cur =	cur->sibs;
	}
      }else if((cur->sibs)->data > ch){//new chlid will go before cur
	CTree* child = new CTree(ch);
	child->sibs = cur;
	child->prev = cur->prev;
	if((cur->prev)->kids == cur){
	  (cur->prev)->kids = child;
	}else{
	  (cur->prev)->sibs = child;
	}
	cur->prev = child;//TODO: check for working with all
      }
    }
    return kids->addChild(ch);
  }
}

std::string CTree::toString(){
  map<char, char> chars;
  //CTree * cur = this->kids;
  std::string str;//string to hold all data
  str += this-> data;//adding "top letter"
  str+= "\n";
  if(this->kids != NULL){
    str += (this->kids)->data;
    str += "\n";
    CTree * cur = (this->kids)->sibs;
    while(cur != NULL){
      str += cur->data;
      str += "\n";
      cur = cur->sibs;
      //cout << "here"<< endl;
    }
  }
  /* if(this->kids != NULL){
    for(CTree* cur = this->kids; cur != NULL; cur = cur->kids){
      str += cur->data;
      str += "\n";
    }
  }
  if(this->sibs != NULL){
    for(CTree* cur = this->sibs; cur != NULL; cur = cur->sibs){
      str += cur->toString();
    }
    }*/
  /*int levels = 0;
  if(this->kids == NULL){
    std::cout<<this->data<<std::endl;
    return str;
  }
  for(CTree * cur = this->kids; cur != NULL; cur = cur->sibs){
    str+=cur->data;
    str += "\n";
    while(cur->kids != NULL){
      cur = cur->kids;
    }
    }*/
  //std::cout<<str<<std::endl;
  return str;
  /*while(cur){
    str+=cur->data + "\n";
    if(cur->kids){
      cur = cur->kids;
      levels += 1;
    }else{
      for(int i = 0; i < levels; i++){
	cur = cur->
      }
    }
    }*/
}
/*std::string CTree::toString(){
  //TODO: write me
  //vector<char> chars;
  map<char, char> chars;
  //if(this->kids != NULL){
  //CTree * cur = this->kids;
    //}//CTree * cur = this;
  std:: string temp;
  //int temp = 0;
  for(CTree* cur = ){
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
  cur = this->sibs;
  while(cur){
    temp += cur->toString();
    cur = cur->sibs;
  }
  std::cout << temp << "done" << std::endl;
  return temp;
  }*/

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
  if(root->prev != NULL || root->sibs != NULL){
    return false;
  }
  CTree* cur = this->kids;
  while(cur){
    if(cur == root){
      return false;
    }else{
      cur = cur->sibs;
    }
  }
  root->prev = this;
  if(kids == NULL){
    kids = root;
    return true;
  }else{
    cur = this->kids;
    while(cur){
      if(cur->sibs == NULL){
	cur->sibs = root;
	root->sibs = cur;
	return true;
      }else{
	cur = cur->sibs;
      }
    }
  }
  return false;
  //TODO: fix me
}

