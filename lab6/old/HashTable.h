#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
// Liam Tolbert, lct4am, 10/15/2021, HashTable.h
class HashTable{
 public:
  HashTable(int b);

  void insert(string word);
  int hashFunction(string word);
  bool contains(string word);
 private:
  int buckets;
  list<string> *table;
};

#endif
