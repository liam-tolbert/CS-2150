// Insert your header information here
// Liam Tolbert, lct4am, 10/2/2021, TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  root -> left = NULL;
  root -> right = NULL;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(root);
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree == NULL)
    return;
  cleanTree(tree->left);
  cleanTree(tree->right);
  delete tree;
  root = NULL;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if(val != "-"
     && val != "+"
     && val != "*"
     && val != "/"){
    TreeNode* node = new TreeNode(val);
    node -> left = node -> right = NULL;
    expressionStack.push(node);
  }
    
  else{
    if(!expressionStack.empty()){
      TreeNode* node = new TreeNode(val);

      TreeNode* t1 = expressionStack.top();
      expressionStack.pop();
      TreeNode* t2 = expressionStack.top();
      expressionStack.pop();

      node->right = t1;
      node->left = t2;

      expressionStack.push(node);
    }
  }
  root = expressionStack.top();
  
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if(tree == NULL)
    return;
  cout << tree->value << " ";
  printPrefix(tree->left);
  printPrefix(tree->right);
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  bool flag = false;
  if(tree == NULL)
    return;
  if(tree->left != NULL && tree->right != NULL){
    cout << "(";
    flag = true;
  }
  printInfix(tree->left);
  cout << (flag ? " " : "") << tree->value << (flag ? " " : "");
  printInfix(tree->right);
  if(tree->left != NULL && tree->right != NULL)
    cout << ")";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if(tree == NULL)
    return;
  printPostfix(tree->left);
  printPostfix(tree->right);
  cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  if(tree->value == "?"){
    return 0;
  }
  if(tree->left == NULL && tree->right == NULL){
    return stoi(tree->value);
  }
  
  int leftCalc = calculate(tree->left);
  int rightCalc = calculate(tree->right);

  if(tree->value == "+"){
    return leftCalc + rightCalc;
  }
  if(tree->value == "-")
    return leftCalc - rightCalc;
  if(tree->value == "*")
    return leftCalc*rightCalc;
  return leftCalc/rightCalc;
}


//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int result = calculate(root);
  while(!expressionStack.empty())
    expressionStack.pop();
  cleanTree(root);
  return result;
}
