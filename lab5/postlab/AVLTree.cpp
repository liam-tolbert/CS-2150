#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    size = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
    size = 0;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if(!find(x))
  {
    root = insert(root, x);
    size++;
    /*printTree();
      cout << "---------------------" << endl;*/
  }
}

AVLNode* AVLTree::insert(AVLNode*& node, const string& x){
  if(node == NULL){
    return new AVLNode(x);
  }

  //inserting normally
  if(x < node->value)
    node->left = insert(node->left, x);
  else if(x > node->value)
    node->right=insert(node->right, x);
  else
    return node;

  //adjust height
  node->height = max(height(node->left), height(node->right)) + 1;
  
  balance(node);
  
  return node;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    size--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(!find(x))return "";
  string path = "";
  AVLNode* y = root;
  while(y -> value != x){
    path += y -> value + " ";
    if(x < y->value)
      y = y -> left;
    else
      y = y -> right;
    
  }
  return path + x;
  
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* y = root;
  while(y != NULL){
    if(x > y -> value)
      y = y->right;
    else if(x < y->value)
      y = y -> left;
    else
      return true;
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return size;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if(getBalanceFactor(n) == 2){
    if(getBalanceFactor(n->right) < 0){
      n->right = rotateRight(n->right);
    }
    n = rotateLeft(n);
  }
  else if(getBalanceFactor(n) == -2){
    if(getBalanceFactor(n->left) > 0){
      n->left = rotateLeft(n->left);
    }
    n = rotateRight(n);
  }
  
}

int AVLTree::getBalanceFactor(AVLNode*& node){
  if(node == NULL)return 0;
  return height(node->right)-height(node->left);
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* x = n -> right;
  AVLNode* temp = x -> left;

  x -> left = n;
  n -> right = temp;

  n -> height = max(height(n->left), height(n->right))+1;

  x -> height = max(height(x->left), height(x->right))+1;

  return x;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* x = n -> left;
  AVLNode* temp = x -> right;

  x -> right = n;
  n -> left = temp;

  n -> height = max(height(n->left), height(n->right))+1;

  x -> height = max(height(x->left), height(x->right))+1;

  return x;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns 0.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
