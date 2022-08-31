#include <iostream>
#include <string>
#ifndef LIFECYCLE_H
#define LIFECYCLE_H
using namespace std;

// Liam Tolbert, lct4am, 8/28/2021, LifeCycle.h
// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);

private:
    string name;
    int id;
};

int cmpMyObj(const MyObject o1, const MyObject o2);
MyObject getMaxMyObj(const MyObject o1, const MyObject o2MyObject);
void swapMyObj(MyObject& o1, MyObject& o2);

#endif
