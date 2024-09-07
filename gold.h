/*********************************************************************
** Program Filename: bats.h
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Header file for the Bats class
** Input: A bat object is created
** Output: Bat class declaration is made
*********************************************************************/

#include "event.h"
#ifndef GOLD_H
#define GOLD_H

class Gold : public Event {

public:
    void percept();
    void encounter();
    
};
#endif