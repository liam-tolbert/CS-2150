#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/**
 * @author Liam Tolbert
 * @date 12/3/2021
 *
 *
 *
 */
struct PuzzNode
{
  /* The 3x3 2d array that stores the puzzle */
  int puzzle[3][3];

  /* The level of the node on the tree it is generated on */
  int level;

};

/**
 * @brief Making a new node, primarily for swapping. 
 *
 * @param puzz The 2d array that stores the puzzle of the new node. 
 * @param x1 The x-value of the first element to swap
 * @param y1 The y-value of the first element to swap
 * @param x2 The x-value of the second element to swap
 * @param y2 The y-value of the second element to swap
 * @param level The level of the node
 * 
 *
 *
 * @return A pointer to a new PuzzNode object
 */
PuzzNode* newNode(int puzz[3][3], int x1, int y1, int x2, int y2, int level){
  PuzzNode* node = new PuzzNode;

  memcpy(node->puzzle, puzz, sizeof node->puzzle);

  swap(node->puzzle[x1][y1], node->puzzle[x2][y2]);
  
  node->level = level;

  return node;
}

/**
 * @brief Is the provided puzzle solvable? 
 * This method returns true if the puzzle is solvable, otherwise false
 * 
 * @param puzzle The puzzle to be checked
 *
 * @return True for solvable, false for impossible
 *
 */
bool isSolvable(int puzzle[3][3]){
  int inversions = 0;
  for(int i = 0; i < 2; i++)
    for(int j = i + 1; j < 3; j++)
      if(puzzle[j][i] > 0 && puzzle[j][i] > puzzle[i][j])
	inversions++;

  return inversions % 2 == 0;
}

/**
 * @brief Is the provided puzzle sorted?
 * This method returns true if the puzzle is sorted, as in being in order from 1-8. The location of zero is checked elsewhere. 
 * 
 * @param puzzle The puzzle to be checked
 *
 * @return True for sorted, false otherwise
 *
 */
bool isSorted(int puzzle[3][3]){
  int prev = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
      if(puzzle[i][j] != 0){
	if(prev >= puzzle[i][j]){
	  return false;
	}
	prev = puzzle[i][j];
      }
    }
  return true;
}

/**
 * @brief Prints out the puzzle provided. 
 *
 */
void printList(int puzzle[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << puzzle[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 * @brief Generates all possible moves of a given puzzle. 
 * This method returns a collection of puzzles as possible moves from the given puzzle. 
 * 
 * @param puzzle The puzzle whose neighbors will be generated from
 * @param prevLvl Every time neighbors are generated from a Puzzle node, they are a level down from that node
 *
 * @return A vector of all possible moves
 *
 */
vector<PuzzNode*> generateNeighbors(int puzzle[3][3], int prevLvl){
  vector<PuzzNode*> neighbors;
  int i = 0, j = 0;
  bool flag = false;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(puzzle[i][j] == 0){
	flag = true;
	break;
      }
    }
    if(flag)
      break;
  }
  
  if(i != 0){
    PuzzNode* node = newNode(puzzle, i, j, i - 1, j, prevLvl+1);
    neighbors.push_back(node);
  }

  if(i != 2){
    PuzzNode* node = newNode(puzzle, i, j, i + 1, j, prevLvl+1);
    neighbors.push_back(node);
  }

  if(j != 0){
    PuzzNode* node = newNode(puzzle, i, j, i, j - 1, prevLvl+1);
    neighbors.push_back(node);
  }

  if(j != 2){
    PuzzNode* node = newNode(puzzle, i, j, i, j + 1, prevLvl+1);
    neighbors.push_back(node);
  }

  return neighbors;
}

/**
 * @brief Are the provided puzzles equal?
 * This method returns true if the first puzzle is equal to the other, otherwise false
 * 
 * @param puzz1 The first puzzle to be compared
 * @param puzz2 The second puzzle to be compared
 *
 * @return True for equal, false otherwise
 *
 */
bool isEqual(int puzz1[3][3], int puzz2[3][3])
{
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	if(puzz1[i][j] != puzz2[i][j]){
	  return false;
	}
      }
  }
  return true;
  
}

/**
 * @brief Helper method for use after calling generateNeighbors
 * This method returns true if a puzzle is within the PuzzNodes in a vector<PuzzNode*>, false otherwise
 * 
 * @param vec The vector to be searched
 * @param puzz The puzzle to be found
 * 
 * @return True for if the puzzle is found, false otherwise
 *
 */
bool contains(vector<PuzzNode*> vec, int puzz[3][3]){
  for(PuzzNode* p : vec){
    if(isEqual(p->puzzle, puzz)) return true;
  }
  return false;
}

/**
 * @brief Solving time!
 * This method uses breadth-first-search to find the minimum amount of steps required to solve an 8 puzzle.
 * 
 * @param start The puzzle to be solved
 *
 * @return The minimum steps to solve the puzzle
 *
 */
int solve(int start[3][3]){
  //vector<PuzzNode*> visited;
  unordered_set<string> visited;
  vector<PuzzNode*> neighbors;
  int steps = 0;
  queue<PuzzNode*> q;

  PuzzNode* root = newNode(start, 0, 0, 0, 0, 0);

  q.push(root);

  while(!q.empty()){
    PuzzNode* node = q.front();
    steps = node->level;
    
    if(isSorted(node->puzzle) && node->puzzle[2][2] == 0){
      break;
    }
    
    q.pop();

    neighbors = generateNeighbors(node->puzzle, steps);

    for(PuzzNode* puzz : neighbors){
      string str = "";
      for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++){
	  str += to_string(puzz->puzzle[i][j]);
	}
      if(visited.count(str) == 0){
	visited.insert(str);
	q.push(puzz);
      }
    }
    neighbors.clear();
  }
  return steps;
}

int main(){
  string el1, el2, el3,el4,el5,el6,el7,el8,el9;
  cout << "Enter Puzzle" << endl;
  cin >> el1;
  cin >> el2;
  cin >> el3;
  cin >> el4;
  cin >> el5;
  cin >> el6;
  cin >> el7;
  cin >> el8;
  cin >> el9;
  cout << "Solving Puzzle" << endl;

  int puzzList[3][3] = {{stoi(el1), stoi(el2), stoi(el3)}, {stoi(el4), stoi(el5), stoi(el6)}, {stoi(el7), stoi(el8), stoi(el9)}};

  PuzzNode* puzz = newNode(puzzList, 0, 0, 0, 0, 0);

  if(isSolvable(puzz->puzzle)){
    cout << solve(puzz->puzzle) << endl;
  }
  else
    cout << "IMPOSSIBLE" << endl;
}
