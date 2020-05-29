#include "ChessGame.hpp"

ChessGame::ChessGame() {
    current_player = 2;         //white make their move first
    p1_chessmans_least = 16;    //at the start of the game each
    p2_chessmans_least = 16;    //player has 16 chessmates
}

int ChessGame::get_current_player() {
    return current_player;
}

void ChessGame::change_current_player() {
    current_player == 1 ? current_player = 2 : current_player = 1;
}

void ChessGame::decr_chessmans_amount(int player) {
    if(player == 1)
        p1_chessmans_least--;
    else
        p2_chessmans_least--;
}

std::string ChessGame::get_move() {
    return move;
}

void ChessGame::set_move(std::string m) {
    move = m;
}

//placing the chessmans on the board
//argument in quotes - chassman's name, second argument - player identifier
void ChessGame::init_board() {
    //first row
	board[0][0].chessman = new Chessman("Rook",   1);
	board[0][1].chessman = new Chessman("Knight", 1);
	board[0][2].chessman = new Chessman("Bishop", 1);
	board[0][3].chessman = new Chessman("Queen",  1);
	board[0][4].chessman = new Chessman("King",   1);
	board[0][5].chessman = new Chessman("Bishop", 1);
	board[0][6].chessman = new Chessman("Knight", 1);
	board[0][7].chessman = new Chessman("Rook",   1);
    //second row (pawns)
	board[1][0].chessman = new Chessman("Pawn", 1);
	board[1][1].chessman = new Chessman("Pawn", 1);
	board[1][2].chessman = new Chessman("Pawn", 1);
	board[1][3].chessman = new Chessman("Pawn", 1);
	board[1][4].chessman = new Chessman("Pawn", 1);
	board[1][5].chessman = new Chessman("Pawn", 1);
	board[1][6].chessman = new Chessman("Pawn", 1);
	board[1][7].chessman = new Chessman("Pawn", 1);
	//player2's chessmans...
	board[7][0].chessman = new Chessman("Rook",   2);
	board[7][1].chessman = new Chessman("Knight", 2);
	board[7][2].chessman = new Chessman("Bishop", 2);
	board[7][3].chessman = new Chessman("Queen",  2);
	board[7][4].chessman = new Chessman("King",   2);
	board[7][5].chessman = new Chessman("Bishop", 2);
	board[7][6].chessman = new Chessman("Knight", 2);
	board[7][7].chessman = new Chessman("Rook",   2);
    //second row (pawns)
	board[6][0].chessman = new Chessman("Pawn", 2);
	board[6][1].chessman = new Chessman("Pawn", 2);
	board[6][2].chessman = new Chessman("Pawn", 2);
	board[6][3].chessman = new Chessman("Pawn", 2);
	board[6][4].chessman = new Chessman("Pawn", 2);
	board[6][5].chessman = new Chessman("Pawn", 2);
	board[6][6].chessman = new Chessman("Pawn", 2);
	board[6][7].chessman = new Chessman("Pawn", 2);
}

Square ChessGame::get_board_cell(int x, int y) {
    return board[x][y];
}

void ChessGame::del_board_cell(int x, int y) {
    board[x][y].chessman = nullptr;
}

void ChessGame::set_board_cell(int x, int y, Chessman *new_chessman) {
    board[x][y] = new_chessman;
}
