/* 
 * File:   Node.cpp
 * Author: mahmo211
 * 
 * Created on October 12, 2016, 9:51 PM
 */

#include "Node.h"
#include "Resistor.h"
#include <iostream>

using namespace std;

Node::Node(int _ID) {
    next = NULL;
    ID = _ID;
    resList.setHead(NULL);
    numRes = 0;
}

Node::~Node() {
}

Node* Node::getNext() {//Returns a pointer to the next element the node list
    return next;
}

void Node::setNext(Node * _next){//Sets the next pointer of node
    next = _next;
}

int Node::getNodeID(){//Returns ID of this node
    return ID;
}

int Node::getNumRes(){
    return numRes;
}

/*This function adds a new resistor to the resistorList*/
void Node::addResistor(Resistor* res){
    resList.addResistor(res);
    numRes++;
}

/*This function prints the header of the node then prints the resistor list*/
void Node::print() {
    std::cout << "Connections at node " << ID << ": " << numRes <<
            " resistor(s)" << endl;
    resList.print();
}

/*This function checks to see if a resistor exists*/
bool Node::checkRes(string name){
    return resList.checkRes(name);
}

/*This function locates a specific resistor by name*/
Resistor* Node::getRes(string name){
    return resList.getRes(name);
}

/*This function deletes a specific resistor from the resistor list*/
void Node::deleteRes(string name){
    resList.deleteRes(name);
    numRes--;
}