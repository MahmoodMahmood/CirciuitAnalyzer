/* 
 * File:   Rparser.h
 * Author: mahmo211
 *
 * Created on October 12, 2016, 9:53 PM
 */

#ifndef RPARSER_H
#define RPARSER_H
#include <iostream>
#include <sstream>
#include "NodeList.h"

class Rparser {
private:
    void invalid();
    void manyArgs();
    void fewArgs();
    bool checkLength(std::stringstream&, int);
    int searchRName(string name);
    
public:
    Rparser();
    virtual ~Rparser();
    void insertR(std::stringstream&, NodeList&);
    void modifyR(std::stringstream&, NodeList&);
    void printR(std::stringstream&, NodeList&);
    void deleteR(std::stringstream&,NodeList&);
    void printNode(std::stringstream&,NodeList&);
};

#endif /* RPARSER_H */

