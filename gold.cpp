/*********************************************************************
** Program Filename: gold.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Gold class functions
** Input: A gold object is created
** Output: Gold object is created properly
*********************************************************************/

#include "gold.h"

/*********************************************************************
** Function: percept()
** Description: Called when you are adjacient to an object
** Parameters: none
** Pre-Conditions: Called when you are adjacient to an object
** Post-Conditions: Text printed to screen warning you
*********************************************************************/ 
void Gold::percept(){
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: Called when you are in the same room as an object
** Parameters: none
** Pre-Conditions: Called when you are in the same room as an object
** Post-Conditions: Text printed to screen telling you what has happened
*********************************************************************/ 
void Gold::encounter(){
    cout << "You found gold You pick it up." << endl;
}