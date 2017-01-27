/* 
 * File:   ResistorList.cpp
 * Author: mahmo211
 * 
 * Created on November 8, 2016, 4:19 PM
 */

#include "ResistorList.h"
#include "Resistor.h"

using namespace std;

ResistorList::ResistorList() {
    head = NULL;
}

ResistorList::~ResistorList() {
    Resistor* temp = head;
    while (head != NULL){
        temp = head;
        head = temp->getNext();
        delete temp;
    }
}

Resistor* ResistorList::getHead() const {
    return head;
}

void ResistorList::setHead(Resistor* _head) {
    head = _head;
}

/*This function adds a resistor to the resistor list*/
void ResistorList::addResistor(Resistor* res) {
    if (head == NULL) {
        head = res;
    } else {
        Resistor* currentRes = head;
        //Loop through all the resistors to get to the end
        while (currentRes->getNext() != NULL)
            currentRes = currentRes->getNext();
        currentRes->setNext(res); //Set the last resistor to point to the new resistor
    }
}

/*This function prints all the resistors in the list*/
void ResistorList::print() {
    Resistor* temp = head;
    if (head == NULL)//If its empty then just leave
        return;
    head->print(); //Print head for starters
    while (temp->getNext() != NULL) {//Keep going to the next element until the end
        temp = temp->getNext(); //Move forward one
        temp->print(); //Print
    }
}

/*This function checks if a resistor exists*/
bool ResistorList::checkRes(string name) {
    if (head == NULL)//Make sure there is something to search for
        return false;
    if (head->getName() == name)//Check the first element
        return true;
    Resistor* temp = head;
    while (temp->getNext() != NULL) {//Go through all the resistors in the resistor list
        temp = temp->getNext();
        if (temp->getName() == name)
            return true;
    }
    return false;
}

/*This function returns a pointer to the resistor needed*/
Resistor* ResistorList::getRes(string name) {
    if (head->getName() == name)//Check the first element
        return head;
    Resistor* temp = head;
    while (temp->getNext() != NULL) {//Loop through all the resistors we have
        temp = temp->getNext();
        if (temp->getName() == name)//Return as soon as we find the right resistor
            return temp;
    }
    //WARNING: THIS FUNCTION ASSUMES THAT THE RESISTER NAME EXISTS!!
    return NULL;
}

/*This function deletes a specific resistor from the list*/
void ResistorList::deleteRes(string name) {
    Resistor* temp = head;
    if (head->getName() == name) {//Check if its the first element
        head = head->getNext();
        delete temp;
    } else {
        Resistor* previous;
        while (temp->getNext() != NULL) {
            previous = temp;
            temp = temp->getNext();
            if (temp->getName() == name) {
                previous->setNext(temp->getNext());
                delete temp;
                return;
            }
        }
    }
}