/*********************************************************************
** Program Filename: pit.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Pit class functions
** Input: A pit object is created
** Output: Pit object is created properly
*********************************************************************/

#include "pit.h"

/*********************************************************************
** Function: percept()
** Description: Called when you are adjacient to an object
** Parameters: none
** Pre-Conditions: Called when you are adjacient to an object
** Post-Conditions: Text printed to screen warning you
*********************************************************************/ 
void Pit::percept(){
    cout << "You feel a breeze." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: Called when you are in the same room as an object
** Parameters: none
** Pre-Conditions: Called when you are in the same room as an object
** Post-Conditions: Text printed to screen telling you what has happened
*********************************************************************/ 
void Pit::encounter(){
    cout << "You fall into the bottomless pit!" << endl;
}