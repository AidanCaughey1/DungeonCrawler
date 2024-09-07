/*********************************************************************
** Program Filename: bats.h
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Header file for the Bats class
** Input: A bat object is created
** Output: Bat class declaration is made
*********************************************************************/

#include "room.h"
#include <vector>
#include <cstdlib>
#ifndef GAME_H
#define GAME_H

class Game{

public:
    Game();
    //No accessors/mutators needed most of program functions in game functions
    //Functions
    void dungeon();
    void cin_debug();
    void load_data();
    void load_event(char temp);
    void load_player();
    void print_grid();
    void print_grid_debug();
    void menu();
    void move();
    void move_reverse(char);
    void update(char);
    void check();
    void shoot_direction(char);
    void percept();
    void encounter();
    void gold_encounter();
    void wumpus_kill();
    void wumpus_move();
    void event(char);
    void you_lose();
    void you_win();
    void check_win();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void shoot_up();
    void shoot_down();
    void shoot_left();
    void shoot_right();
    
private:
    //2D grid
    vector <vector <Room> > grid;
    int row;
    int col;
    int arrows;
    int win_condition;
    bool lose_condition;
    int confusion;
    string debug;
    bool slain;
};
#endif