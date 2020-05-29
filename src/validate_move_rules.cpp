#include "header.hpp"

//this function performs all chess rules validation of the previously correctly-formatted move
bool validate_movement(ChessGame &game) {
	//first of all we need to convert user input like a1->a2 to real coordinates of this pints on the board-array
    t_move_cells move_cells;
    //converts chess-board coordinates to indexes of cells in 2d array
	get_2darr_coord(game, move_cells);

    ////check if starting/destination cell is not valid (for example it's empty cell with no chessman)
    if(!check_start_end_points(game, move_cells))
        return false;

    //depending on choosed chess checks wether the move is correct
	if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("Pawn") == 0)
        return check_pawn_rules(game, move_cells);
	
    else if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("King") == 0){
        return check_king_rules(game, move_cells);
	}

	else if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("Queen") == 0){
        return check_queen_rules(game, move_cells);
	}

	else if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("Knight") == 0){
        return check_knight_rules(game, move_cells);
	}

	else if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("Bishop") == 0){
        return check_bishop_rules(game, move_cells);
	}

	else if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->name.compare("Rook") == 0){
        return check_rock_rules(game, move_cells);
	}

	else return false;	

}

