//my_node.h

#ifndef MY_NODE_H
#define MY_NODE_H

template<typename T>
class my_node {

 private:

  T payload;  //the payload stored in this node
  my_node<T>* next;  //the pointer to node after this one

 public:

  //constructors
  my_node(T value): payload(value), next(nullptr) { }
  my_node(T value, my_node<T>* ptr): payload(value), next(ptr) { }

  //getters
  T get_data() const         { return payload; }
  my_node<T>* get_next() const   { return next; }

  //setters
  void set_data(T value)     { payload = value; }
  void set_next(my_node<T>* ptr) { next = ptr; }

};

#endif
