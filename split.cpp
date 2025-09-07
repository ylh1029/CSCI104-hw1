/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
bool isOdd(const int val);

Node* insert(Node* add, Node*& list);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if(in != nullptr){ 
    if(isOdd(in -> value)){
      in = insert(in, odds);
    }

    else {
      in = insert(in, evens);
    }

    split(in, odds, evens);
  }
}

bool isOdd(const int val){
  return val%2;
}

Node* insert(Node* add, Node*& list){
  Node* rtn = add -> next;
  add -> next = nullptr;

  if(list == nullptr){
    list = add;
  }

  else if (list -> next == nullptr){
    list -> next = add;
  }

  else{
    insert(add, list -> next);
  }

  return rtn;
}

/* If you needed a helper function, write it here */
