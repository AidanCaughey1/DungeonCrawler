/*********************************************************************
** Program Filename: Wumpus.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Wumpus class functions
** Input: A Wumpus object is created
** Output: Wumpus object is created properly
*********************************************************************/

#include "wumpus.h"

/*********************************************************************
** Function: percept()
** Description: Called when you are adjacient to an object
** Parameters: none
** Pre-Conditions: Called when you are adjacient to an object
** Post-Conditions: Text printed to screen warning you
*********************************************************************/ 
void Wumpus::percept(){
    cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: Called when you are in the same room as an object
** Parameters: none
** Pre-Conditions: Called when you are in the same room as an object
** Post-Conditions: Text printed to screen telling you what has happened
*********************************************************************/ 
void Wumpus::encounter(){
    cout << "You have found the mighty Wumpus! The Wumpus is angered by your presence and eats you!" << endl;
}