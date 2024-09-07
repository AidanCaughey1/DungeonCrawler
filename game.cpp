/*********************************************************************
** Program Filename: bats.cpp
** Author: Aidan Caughey
** Date: 05/24/23
** Description: Contains Bats class functions
** Input: A bat object is created
** Output: Bat object is created properly
*********************************************************************/

#include "game.h"

/*********************************************************************
** Function: Game::Game()
** Description: Constructor
** Parameters: nothing
** Pre-Conditions: Game object is called
** Post-Conditions: Game object is successfully filled
*********************************************************************/
Game::Game(){
   this->row = 0;
   this->col = 0;
   this->arrows = 3;
   this->win_condition = 0;
   this->lose_condition = 0;
   this->confusion = 0;
   this->debug = "";
   this->slain = 0;
}

/*********************************************************************
** Function: dungeon
** Description: Getting the width and height inputs for the grid
** Parameters: nothing
** Pre-Conditions: Called when initializing the dungeon
** Post-Conditions: Row and column variables are now filled
*********************************************************************/
void Game::dungeon(){
    while(row<4||row>20){
        cout << "Enter the height of the cave: ";
        cin >> row;
        if(row<4||row>20){
            cout << "Sorry that is not a valid input" << endl;
            cin.clear();
            cin.ignore(INT8_MAX,'\n');
        }
    }
    while(col<4||col>20){
        cout << "Enter the width of the cave: ";
        cin >> col;
        if(col<4||col>20){
            cout << "Sorry that is not a valid input" << endl;
            cin.clear();
            cin.ignore(INT8_MAX,'\n');
        }
    }
}

/*********************************************************************
** Function: cin_debug
** Description: Entering if you want to launch the game in debug mode or not
** Parameters: nothing
** Pre-Conditions: Called when deciding if the game should be run in debug mode
** Post-Conditions: Debug variable is filled, letting it run in debug mode or not
*********************************************************************/
void Game::cin_debug(){
    while(debug!="true"&& debug!="false"){
        cout << "Would you like to run the game in debug mode? Type true or false:";
        cin >> debug;
        if(debug!="true"&& debug!="false"){
            cout << "Sorry that is not a valid input" << endl;
            cin.clear();
            cin.ignore(INT8_MAX,'\n');
        }
    }
}

/*********************************************************************
** Function: load_data
** Description: Loading the 2D vector and then loading it with the objects
** Parameters: nothing
** Pre-Conditions: Called when initializing the dungeon
** Post-Conditions: Vector has been filled
*********************************************************************/
void Game::load_data(){
    //User inputs height and width
    dungeon();
    for (int i = 0; i < row; i++){
        vector<Room> row_vec;
    for (int j = 0; j < col; j++){
        Room r;
            row_vec.push_back(r);   
        } 
        grid.push_back(row_vec);
    }
    //Load with random events
    load_event('g');
    load_event('w');
    load_event('p');
    load_event('p');
    load_event('b');
    load_event('b');
    load_player();
}

/*********************************************************************
** Function: load_player
** Description: Loading the player starting position
** Parameters: nothing
** Pre-Conditions: Called after the dungeon has been filled
** Post-Conditions: Player has been dropped into the grid
*********************************************************************/
void Game::load_player(){
    bool get = 0;
    //Make it pick a random size
    while (get==0){
        //Setting the starting position and the player position
        int randrow = (rand()%this->row);
        int randcol = (rand()%this->col);
        if (grid[randrow][randcol].get_counter()==0){
            grid[randrow][randcol].set_player(1);
            grid[randrow][randcol].set_start(1);
            grid[randrow][randcol].set_counter(1);
            get=1;
        }
    }
}

/*********************************************************************
** Function: load_event
** Description: Loading the different objects into the grid
** Parameters: char, the object identifier
** Pre-Conditions: Called after the 2D vector has been initialized
** Post-Conditions: Vector has been filled with an object
*********************************************************************/
void Game::load_event(char temp){
    bool get = 0;
    //Make it pick a random size
    while (get==0){
        int randrow = (rand()%this->row);
        int randcol = (rand()%this->col);
        if (grid[randrow][randcol].get_counter()==0){
            grid[randrow][randcol].load_char(temp);
            get=1;
        }
    }
}

/*********************************************************************
** Function: print_grid
** Description: Printing the grid, not debug mode
** Parameters: nothing
** Pre-Conditions: Called when grid needs to be printed, not in debug mode
** Post-Conditions: Grid has successfully been printed
*********************************************************************/
void Game::print_grid(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 0; j < col; j++){
            if (grid[h][j].get_player()==1){
                cout << "| * ";
            }
            else{
                cout << "|   ";
            }
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < col; i++){
            cout << "+---";
    }
    cout << "+" << endl;
}

/*********************************************************************
** Function: print_grid_debug
** Description: Printing the grid in debug mode
** Parameters: nothing
** Pre-Conditions: Called when the grid needs to be printed
** Post-Conditions: Grid has been printed
*********************************************************************/
void Game::print_grid_debug(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 0; j < col; j++){
            if (grid[h][j].get_player()==1){
                cout << "| * ";
            }
            else if (grid[h][j].get_counter()==1){
                grid[h][j].print_char();
            }
            else{
                cout << "|   ";
            }
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < col; i++){
            cout << "+---";
    }
    cout << "+" << endl;
}

/*********************************************************************
** Function: menu
** Description: Order of operations for the game
** Parameters: nothing
** Pre-Conditions: prompted to move
** Post-Conditions: Menu has checked your surroundings and your room, and also prompts you to move
*********************************************************************/
void Game::menu(){
    do{
        check();
        if (lose_condition==0 && win_condition < 3){
            move();
        }
    }while(lose_condition==0 && win_condition < 3);
}

/*********************************************************************
** Function: move
** Description: Moving prompts
** Parameters: nothing
** Pre-Conditions: Called after the Menu checks your surroundings
** Post-Conditions: Move input was made
*********************************************************************/
void Game::move(){
    char move ='n';
        while (move!='w'&& move!='s'&& move!='a'&& move!='d' && move!='f'){
            cout << "What would you like to do? w-up, s-down, a-left, d-right, f-fire an arrow: ";
            cin >> move;
            if (move!='w'&& move!='s'&& move!='a'&& move!='d' && move!='f'){
                cout << "Sorry that is not a valid input, please try again" << endl;
                cin.clear();
                cin.ignore(INT8_MAX,'\n');
            }
        }
    //Checking if confusion has been applied
    if(confusion>0){
        move_reverse(move);
    }
    //Actually moving the player
    else{
    update(move);
    }
}

/*********************************************************************
** Function: move_reverse
** Description: Swapping the move input
** Parameters: char
** Pre-Conditions: Called if the player is confused
** Post-Conditions: Move input has been swapped
*********************************************************************/
void Game::move_reverse(char move){
    confusion--;
    if (confusion==0){
        cout << "You finally returned to your senses" << endl;
    }
    //Reversing move
    if(move=='w'){
        move='s';
    }
    else if(move=='s'){
        move='w';
    }
    else if (move=='a'){
        move='d';
    }
    else{
        move='a';
    }
    //Update
    update(move);
}

/*********************************************************************
** Function: check
** Description: Percepting, encountering and checking win and loss conditions
** Parameters: nothing
** Pre-Conditions: Called after the Menu has been called
** Post-Conditions: Has checked adjacient rooms, the current room and win and loss conditions
*********************************************************************/
void Game::check(){
    //Printing Map
    if (debug == "true"){
        print_grid_debug();
        }
    else{
        print_grid();
    }

    //Checking around the player
    percept();

    //Checking if the player has encountered something
    encounter();

    //Checking if any win or loss conditions were met
    if(arrows==0&&slain==0){
        cout << "You've run out of arrows! " << endl;
        lose_condition=1;
    }

    if(lose_condition==1){
        cout << "You lose!" << endl;
        cout << "Better luck next time!" << endl;
        }
    check_win();
}

/*********************************************************************
** Function: check_win
** Description: Checking to see if win conditions have been met
** Parameters: nothing
** Pre-Conditions: Called in the Check function
** Post-Conditions: Win conditions may or may not have been met
*********************************************************************/
void Game::check_win(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if(win_condition==2 && grid[h][i].get_start()==1){
                    cout << "You found the escape rope and you win!" << endl;
                    cout << "Hooray!" << endl;
                    win_condition++;
                }
            }
        }
    }
}

/*********************************************************************
** Function: percept
** Description: Checkign adjacient rooms
** Parameters: nothing
** Pre-Conditions: Called after the Check function is called
** Post-Conditions: Prints percept messages to screen if necessary
*********************************************************************/
void Game::percept(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (h!=0){
                    grid[h-1][i].check_char();
                }
                if (h!=row-1){
                    grid[h+1][i].check_char();
                }
                if(i!=0){
                    grid[h][i-1].check_char();
                }
                if(i!=col-1){
                    grid[h][i+1].check_char();
                }
            }
        }
    }
}

/*********************************************************************
** Function: encounter
** Description: Checking the room the player is in
** Parameters: nothing
** Pre-Conditions: Called after the Percept function
** Post-Conditions: Player encountered or did not encounter
*********************************************************************/
void Game::encounter(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (grid[h][i].get_check()!='r'){
                    char encounter = grid[h][i].encounter_char();
                    event(encounter);
                }
            }
        }
    }
}

/*********************************************************************
** Function: event
** Description: If player encountered 
** Parameters: char
** Pre-Conditions: Called after the player has encountered an obstacle
** Post-Conditions: win and loss conditions are updated
*********************************************************************/
void Game::event(char encounter){

    switch(encounter){
        case('b'):
            this->confusion=5;
            break;
        case('p'):
            this->lose_condition=1;
            break;
        case('w'):
            this->lose_condition=1;
            break;
        case('g'):
            gold_encounter();
            break;
    }
}

/*********************************************************************
** Function: gold_encounter
** Description: You picked up gold
** Parameters: nothing
** Pre-Conditions: Called after you walk in the same room as gold
** Post-Conditions: Gold object has been "picked up"
*********************************************************************/
void Game::gold_encounter(){
    win_condition++;
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if(grid[h][i].get_check()=='g'){
                grid[h][i].set_check('r');
                grid[h][i].set_counter(0);
            }
        }
    }
}

/*********************************************************************
** Function: wumpus_kill
** Description: Wumpus was slain with an arrow
** Parameters: nothing
** Pre-Conditions: Called after the wumpus was killed
** Post-Conditions: Win conditions are updated
*********************************************************************/
void Game::wumpus_kill(){
    cout << "The arrow hit the Wumpus it is slain!" << endl;
    slain = 1;
    win_condition++;
}

/*********************************************************************
** Function: wumpus_move
** Description: If arrow misses, Wumpus move algorithm
** Parameters: nothing
** Pre-Conditions: Called after the player misses all their shots
** Post-Conditions: Wumpus has moved
*********************************************************************/
void Game::wumpus_move(){
    bool get = 0;
    int temprow;
    int tempcol;
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if(grid[h][i].get_check()=='w'){
                //Storing location so it moves to a new one 
                temprow = h;
                tempcol = i;
                grid[h][i].set_check('r');
                grid[h][i].set_counter(0);
                break;
            }
        }
    }
      //Finding new space
     while (get==0){
        int randrow = (rand()%this->row);
        int randcol = (rand()%this->col);
        if (grid[randrow][randcol].get_check()=='r'&&(randrow!=temprow&&randcol!=tempcol)){
            get = 1;
            grid[randrow][randcol].load_char('w');
        }
    } 
}

/*********************************************************************
** Function: update
** Description: Called when the player has chosen to move or shoot an arrow
** Parameters: char, the option they chose
** Pre-Conditions: Called after the Move function
** Post-Conditions: MOve input or arrow shot was made
*********************************************************************/
//This function is longer than 15 lines because it contians a switch statement and lots of nested if loops. 
void Game::update(char action){
//Player Action
    if (action == 'f'){
        if (arrows>0){
            char direction;
            cout << "What direction would you like to fire the arrow? ";
            cin >> direction;
            shoot_direction(direction);
        }
        else{
            cout << "You are out of arrows!" << endl;
        }
    }
    else{
        //Finding the player index
        switch (action){
            case('a'):
                move_left();
                break;
            case('d'):
                move_right();
                break;
            case('s'):
                move_down();
                break;
            case('w'):
                move_up();
                break;
        }
    }
}

/*********************************************************************
** Function: shoot_direction
** Description: The direction the arrow is shot
** Parameters: char direction
** Pre-Conditions: Called after the player chooses the direction of the arrow
** Post-Conditions: Arrow is shot in the direction the player chose
*********************************************************************/
void Game::shoot_direction(char direction){
    arrows--;
    switch (direction){
        case('a'):
            shoot_left();
            break;
        case('d'):
            shoot_right();
            break;
        case('s'):
            shoot_down();
            break;
        case('w'):
            shoot_up();
            break;
    }
}

/*********************************************************************
** Function: shoot_up
** Description: Arrow is shot up
** Parameters: none
** Pre-Conditions: Called after the player chooses the shoot the arrow upwards
** Post-Conditions: Arrow is shot up
*********************************************************************/
void Game::shoot_up(){
    //This function is longer than 15 lines because it uses many nested for loops
    bool kill = false;
    //Finding the player position
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (h==0){
                    break;
                }
                //Shooting arrow 
                for (int j = 0; j < 4; j++){
                    if(h-j<0){
                        break;
                    }
                    //Seeing if the arrow hit the Wumpus
                    else{
                        kill = grid[h-j][i].check_wumpus();
                        if (kill == true){
                            wumpus_kill();
                            break;
                        }
                    }
                }
            }
        }
    }
    if (kill==false){
        if (bool TrueFalse = (rand() % 100) < 75){
            wumpus_move();
        }
    }
}

/*********************************************************************
** Function: shoot_down
** Description: Arrow is shot down
** Parameters: none
** Pre-Conditions: Called after the player chooses the shoot the arrow downwards
** Post-Conditions: Arrow is shot down
*********************************************************************/
void Game::shoot_down(){
    //This function is longer than 15 lines because it uses many nested for loops
    bool kill = false;
    //Finding the player position
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (h==row-1){
                    break;
                }
                //Shooting arrow 
                for (int j = 0; j < 4; j++){
                    if(h+j>row-1){
                        break;
                    }
                    else{
                        kill = grid[h+j][i].check_wumpus();
                        if (kill == true){
                            wumpus_kill();
                            break;
                        }
                    }
                }
            }
        }
    }
    if (kill==false){
        if (bool TrueFalse = (rand() % 100) < 75){
            wumpus_move();
        }
    }
}

/*********************************************************************
** Function: shoot_left
** Description: Arrow is shot left
** Parameters: none
** Pre-Conditions: Called after the player chooses the shoot the arrow left
** Post-Conditions: Arrow is shot left
*********************************************************************/
void Game::shoot_left(){
    //This function is longer than 15 lines because it uses many nested for loops
    bool kill = false;
    //Finding the player position
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (i==0){
                    break;
                }
                //Shooting arrow 
                for (int j = 0; j < 4; j++){
                    if(i-j<0){
                        break;
                    }
                    else{
                        kill = grid[h][i-j].check_wumpus();
                        if (kill == true){
                            wumpus_kill();
                            break;
                        }
                    }
                }
            }
        }
    }
    if (kill==false){
        if (bool TrueFalse = (rand() % 100) < 75){
            wumpus_move();
        }
    }
}

/*********************************************************************
** Function: shoot_right
** Description: Arrow is shot right
** Parameters: none
** Pre-Conditions: Called after the player chooses the shoot the arrow right
** Post-Conditions: Arrow is shot right
*********************************************************************/
void Game::shoot_right(){
    //This function is longer than 15 lines because it uses many nested for loops
    bool kill = false;
    //Finding the player position
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if (i==row-1){
                    break;
                }
                //Shooting arrow 
                for (int j = 0; j < 4; j++){
                    if(i+j>row-1){
                        break;
                    }
                    else{
                        kill = grid[h][i+j].check_wumpus();
                        if (kill == true){
                            wumpus_kill();
                            break;
                        }
                    }
                }
            }
        }
    }
    if (kill==false){
        if (bool TrueFalse = (rand() % 100) < 75){
            wumpus_move();
        }
    }
}

/*********************************************************************
** Function: move_up
** Description: Player moves up
** Parameters: none
** Pre-Conditions: Called after the player chooses to move upwards
** Post-Conditions: Player moves up
*********************************************************************/
void Game::move_up(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                //Checking if wall
                if(h==0){
                    cout << "Sorry there is a wall there" << endl;
                    break;
                }
            grid[h][i].set_player(0);
            grid[h-1][i].set_player(1);
            }
        }
    }
}

/*********************************************************************
** Function: move_down
** Description: Player moves down
** Parameters: none
** Pre-Conditions: Called after the player chooses to move downwards
** Post-Conditions: Player moves down
*********************************************************************/
void Game::move_down(){
    bool temp = 0;
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                if(h==row-1){
                    //Checking if wall
                    cout << "Sorry there is a wall there" << endl;
                    break;
                }
                grid[h][i].set_player(0);
                grid[h+1][i].set_player(1);
                temp=1;
            }
        }
        if (temp==1){
            break;
        }
    }
}

/*********************************************************************
** Function: move_left
** Description: Player moves left
** Parameters: none
** Pre-Conditions: Called after the player chooses to move left
** Post-Conditions: Player moves left
*********************************************************************/
void Game::move_left(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                //Checking if wall
                if(i==0){
                cout << "Sorry there is a wall there" << endl;
                break;
                }
            grid[h][i].set_player(0);
            grid[h][i-1].set_player(1);
            }
        }
    }
}

/*********************************************************************
** Function: move_right
** Description: Player moves right
** Parameters: none
** Pre-Conditions: Called after the player chooses to move right
** Post-Conditions: Player moves right
*********************************************************************/
void Game::move_right(){
    for (int h = 0; h < row; h++){
        for (int i = 0; i < col; i++){
            if (grid[h][i].get_player()==1){
                //Checking if wall
                if(i==col-1){
                    cout << "Sorry there is a wall there" << endl;
                    break;
                }
                grid[h][i].set_player(0);
                grid[h][i+1].set_player(1);
                break;
            }
        }
    }
}