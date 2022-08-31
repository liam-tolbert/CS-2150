#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp
/**
 * @brief A seeded prodecurally generated Middle-Earth object.
 * 
 * @author Aaron Bloomfield
 * @author Liam Tolbert
 * @date 11/27/2021
 * 
 */
class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    void print();
    void printTable();
    float getDistance(const string& city1, const string& city2);
    vector<string> getItinerary(unsigned int length);

private:
    /** How many cities will be generated in the world*/
    int num_city_names; 
    
    /** X size of the world*/
    int xsize; 
    
    /** Y size of the world*/
    int ysize; 
    
    /** Hashmap of X positions paired with each city generated*/
    unordered_map<string, float> xpos; 
    
    /** HashmapY positions paired with each city generated*/
    unordered_map<string, float> ypos; 
    
    /** A vector of each city generated*/
    vector<string> cities;
    
    /** Cities paired with distance required to go to the next specified city*/
    unordered_map<string, unordered_map<string, float>> distances; 

    /** Mersenne-Twister random number engine*/
    mt19937 gen; 
};

#endif
