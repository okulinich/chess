#include "header.hpp"

//convert a1 to coordinates on the 2d array board like [0][1]
void get_2darr_coord(ChessGame game, t_move_cells &move_cells) {
    char tmp[2] = {0};

    tmp[0] = game.get_move()[0] - 49;  //there are 49 characters in ascii table between letter and numbers,
	move_cells.col_start = atoi(tmp);  //so we get desired number from a letter as following: a->0, b->1...
	tmp[0] = game.get_move()[4] - 49;
    move_cells.col_dest = atoi(tmp);
	move_cells.row_start = game.get_move()[1] - '0';
	move_cells.row_dest = game.get_move()[5] - '0';
	move_cells.row_diff = move_cells.row_start - move_cells.row_dest;
	move_cells.col_diff = move_cells.col_start - move_cells.col_dest;
}

//check if starting/destination cell is not valid (for example it's empty cell with no chessman)
bool check_start_end_points(ChessGame game, t_move_cells move_cells) {
    //check if starting cell has any chessmans
	if(game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman == nullptr){
		cout << "There's no chessman at the starting point\n";
		return false;
	}

	//checks if player tries to move his/here chessmans
	if (game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman != nullptr 
        && game.get_current_player() != game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman->player) {
		cout << "Nice try, that was chessman of your opponent\n";
		return false;
	}

	//checks if the player already has a chessman at the desired cell
	if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_current_player() == game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player) {
		cout << "Nope, you already have a chessman there\n";
		return false;
	}

    return true;
}

void eat_chessman(ChessGame &game, t_move_cells move_cells, string congrats) {
    //print congratulations!
    cout << congrats << ". Enemy's ";
    cout << game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->name;
    cout << " is yours!\n\n";
    //move is ok. make it be displayed on the board
    game.set_board_cell(move_cells.row_dest, move_cells.col_dest, game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman);
    game.del_board_cell(move_cells.row_start, move_cells.col_start);
    //let player celebrate
    sleep(1);
}

void make_move(ChessGame &game, t_move_cells move_cells) {
    cout << "Ok, go on!\n";
    //move is ok. make it be displayed on the board
    game.set_board_cell(move_cells.row_dest, move_cells.col_dest, game.get_board_cell(move_cells.row_start, move_cells.col_start).chessman);
    game.del_board_cell(move_cells.row_start, move_cells.col_start);
    //let player cool down a dit
    sleep(1);
}

void get_player_move(ChessGame &game) {
    string buf;

    getline(cin, buf);
    //a valid move has at least 6 characters
    while(buf.length() < 6)
        getline(cin, buf);
    game.set_move(buf);
}

void congrat_players() {
    cout << "Hello, great warriors! Prepare your minds!\n\t\tCHESS\n";
    sleep(2);
    cout << "And let the odds be even in your favour!\n";
    sleep(2);
    cout << "Movement format: a1->b1\n";
    sleep(2);
    cout << "Good luck! And may the force be with you!\n";
    sleep(3);
    cout << endl;
}
