/*********************************************************************
** Program Filename: bats.h
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Header file for the Bats class
** Input: A bat object is created
** Output: Bat class declaration is made
*********************************************************************/

#include <iostream>
using namespace std;
#ifndef EVENT_H
#define EVENT_H

class Event{

public:
    //Don't have a copy constructor or an operator= because I never set one event object to another I only use the new command
    Event();
    virtual ~Event();
    virtual void percept() = 0;
    virtual void encounter() = 0;

};
#endif 