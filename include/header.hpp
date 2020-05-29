#pragma once

#include <string>
#include <sstream>
#include <ctype.h>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include "ChessGame.hpp"

using namespace std;

/*saves coordinates of start/end cells and 
their difference for futher move performing*/
typedef struct s_move_cells {
    int col_start;
    int col_dest;
    int row_start;
    int row_dest;
    int row_diff;
    int col_diff;
} t_move_cells;

//checks the user input
bool validate_move_format(ChessGame &game);
//checks if move specified my the user is correct
bool validate_movement(ChessGame &game);
//draws board to the terminal window
void Display(ChessGame game);
//reads player move from stdin
void get_player_move(ChessGame &game);
//convert a1 to coordinates on the 2d array board like [0][1]
void get_2darr_coord(ChessGame game,t_move_cells &move_cells);
//check if starting/destination cell is not valid (for example it's empty cell with no chessman)
bool check_start_end_points(ChessGame game, t_move_cells move_cells);
//if choosed chess is pawn-> checks wether the move is valid
bool check_pawn_rules(ChessGame &game, t_move_cells move_cells);
//depending on chessman checks wether move specified by the user is corrects
bool check_king_rules(ChessGame &game, t_move_cells move_cells);
bool check_queen_rules(ChessGame &game, t_move_cells move_cells);
bool check_knight_rules(ChessGame &game, t_move_cells move_cells);
bool check_bishop_rules(ChessGame &game, t_move_cells move_cells);
bool check_rock_rules(ChessGame &game, t_move_cells move_cells);
bool check_bishop_directions(ChessGame &game, t_move_cells move_cells);
bool check_rock_directions(ChessGame &game, t_move_cells move_cells);
void eat_chessman(ChessGame &game, t_move_cells move_cells, string congrats);
void make_move(ChessGame &game, t_move_cells move_cells);
void congrat_players();