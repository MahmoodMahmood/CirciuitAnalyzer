/* 
 * File:   Main.cpp
 * Author: Mahmood Mahmood
 *
 * Created on November 9, 2016, 9:46 PM
 */

#include <cstdlib>
#include <sstream>
#include "Rparser.h"
#include "NodeList.h"

using namespace std;

int main(int argc, char** argv) {
    Rparser client = Rparser();
    NodeList nodes = NodeList();//Make list of all the nodes
    string line, command;
    // May have some setup code here
    cout << "> ";
    getline(cin, line); // Get a line from standard input
    while (!cin.eof()) {
        // Put the line in a stringstream for parsing
        // Making a new stringstream for each line so flags etc. are in a known state
        stringstream sStream(line);
        sStream >> command;
        if (command == "insertR") {
            client.insertR(sStream, nodes);
        } else if (command == "modifyR") {
            client.modifyR(sStream, nodes);
        } else if (command == "printR") {
            client.printR(sStream, nodes);
        } else if (command == "printNode") {
            client.printNode(sStream, nodes);
        } else if (command == "deleteR") {
            client.deleteR(sStream, nodes);
        } else {
            cout << "Error: invalid command" << endl;
        }
        line = "";
        command = "";
        cout << "> ";
        getline(cin, line);
    } // End input loop until EOF.

    return 0;
}