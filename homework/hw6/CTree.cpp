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
	//cout<<"here"<<endl;
	if((cur->prev)->kids == cur){
	  (cur->prev)->kids = child;
	}else{
	  (cur->prev)->sibs = child;
	}
	cur->prev = child;//TODO: check for working with all
	return true;
      }
    }
    return kids->addChild(ch);
  }
}

std::string CTree::toString(){
  //map<char, char> chars;
  //CTree * cur = this->kids;
  std::string str;//string to hold all data
  str += this-> data;//adding "top letter"
  str+= "\n";
  if(this->kids != NULL){
    str += (this->kids)->data;
    str += "\n";
    CTree * depth = (this->kids)->kids;
    if(depth){str += depth->toString();}
    /*while(depth){
      str += depth->data;
      str += "\n";
      CTree * traversal = depth->sibs;
      while(traversal){
	str += traversal->data;
	str += "\n";
	traversal = traversal->sibs;
      }
      depth = depth->kids;
      }*/
    CTree * cur = (this->kids)->sibs;
    while(cur != NULL){
      str += cur->data;
      str += "\n";
      if(cur->kids != NULL){
	CTree* temp = cur->kids;
	if(temp){str += temp->toString();}
	/*while(temp){
	  str += temp->data;
	  str += "\n";
	  temp = temp->kids;
	  cout<<"heeer"<<endl;
	  }*/
      }
      cur = cur->sibs;
      //cout << "here"<< endl;
    }
  }
  /*if(this->sibs != NULL){
    CTree * cur = (this->sibs);
    while(cur!= NULL){
      //cout << "ok" << endl;
      //str += cur->toString();
      //cur = cur->sibs;
      str += cur->data;
      str += "\n";
      CTree * temp = cur->sibs;
      while(temp){
	str += temp->data;
	str += "\n";
	temp = temp->sibs;
      }
      cur = cur->sibs;
    }
  }*/
  if(this->sibs){
    str += (this->sibs)->toString();
  }
  return str;
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
/*
bool CTree:: addChild(CTree *root){
  if(root->prev != NULL || root->sibs != NULL){
    return false;
  }//root must not have prev or sibs
  CTree* cur = this->kids;
  while(cur){//making sure that no data matches
    if(cur == root){
      return false;
    }else{
      cur = cur->sibs;
    }
  }
  if(this->addChild(root->data)){
    cur = this->kids;
    while(cur->data != root->data){
      cur = cur->sibs;
    }
    if(cur->sibs == NULL){//then will always be successful
      cur->sibs = root->kids;
    }else if((cur->sibs)->data < root->data){
      CTree * temp = cur->sibs;
      if((temp->sibs)->data > root->data && (temp->prev)->data < root->data){
	cur->kids = root->kids;
      }else{
	temp = temp->sibs;
      }
    }
    return true;
  }else{
    return false;
  }
  
  return false;
  //TODO: fix me
}
*/

bool CTree:: addChild(CTree *root){
  if(root->prev != NULL || root->sibs != NULL){
    return false;
  }//root must not have prev or sibs 
  CTree* cur = this->kids;
  //cout << "here3" << endl;
  while(cur){
    //cout << "here4" << endl;
    if(cur == root || cur->data == root->data){//making sure no doubles
      return false;
    }else{
      cur = cur->sibs;
    }
  }
  if(this->kids == NULL){
    this->kids = root;
    return true;
  }else if((this->kids)->data < root->data){//root will go after this->kids
    cur = (this->kids)->sibs;
    //cout << "here2" << endl;
    if(cur == NULL || cur->data > root->data){
      //cout << "here1" << endl;
      root->sibs = cur;
      root->prev = this->kids;
      (this->kids)->sibs = root;
      if(cur != NULL){
	cur->prev = root;
      }
      return true;
    }
  }
  else{//root goes before
    //cout << "here" << endl;
    /*if(!addChild(root->data)){
      return false;
    }
    CTree * target = this->kids;
    while(target){
      if(target->data == root->data){
	break;
      }
    }
    target->kids = root->kids;*/
    root->sibs = this->kids;
    root->prev = this;
    (this->kids)->prev = root;
    this->kids = root;
    return true;
  }
  //cout << "no" << endl;
  return false;
}
