/* 
 * File:   NodeList.cpp
 * Author: mahmo211
 * 
 * Created on November 8, 2016, 4:19 PM
 */

#include "NodeList.h"
#include "Node.h"
#include "Resistor.h"
#include <stddef.h>

using namespace std;

NodeList::NodeList(Node* _head) {
    head = _head;
}

NodeList::NodeList() {
    head = NULL;
}

NodeList::~NodeList() {
    Node* temp;
    while (head != NULL) {//Basically just deleting the first element and moving head forward
        temp = head;
        head = temp->getNext();
        delete temp;
    }
}

Node* NodeList::getHead() {
    return head;
}

/*This function adds a new node to the list*/
void NodeList::addNode(int ID) {
    //Check if this node already exists
    if (checkID(ID)) {
        return;
    }

    //Otherwise create a new node
    Node* temp = new Node(ID);
    //Check if the list is empty
    if (head == NULL || ID < head->getNodeID()) {
        temp->setNext(head);
        head = temp;
    } else {
        Node* currentNode = head;
        if (ID < head->getNodeID()) {//Check if this is the lowest node ID yet
            head = new Node(ID);
            head->setNext(currentNode);
        } else {
            //Otherwise just loop through the rest of the nodes to find the correct place for it
            while (ID > currentNode->getNodeID() && currentNode->getNext() != NULL) {
                currentNode = currentNode->getNext(); //Keep going through the node list
            }
            //Now add the new node AHEAD of the currentNode
            temp->setNext(currentNode->getNext());
            currentNode->setNext(temp);
        }
    }
}

/*This function adds a new resistor in the appropriate nodes*/
void NodeList::addResistor(string name, double res, int node1, int node2) {
    int connectedNodes[2] = {node1, node2};
    Resistor* newResister1 = new Resistor(name, res, connectedNodes);
    //I just wasted 2 hours to figure out that i need 2 new resistors... 
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARRRRRRRRRRGGGGHHHHHHH
    Resistor* newResister2 = new Resistor(name, res, connectedNodes);
    getNodeByID(node1)->addResistor(newResister1);
    getNodeByID(node2)->addResistor(newResister2);
}

/*This function looks for a particular nodeID, if no such node exists, return null*/
Node* NodeList::getNodeByID(int ID) const {
    Node* currentNode = head;
    //Make sure there is at least something in the node list
    if (head == NULL)
        return NULL;
    //Loop through all the nodes in the list until we find a match or reach the end
    while (ID != currentNode->getNodeID() && currentNode->getNext() != NULL)
        currentNode = currentNode->getNext();
    if (ID == currentNode->getNodeID())
        return currentNode;
    else
        return NULL;
}

/*This function looks for a node ID, returns true if ID is found*/
bool NodeList::checkID(int ID) {
    Node* currentNode = head;
    if (head == NULL)//Make sure there is at least a single node in the nodelist
        return false;
    //Loop through all the nodes in the list until we find a match or reach the end
    while (ID != currentNode->getNodeID() && currentNode->getNext() != NULL)
        currentNode = currentNode->getNext();
    if (ID == currentNode->getNodeID()) {
        return true;
    } else {
        return false;
    }
}

/*This function prints a specific node*/
void NodeList::printNode(int ID) {
    Node* node = getNodeByID(ID);
    node->print();
}

/*This function prints all the nodes*/
void NodeList::printAllNodes() {
    Node* toPrint = head;
    if (head == NULL)//Make sure there is something to print
        return;
    head->print(); //Print first element
    while (toPrint->getNext() != NULL) {//Keep going to the next element until the end
        toPrint = toPrint->getNext(); //Move forward one
        toPrint->print(); //Print
    }

}

/*This checks to see if a resistor name exists anywhere*/
bool NodeList::checkRes(string name) {
    //Make sure there is any nodes
    if (head == NULL)
        return false;
    //Loop through all the nodes
    Node* temp = head;
    while (temp->getNext() != NULL) {
        if (temp->checkRes(name))
            return true; //As soon as you find a match return true
        temp = temp->getNext();
    }
    return false;
}

/*This function prints a specific resistor*/
void NodeList::printRes(string name) {
    //We will assume the resitor exists for sure
    //Note: We are only going to print the first resistor that shows up
    if (head->checkRes(name)) {//Check the first element
        head->getRes(name)->print();
        return;
    }
    Node* temp = head;
    while (temp->getNext() != NULL) {//Loop through all nodes
        temp = temp->getNext();
        if (temp->checkRes(name)) {//If you find the right resistor
            temp->getRes(name)->print(); //Print it
            return; //And GTFO
        }
    }
}

/* This function looks for and returns pointers to both instances of a resistor
 * with a given name*/
Resistor** NodeList::findBothResistors(string name) const {
    int counter = 0; //This is a counter to keep track of how many resistors we've found so far
    Resistor** twoResistors = new Resistor*[2]; //Array to store pointers to both resistors
    if (head->checkRes(name)) {//Check the first element
        twoResistors[counter] = head->getRes(name);
        counter++;
    }
    Node* temp = head;
    while (temp->getNext() != NULL && counter < 2) {//Loop through nodes
        temp = temp->getNext();
        if (temp->checkRes(name)) {//If you find the resistor
            twoResistors[counter] = temp->getRes(name); //Add it to array
            counter++; //Increment counters
        }
    }
    return twoResistors;
    //TODO: REMEMBER TO DELETE THIS POINTER AFTER YOU'RE DONE WITH IT!!
}

/*This function modifies the value of a resistors*/
void NodeList::modifyRes(string name, double res) {
    Resistor** twoResistors = findBothResistors(name);
    twoResistors[0]->setResistance(res);
    twoResistors[1]->setResistance(res);
    delete[] twoResistors; //Oh God I really hope this works...
}

/*This function deletes a resistor*/
void NodeList::deleteRes(string name) {
    int counter = 0; //This is a counter to keep track of how many resistors we've found so far
    if (head->checkRes(name)) {//Check the first element
        head->deleteRes(name);
        counter++;
    }
    Node* temp = head;
    while (temp->getNext() != NULL && counter < 2) {//Loop through nodes
        temp = temp->getNext();
        if (temp->checkRes(name)) {//If you find the resistor
            temp->deleteRes(name);
            counter++; //Increment counters
        }
    }
    purgeNodes();//Make sure there is no empty nodes
}

/*This function deletes all nodes and resistors inside them*/
void NodeList::deleteAll() {
    Node* temp;
    while (head != NULL) {//Basically just deleting the first element and moving head forward
        temp = head;
        head = temp->getNext();
        delete temp;
    }
}

/*This function gets rid of all empty nodes*/
void NodeList::purgeNodes() {
    //Make sure there is any nodes
    if (head == NULL)
        return;
    //Loop through all the nodes
    Node* temp = head;
    while (temp->getNext() != NULL) {
        if (temp->getNumRes() <= 0){//When you find an empty node
            deleteNode(temp->getNodeID());//Delete it
        }
        temp = temp->getNext();
    }
}

/*This function deletes a specific node from the list*/
void NodeList::deleteNode(int ID) {
    Node* temp = head;
    if (head->getNodeID() == ID) {//Check if its the first element
        head = head->getNext();
        delete temp;
    } else {
        Node* previous;//Store past element
        while (temp->getNext() != NULL) {//Keep looking till you find the node
            previous = temp;
            temp = temp->getNext();
            if (temp->getNodeID() == ID) {//Once the node is found, delete it
                previous->setNext(temp->getNext());
                delete temp;
                return;
            }
        }
    }
}