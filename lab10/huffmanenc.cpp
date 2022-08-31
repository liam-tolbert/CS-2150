#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "heap.h"
#include "heapnode.h"

void getCode(heapnode* node, string code, map<string, string> &map){
  if(node == NULL)
    return;
  if(node -> left == NULL && node -> right == NULL){
    map[node -> data] = code;
  }
  
  getCode(node -> left, code + "0", map);
  getCode(node -> right, code + "1", map);
}

int main(int argc, char** argv) {
  
  // verify the correct number of parameters
  if (argc != 2) {
      cout << "Must supply the input file name as the one and only parameter" << endl;
      exit(1);
  }

  // attempt to open the supplied file
  // ifstream stands for "input file stream"
  ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit
  if (!file.is_open()) {
      cout << "Unable to open '" << argv[1] << "' for reading" << endl;
      exit(2);
  }

  // read in characters one by one, until reading fails (we hit the end of the file)
  char g;
  map<string, int> freqTable;
  heap h;
  
  while (file.get(g)) {
    if(g >= 32 && g <= 126){
      string str;
      str+=g;
      freqTable[str]++;
    }
  }

  for(auto i = freqTable.begin(); i != freqTable.end(); i++){
    if(i->first == " "){
      heapnode* node = new heapnode("space", i->second, NULL, NULL);
      h.insert(node);
    }
    else{
      heapnode* node = new heapnode(i->first, i->second, NULL, NULL);
      h.insert(node);
    }
  }
  
  while(h.size() > 1) {
    heapnode* node = new heapnode();
    heapnode* min1 = h.deleteMin();
    heapnode* min2 = h.deleteMin();

    node -> frequency = min1 -> frequency + min2 -> frequency;
    node -> left = min1;
    node -> right = min2;
    h.insert(node);
  }
  
  map<string, string> codes;
  getCode(h.findMin(), "", codes);

  for(auto i = codes.begin(); i != codes.end(); i++)
      cout << i->first << " " << i->second << endl;

  cout << "----------------------------------------" << endl;
  char c;
  int count = 0;
  int numBits = 0;

  file.clear();
  file.seekg(0);
  
  while(file.get(c)){
    if(c >= 32 && c <= 126){
      if(c == ' '){
	cout << codes["space"] << " ";
	numBits += codes["space"].length();
      }
      else{
	string character;
	character+=c;
	cout<< codes[character] << " ";
	numBits += codes[character].length();
      }
      count++;
    }
  }
  cout << endl;
  cout << "----------------------------------------" << endl;

  cout << "There are a total of " << count << " symbols that are encoded. " << endl;
  cout << "There are " << codes.size() << " distinct symbols used. " << endl;
  cout << "There were " << count * 8 << " bits in the original file. " << endl;
  cout << "There were " << numBits << " bits in the compressed file. " << endl;
  cout.precision(5);
  cout << fixed;
  cout << "This gives a compression ratio of " << 1.0 * (count*8)/numBits << endl;
  cout << "The cost of the Huffman tree is " << 1.0 * numBits/count << " bits per character. " << endl;
  // close the file
  file.close();

  return 0;
}














