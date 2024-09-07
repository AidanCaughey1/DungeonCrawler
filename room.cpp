/*********************************************************************
** Program Filename: room.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Room class functions
** Input: A room object is created
** Output: Room object is created properly
*********************************************************************/

#include "room.h"

/*********************************************************************
** Function: Room::Room()
** Description: Room constructor
** Parameters: none
** Pre-Conditions: Room object is created
** Post-Conditions: Room object is successfully loaded
*********************************************************************/
Room::Room(){
    event = NULL;
    check = 'r';
    counter = 0;
    player = 0;
    start = 0;
}

/*********************************************************************
** Function: Room::~Room()
** Description: Room Destructor
** Parameters: none
** Pre-Conditions: Room object is deleted
** Post-Conditions: Event object is deleted and pointed to null
*********************************************************************/
Room::~Room(){
    if (event!=NULL){
        delete event;
        event = NULL;
    }
}

/*********************************************************************
** Function: Room::Room(const Room& other)
** Description: Copy constructor
** Parameters: another Room object
** Pre-Conditions: Room object is created and initialized with another Room
** Post-Conditions: Room is successfully copied from another Room object
*********************************************************************/
Room::Room(const Room& other){
    this->event = other.event;
    this->check = other.check;
    this->counter = other.counter;
    this->player = other.player;
    this->start = other.start;
}

/*********************************************************************
** Function: &Room Room::operator=(const Room& other)
** Description: Assignment Overload
** Parameters: another Room object
** Pre-Conditions: Already initialized Room object copies another Room object's data
** Post-Conditions: Room is successfully copied from another Room object
*********************************************************************/
Room& Room::operator=(const Room& other){
    this->event = other.event;
    this->check = other.check;
    this->counter = other.counter;
    this->player = other.player;
    this->start = other.start;
    return *this;
}

/*********************************************************************
** Function: set_event
** Description: Mutator function for the Room object
** Parameters: Event object
** Pre-Conditions: The variable needs to be set outside of the class
** Post-Conditions: The variable's value is changed
*********************************************************************/
void Room::set_event(Event *e){
    this->event = e;
}

/*********************************************************************
** Function: get_event
** Description: Accessor function for the Room object
** Parameters: nothing
** Pre-Conditions: The variable needs to be obtianed from outside the class
** Post-Conditions: The variable is accessed
*********************************************************************/
Event* Room::get_event() const{
    return this->event;
}

/*********************************************************************
** Function: set_check
** Description: Mutator function for the Room object
** Parameters: const character
** Pre-Conditions: The variable needs to be set outside of the class
** Post-Conditions: The variable's value is changed
*********************************************************************/
void Room::set_check(const char c){
    this->check = c;
}

/*********************************************************************
** Function: get_check
** Description: Accessor function for the Room object
** Parameters: nothing
** Pre-Conditions: The variable needs to be obtianed from outside the class
** Post-Conditions: The variable is accessed
*********************************************************************/
char Room::get_check() const{
    return this->check;
}

/*********************************************************************
** Function: set_counter
** Description: Mutator function for the Room object
** Parameters: const integer
** Pre-Conditions: The variable needs to be set outside of the class
** Post-Conditions: The variable's value is changed
*********************************************************************/
void Room::set_counter(const int c){
    this->counter = c;
}

/*********************************************************************
** Function: get_counter
** Description: Accessor function for the Room object
** Parameters: nothing
** Pre-Conditions: The variable needs to be obtianed from outside the class
** Post-Conditions: The variable is accessed
*********************************************************************/
int Room::get_counter() const{
    return this->counter;
}

/*********************************************************************
** Function: set_player
** Description: Mutator function for the Room object
** Parameters: const boolean
** Pre-Conditions: The variable needs to be set outside of the class
** Post-Conditions: The variable's value is changed
*********************************************************************/
void Room::set_player(const bool b){
    this->player = b;
}

/*********************************************************************
** Function: get_player
** Description: Accessor function for the Room object
** Parameters: nothing
** Pre-Conditions: The variable needs to be obtianed from outside the class
** Post-Conditions: The variable is accessed
*********************************************************************/
bool Room::get_player() const{
    return this->player;
}

/*********************************************************************
** Function: set_start
** Description: Mutator function for the Room object
** Parameters: const boolean
** Pre-Conditions: The variable needs to be set outside of the class
** Post-Conditions: The variable's value is changed
*********************************************************************/
void Room::set_start(const bool b){
    this->start = b;
}

/*********************************************************************
** Function: set_start
** Description: Accessor function for the Room object
** Parameters: nothing
** Pre-Conditions: The variable needs to be obtianed from outside the class
** Post-Conditions: The variable is accessed
*********************************************************************/
bool Room::get_start() const{
    return this->start;
}

/*********************************************************************
** Function: print_char
** Description: Debug mode printing the symbol that represents the object
** Parameters: nothing
** Pre-Conditions: Room object needs to be printed in debug mode
** Post-Conditions: Room is printed onto the grid
*********************************************************************/
void Room::print_char(){
    cout << "| " << this->check << " ";
}

/*********************************************************************
** Function: load_char
** Description: Loading an object into one of the vector indexes
** Parameters: char, what type of object needs to be loaded in
** Pre-Conditions: Room object needs to be loaded
** Post-Conditions: Room is successfully loaded with its new object
*********************************************************************/
void Room::load_char(char temp){
    this->check = temp;
    this->counter++;
    //Finding what to load in
    switch(temp){
        case('g'):
        event = new Gold;
        break;
        case('b'):
        event = new Bats;
        break;
        case('p'):
        event = new Pit;
        break;
        case('w'):
        event = new Wumpus;
        break;
    }
}

/*********************************************************************
** Function: check_char
** Description: Used in the percept function to check if the room next to it is not empty
** Parameters: nothing
** Pre-Conditions: Percept function is called
** Post-Conditions: Either the adjacient room is empty or not
*********************************************************************/
void Room::check_char(){
    if (this->check!='r'){
        this->event->percept();
    }
}

/*********************************************************************
** Function: encounter_char
** Description: Used in the encounter function if the room the player is in isn't empty
** Parameters: nothing
** Pre-Conditions: Encounter function is called
** Post-Conditions: Prints the encounter message, then returns the char so it an continue with the function
*********************************************************************/
char Room::encounter_char(){
    this->event->encounter();
    return check;
}

/*********************************************************************
** Function: check_wumpus
** Description: Checking to see if the arrow hit the Wumpus
** Parameters: nothing
** Pre-Conditions: Called when the arrow flies into a room
** Post-Conditions: Either the Wumpus was in the room or it was empty
*********************************************************************/
bool Room::check_wumpus(){
    //Checking to see if the arrow hit the Wumpus
    if (check == 'w'){
        this->check = 'r';
        counter = 0;
        return true;
    }

    else{
        return false;
    }
}