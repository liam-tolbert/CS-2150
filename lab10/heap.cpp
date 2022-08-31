// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "heapnode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
  h.push_back(new heapnode());
}

// builds a heap from an unsorted vector
heap::heap(vector<heapnode*> vec) : heap_size(vec.size()) {
    h = vec;
    h.push_back(h[0]);
    h[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(heapnode* x) {
    // a vector push_back will resize as necessary
    h.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapnode* x = h[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < h[hole/2] -> frequency); hole /= 2) {
        h[hole] = h[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    h[hole] = x;
}

heapnode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    heapnode* ret = h[1];
    // move the last inserted position into the root
    h[1] = h[heap_size--];
    // make sure the vector knows that there is one less element
    h.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    heapnode* x = h[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (h[child+1]->frequency < h[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->frequency > h[child]->frequency) {
            h[hole] = h[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    h[hole] = x;
}

heapnode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return h[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    h.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << h[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
      cout << h[i]->data << h[i]->frequency << " ";
        // next line from http://tinyurl.com/mf9tbgm
        //bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        //if (isPow2) {
        //    cout << endl << "\t";
        //}
    }
    cout << endl;
}
