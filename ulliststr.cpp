#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr:: push_back(const std::string& val){
  if(head_ == NULL){
    Item* add = new Item;
    head_ = add;
    tail_ = add;
    add -> val[4] = val;
    add -> first = 4;
    add -> last = 5;
  }

  else if(tail_ -> last == ARRSIZE){
    Item* add = new Item;
    Item* temp = tail_;
    tail_ = add;
    temp -> next = add;
    add -> prev = temp;
    add -> val[0] = val;
    add -> first = 0;
    add -> last = 1;
  }

  else{
    tail_ -> val[tail_ -> last] = val;
    tail_ -> last = (tail_ -> last) + 1;
  }
  size_++;
}

void ULListStr:: push_front(const std::string& val){
  if(head_ == NULL){
    Item* add = new Item;
    head_ = add;
    tail_ = add;
    add -> val[4] = val;
    add -> first = 4;
    add -> last = 5;
  }

  else if(head_ -> first == 0){
    Item* add = new Item;
    Item* temp = head_;
    head_ = add;
    temp -> prev = add;
    add -> next = temp;
    add -> val[ARRSIZE - 1] = val;
    add -> first = ARRSIZE -1;
    add -> last = ARRSIZE;
  }

  else{
    head_ -> val[(head_ -> first)-1] = val;
    head_ -> first = (head_ -> first) - 1;
  }
  size_++;
}

void ULListStr::pop_back(){
  if(tail_ == head_ && tail_ -> last == 1){
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
  }

  else if(tail_ -> last == 1){
    Item* remove = tail_;
    tail_ = tail_ -> prev;
    tail_ -> next = nullptr;
    delete remove;
  }

  else{
    tail_ -> last = (tail_ -> last) - 1;
  }

  size_--;
}

void ULListStr::pop_front(){
  if(head_ == tail_ && head_ -> first == ARRSIZE - 1){
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
    
  }

  else if(head_ -> first == ARRSIZE - 1){
    Item* remove = head_;
    head_ = head_ -> next;
    head_ -> prev = nullptr;
    delete remove;
  }

  else{
    head_ -> first = (head_ -> first) + 1;
  }

  size_--;
}

std::string const & ULListStr::back() const{
  return tail_ -> val[tail_ -> last - 1];
}

std::string const & ULListStr::front() const{
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  std::string* rtn = head_ -> val + (head_ -> first);
  int index = head_ -> first;
  Item* currItem = head_;
  for(size_t i = 0; i < loc; i++){
    if(index == ARRSIZE-1){
      currItem = currItem -> next;
      rtn = currItem -> val + (currItem -> first);
      index = 0;
    }

    else{
      rtn++;
      index++;
    }
  }

  return rtn;
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
