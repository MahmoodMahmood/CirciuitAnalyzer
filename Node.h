/* 
 * File:   Node.h
 * Author: JC and VB
 * Author: TSA
 *
 * Updated on August 24, 2016, 01:40 PM
 * Created on October 6, 2013, 12:58 PM
 */

#ifndef NODE_H
#define NODE_H

#include "ResistorList.h"
#include "Resistor.h"
#include <string>

using namespace std;

class Node {
private:
    int voltage; //Node voltage
    int ID; //Node ID
    int numRes;//Number of resistors connected to this node
    Node* next; //Pointer to next node in the list
    ResistorList resList;// Linked list of resistors
    
public:
    Node(int _ID);
    ~Node();

    Node* getNext(); //Returns a pointer to the next element the node list
    int getNodeID();
    
    void setNext(Node* _next);
    void addResistor(Resistor* res);
    void print();
    void resetNode();
    bool checkRes(string name);
    Resistor* getRes(string name);
    int getNumRes();
    void deleteRes(string name);
};

#endif /* NODE_H */

