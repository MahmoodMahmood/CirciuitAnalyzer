/* 
 * File:   NodeList.h
 * Author: mahmo211
 *
 * Created on November 8, 2016, 4:19 PM
 */

#ifndef NODELIST_H
#define	NODELIST_H

#include "Node.h"
#include "Resistor.h"
#include <string>

using namespace std;

class NodeList {
private:
    Node *head;
    Node* getNodeByID(int ID) const;
    Resistor** findBothResistors(string name) const;
    void purgeNodes();
    void deleteNode(int ID);
public:
    NodeList(Node* _head);
    NodeList();
    ~NodeList();
    Node* getHead();
    void addNode(int ID);
    void addResistor(string name, double res, int node1, int node2);
    bool checkID(int ID);
    void printAllNodes();
    void printNode(int ID);
    bool checkRes(string name);
    void printRes(string name);
    void modifyRes(string name, double res);
    void deleteRes(string name);
    void deleteAll();
};

#endif	/* NODELIST_H */

