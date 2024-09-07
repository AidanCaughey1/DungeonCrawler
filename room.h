/*********************************************************************
** Program Filename: room.h
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Header file for the Room class
** Input: A room object is called
** Output: Room class declaration is made
*********************************************************************/
#include "event.h"
#include "gold.h"
#include "bats.h"
#include "wumpus.h"
#include "pit.h"
#ifndef ROOM_H
#define ROOM_H
class Room{
    
public:
    Room();
    ~Room();
    Room(const Room&);
    Room& operator=(const Room&);

    //Functions
    void check_char();
    char encounter_char();
    void load_char(char);
    void print_char();
    bool check_wumpus();

    //Accessors and Mutators
    void set_event(Event *);
    Event* get_event() const;
    void set_check(const char);
    char get_check() const;
    void set_counter(const int);
    int get_counter() const;
    void set_player(const bool);
    bool get_player() const;
    void set_start(const bool);
    bool get_start() const;

private:
    Event* event;
    char check;
    int counter;
    int player;
    bool start;
};

#endif
