/* 
 * File:   Resistor.cpp
 * Author: mahmo211
 * 
 * Created on October 12, 2016, 9:52 PM
 */

#include "Resistor.h"
#include <iostream>
#include <iomanip>

using namespace std;

Resistor::Resistor(string name_,double resistance_,int endpoints_[2]) {
   resistance = resistance_; // resistance (in Ohms)
   name = name_; // C++ string holding the label
   endpointNodeIDs[0] = endpoints_[0]; // IDs of nodes it attaches to
   endpointNodeIDs[1] = endpoints_[1];
   next = NULL;//Initialize pointer to point to null
}

Resistor::Resistor(string name_,double resistance_,int endpoints_[2], Resistor* _next) {
   resistance = resistance_; // resistance (in Ohms)
   name = name_; // C++ string holding the label
   endpointNodeIDs[0] = endpoints_[0]; // IDs of nodes it attaches to
   endpointNodeIDs[1] = endpoints_[1];
   next = _next;//Pointer to next resistor in resistor array
}

void Resistor::print () {
    cout << setw(20) << left << name;//Set the width of the name field and print name and pad with a space
    cout << setw(8) << setprecision(2) << fixed << right << resistance;//Set width of resistance field and precision
    cout << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;

}

string Resistor::getName() const{
    return name;
}

double Resistor::getResistance() const{ // returns the resistance
    return resistance;
}

void Resistor::setResistance (double resistance_){//Updates the resistance
    resistance = resistance_;
}

Resistor* Resistor::getNext(){//Returns pointer to next resistor in the list
    return next;
}

void Resistor::setNext(Resistor* _next){// set the pointer to the next resistor
    next = _next;
}

Resistor::~Resistor() {
}