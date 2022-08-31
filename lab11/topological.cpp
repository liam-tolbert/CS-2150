#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


/**
 * @brief A graph object implemented with adjacency lists and has the ability to topologically sort
 * 
 * @author Liam Tolbert
 * @date 11/29/2021
 * 
 */
class Graph {
public:
  /** Number of vertices in the graph*/
  int v;

  /** Array of vectors that represents adjacency lists for every vertex in the graph*/
  vector<string>* adjacents;

  /** Map that pairs nodes with an index in order to access the string associated with a node*/
  map<string, int> adjacencyIndices; 
  
  Graph(int v);
  vector<string> topSort();
  void addEdge(string v1, string v2);
  int find(vector<int> vec, int target);
  bool contains(map<string, int> map, string str);
};

/**
 * @brief Setting up the Graph object
 * 
 * @param v Number of vertices for the graph
 * 
 */
Graph::Graph(int v){
  this->v = v;
  adjacents = new vector<string>[v];
}

/**
 * @brief Adds an edge to the graph
 *
 * @param v1 First node to make an edge point from
 * @param v2 Second node to make an edge point to
 *
 */
void Graph::addEdge(string v1, string v2){
  adjacents[adjacencyIndices[v1]].push_back(v2);
}

bool Graph::contains(map<string, int> map, string str){
  for(auto const& x : map){
    if(x.first == str)
      return true;
  }
  return false;
}


/**
 * @brief Performs a topological sort on the graph
 *
 * This algorithm is shown in Slides #11
 *
 * @return A vector of the topologically sorted nodes in the graph
 *
 */
vector<string> Graph::topSort(){
  queue<string> q;
  vector<string> sorted;
  int counter = 0;

  vector<int> indegrees(v, 0);
  for(int i = 0; i < v; i++){
    for(string str : adjacents[i]){
      indegrees[adjacencyIndices[str]]++;
    }
  }
  
  for(auto const& x : adjacencyIndices){
    if(indegrees.at(x.second) == 0){
      q.push(x.first);
    }
  }
  
  while(!q.empty()){
    string vert = q.front();
    q.pop();
    sorted.push_back(vert);
    counter++;
    for(string w : adjacents[adjacencyIndices[vert]]){
      if(--indegrees.at(adjacencyIndices[w]) == 0){
	q.push(w);
      }
    }
  }
  if(counter != v) cout << "Cycle found!!" << endl;

  return sorted;
}

int main(int argc, char** argv){
  // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    string str;
    int numVertices = 0;
    unordered_set<string> inserted;
    file >> str;
    while (str != "0"){
      inserted.insert(str);
      file >> str;
    }
    numVertices = inserted.size();
    Graph g(numVertices);

    file.clear();
    file.seekg(0);
    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;    

    while(s1 != "0" && s2 != "0"){
      if(!g.contains(g.adjacencyIndices, s1)){
	int index = g.adjacencyIndices.size();
	g.adjacencyIndices[s1] = index;
      }
      if(!g.contains(g.adjacencyIndices, s2)){
	int index = g.adjacencyIndices.size();
	g.adjacencyIndices[s2] = index;
      }
      g.addEdge(s1, s2);
      file >> s1;
      file >> s2;
    }
    vector<string> sorted = g.topSort();
    for(string str : sorted){
      cout << str << " ";
    }
    cout << endl;

    // close the file before exiting
    file.close();
}
