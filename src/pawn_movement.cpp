#include "header.hpp"

//if choosed chess is pawn-> check wether the move is valid
bool check_pawn_rules(ChessGame &game, t_move_cells move_cells) {
    //PLAYER 1
    if(game.get_current_player() == 1) {
		//on the first move pawns can go forward on two cells, on next moves - only on one cell
		//paws should always go forward, not backwards etc. 
		if ((move_cells.row_start != 1 && move_cells.row_diff <= -2) ||
            move_cells.row_diff >= 0 || abs(move_cells.col_diff) > 1 ) { 
			cout << "Unfortunately, Pawns can't move like that\n";
			return false;
		}
		//if player tries to move far avay
		else if(move_cells.row_start == 1 && move_cells.row_diff < -2) {
			cout << "Pawns can move 2 cells on their first move \n";
			return false;
		}
		//if they try to move diagonally without there being an enemy chessman there
		else if (abs(move_cells.col_diff) == 1 && move_cells.row_diff == -1 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman == nullptr) {
			cout << "There are no enemies on the specified cell\n";
			return false;
		}
		//if they try to move 1 space forward but there's an enemy there
		else if (move_cells.row_diff == -1 && move_cells.col_diff == 0 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player == 2) {
			cout << "There is an enemy chessman on the way.\n";
			return false;
		}
		//if they try to move diagonally to a space and there's an enemy chessman there...
		else if (move_cells.row_diff == -1 && abs(move_cells.col_diff) == 1 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player == 2) {
            eat_chessman(game, move_cells, "Good move!");
			return true;
		}
		//simple forward move with no enemy or player's chessmans there
		else {
			make_move(game, move_cells);
			return true;
		}
	}

	//PLAYER 2
	else if(game.get_current_player() == 2){
		//this is to take into account that pawns can move 2 spaces on their first move, but not after
		if ((move_cells.row_start != 6 && move_cells.row_diff >= 2) ||
            move_cells.row_diff <= 0 || abs(move_cells.col_diff) > 1) {
			cout << "Unfortunately, Pawns can't move like that\n";
			return false;
		}
		//if player tries to move far away
		else if(move_cells.row_start == 6 && move_cells.row_diff > 2){
            cout << "Pawns can move 2 cells on their first move \n";
			return false;
		}
		//if they try to move diagonally without there being an enemy chessman there
		else if (abs(move_cells.col_diff) == 1 && move_cells.row_diff == 1 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman == nullptr) {
			cout << "There are no enemies on the specified cell\n";
			return false;
		}
		//if they try to move 1 space forward but there's an enemy there...
		else if (move_cells.row_diff == 1 && move_cells.col_diff == 0 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player == 1) {
			cout << "There is an enemy chessman on the way.\n";
			return false;
		}
		//if they try to move diagonally to a space and there's an enemy chessman there...
		else if (move_cells.row_diff == 1 && abs(move_cells.col_diff) == 1 
                && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player == 1) {
            eat_chessman(game, move_cells, "Good move!");
			return true;
		}
		//simple forward move
		else {
			make_move(game, move_cells);
			return true;
		}
    }
}

