/*********************************************************************
** Program Filename: main.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Starts the program
** Input: Program started
** Output: The "Cave" is loaded and able to be printed and the menu is called
*********************************************************************/

#include "game.h"
using namespace std;

int main(){

    srand(time(NULL));
    Game g;

    //Loading the vector
    g.load_data();

    //Debug mode input
    g.cin_debug();

    //Menu
    g.menu();
    return 0;
}