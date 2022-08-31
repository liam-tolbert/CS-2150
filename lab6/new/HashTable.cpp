#include "HashTable.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>
//Liam Tolbert, lct4am, 10/15/2021,HashTable.cpp
using namespace std;

HashTable::HashTable(int b){
  buckets = b;
  // separate chaining
  table = new list<string>[buckets];
}

void HashTable::insert(string word){
  int index = hash(word);
  table[index].push_back(word);
}

bool HashTable::contains(string word){
  list<string>::iterator i;
  int index = hash(word);
  if(table != NULL)
    {
      for(i = table[index].begin(); i != table[index].end(); i++){
	if(*i == word)
	  return true;
      }
    }
  return false;
}

// 37 is the prime number
int HashTable::hash(string word){
  int val = 0;
  for(int i = 0; i < word.length(); i++){
    val = val * 37 + word[i];
  }
  return val % buckets < 0 ? -1 * (val % buckets) : val % buckets;
}

