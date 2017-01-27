/* 
 * File:   ResistorList.h
 * Author: mahmo211
 *
 * Created on November 8, 2016, 4:19 PM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H

#include "Resistor.h"
#include <string>

using namespace std;

class ResistorList {
private:
    Resistor *head;//Head of the resistor
public:
    ResistorList();
    ~ResistorList();
    Resistor* getHead() const;
    void setHead(Resistor* _head);
    void addResistor(Resistor* res);
    void print();
    bool checkRes(string name);
    Resistor* getRes(string name);
    void deleteRes(string name);
};

#endif	/* RESISTORLIST_H */

