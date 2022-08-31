#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

//Liam Tolbert, lct4am, 9/6/2021, List.cpp

List::List()
{
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
}

List::List(const List& source)
{
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
      }
}

List::~List()
{
  
}

List& List::operator=(const List& source){
  if (this == &source) {
      // The two are the same list; no need to do anything
      return *this;
  } else {
      // Clear out anything this list contained
      // before copying over the items from the other list
      makeEmpty();

      // Make a deep copy of the list
      ListItr iter(source.head->next);
      while (!iter.isPastEnd()) {
          insertAtTail(iter.retrieve());
          iter.moveForward();
      }
      }
  return *this;
}

bool List::isEmpty() const{
  return false;
}

void List::makeEmpty(){
  
}

ListItr List::first(){
  ListItr itr(head->next);
  return itr;
}

ListItr List::last(){
  ListItr itr(tail->previous);
  return itr;
}

void List::insertAfter(int x, ListItr position){
  
}

void List:: insertBefore(int x, ListItr position){
  
}

void List::insertAtTail(int x){
  ListNode* node = new ListNode();
  node->value = x;
  node->next = tail;
  node->previous = tail->previous;
  tail->previous->next = node;
  tail->previous = node;
  count++;
}

ListItr List::find(int x){
  return NULL;
}


void List::remove(int x){
  
}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  if(forward){
    ListItr itr = source.first();
    while(!itr.isPastEnd()){
      cout << itr.retrieve() << " ";
      itr.moveForward();
    }
  }
  else{
    ListItr itr = source.last();
    while(!itr.isPastBeginning()){
      cout << itr.retrieve() << " ";
      itr.moveBackward();
    }
  }
}
