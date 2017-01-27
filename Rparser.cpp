/* 
 * File:   Rparser.cpp
 * Author: mahmo211
 * 
 * Created on October 12, 2016, 9:53 PM
 */

#include "Rparser.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "NodeList.h"

using namespace std;

Rparser::Rparser() {
}

Rparser::~Rparser() {

}

/*This function deals with the insertR command*/
void Rparser::insertR(stringstream& sStream, NodeList& nodes) {
    //Declare expected variables
    string name;
    double res;
    int node1, node2;

    //Take in all variables
    sStream >> name >> res >> node1 >> node2;

    if (!nodes.checkRes(name)) {//Make sure the resistor name is novel

        //Add Node 1
        if (!nodes.checkID(node1))
            nodes.addNode(node1);

        //Add Node 2
        if (!nodes.checkID(node2))
            nodes.addNode(node2);

        nodes.addResistor(name, res, node1, node2);

        //If everything is fine then output the following
        cout << "Inserted: resistor " << name << " " << setprecision(2) << fixed << res << " Ohms " << node1
                << " -> " << node2 << endl;
    } else {
        cout << "Error: resistor " << name << " already exists" << endl;
    }
}

/*This function deals with modifyR command*/
void Rparser::modifyR(stringstream& sStream, NodeList& nodes) {
    //Declare expected variables
    string name;
    double res;

    sStream >> name >> res;

    //Check if there is such a resistor
    if (nodes.checkRes(name)) {
        nodes.modifyRes(name, res);
    } else {
        cout << "Error: resistor " << name << " not found" << endl;
    }
    //TODO: Change resistor resistance

    //TODO: Output for modifyR

}

/*This function deals with the printR command*/
void Rparser::printR(stringstream& sStream, NodeList& nodes) {
    //Declare expected variables
    string name;

    //Read in the name
    sStream >> name;

    if (nodes.checkRes(name)) {//Check if there is such a resistor
        nodes.printRes(name); //Print that resistor
    } else {
        cout << "Error: resistor " << name << " not found" << endl;
    }
}

/*This function deals with the printNode command*/
void Rparser::printNode(stringstream& sStream, NodeList& nodes) {
    //Declare expected variables
    string strCmd;
    int nodeNum;

    //Load string stream into string (assuming its "all")
    sStream >> strCmd;
    //Check if the input is 'all' or nodeid
    if (strCmd == "all") {
        //TODO: Nodes with no resistors shall not be printed
        nodes.printAllNodes();
    } else {
        //If the name is not "all" then load into a stringstream and then into an int
        stringstream converter(strCmd);
        //Read in node assuming its an integer
        converter >> nodeNum;

        //Check if th node exists
        if (nodes.checkID(nodeNum)) {
            cout << "Print:" << endl;
            nodes.printNode(nodeNum); //Print the node
        } else {
            cout << "Error: node " << nodeNum << " not found" << endl;
        }
    }
}

/*This function deals with the deleteR command*/
void Rparser::deleteR(stringstream& sStream, NodeList& nodes) {
    //Declare expected variables
    string name;

    //Read in the name
    sStream >> name;
    if (name == "all") {
        nodes.deleteAll();
        cout << "Deleted: all resistors" << endl;
    } else {
        nodes.deleteRes(name);
        cout << "Deleted: resistor " << name << endl;
    }
    return;
}