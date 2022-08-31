#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(MiddleEarth me, const string& start, vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    
    // TODO: YOUR CODE HERE
    string start = dests[0];
    cout << "Minimum path has distance " << computeDistance(me, start , dests) << ": ";
    printRoute(me, start, dests);
    return 0;
}

/**
 *
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 *
 * @param me The Middle-Earth object
 * @param start The starting city
 * @param dests A vector of each desintation in the itinerary
 * 
 * @return A float of the shortest distance required to travel through all the cities
 */
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  
  float minPath = 2147483647.0;
  do {
    float pathWeight = 0;

    string x = start;
    for(int i = 0; i < dests.size(); i++){
      pathWeight += me.getDistance(x, dests.at(i));
      x = dests.at(i);
    }
    pathWeight += me.getDistance(x, start);

    minPath = min(pathWeight, minPath);
    
  }while(next_permutation(dests.begin(), dests.end()));
  
  return minPath;
}

/**
 *
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.
 * The output should be similar to:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 *
 * @param me The Middle-Earth object
 * @param start The starting city
 * @param dests A vector of each desintation in the itinerary
 *
 *
 */

void printRoute(MiddleEarth me, const string& start, vector<string>& dests) {
    // TODO: YOUR CODE HERE
  float minPath = 2147483647.0;
  vector<string> path(dests.size() + 1, "");
  do {
    vector<string> newPath(dests.size() + 1, "");
    float pathWeight = 0;
    string x = start;
    for(int i = 0; i < dests.size(); i++){
      pathWeight += me.getDistance(x, dests.at(i));
      cout << x << endl;
      newPath[i] = x;
      x = dests.at(i);
    }
    pathWeight += me.getDistance(x, start);
    newPath[newPath.size() - 1] = start;

    if(pathWeight < minPath){
      minPath = pathWeight;
      path = newPath;
    }
    
  }while(next_permutation(dests.begin(), dests.end()));

  for(int i = 0; i < path.size(); i++){
    if(i != path.size() - 1)
      cout << path[i] << " -> ";
    else
      cout << path[i] << endl;
  }
}
