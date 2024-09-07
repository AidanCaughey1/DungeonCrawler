/*********************************************************************
** Program Filename: bats.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Bats class functions
** Input: A bat object is created
** Output: Bat object is created properly
*********************************************************************/

#include "bats.h"

/*********************************************************************
** Function: percept()
** Description: Called when you are adjacient to an object
** Parameters: none
** Pre-Conditions: Called when you are adjacient to an object
** Post-Conditions: Text printed to screen warning you
*********************************************************************/ 
void Bats::percept(){
    cout << "You hear wings flapping." <<endl;
}

/*********************************************************************
** Function: encounter()
** Description: Called when you are in the same room as an object
** Parameters: none
** Pre-Conditions: Called when you are in the same room as an object
** Post-Conditions: Text printed to screen telling you what has happened
*********************************************************************/ 
void Bats::encounter(){
    cout << "An angry super bat confuses you! You may have some trouble with your directions from now on..." << endl;
}