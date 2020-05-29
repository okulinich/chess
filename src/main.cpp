#include "header.hpp"

int main() {
	ChessGame game;         //declare an object main class
	Square board[8][8];	    //declare the chess board (an array of Squares)

    game.init_board();      //place all chessmen on thr board
    congrat_players();      //print info-message

	while(true) {           //main game loop	
        game.change_current_player();       //after every move -> change the player
		
        system("clear");                    //clear terminal window
		
        Display(game);                      //print board to the terminal
		
        cout << "Player " << game.get_current_player();     //request to a user to print next move
        cout << ":\n> please enter your move: ";
		get_player_move(game);

		while(validate_move_format(game) == false) {        //parse player input and read move one 
			cout << "Ooops, that was invalid move...\n";    //more time if previous was invalid
            cout << "Player " << game.get_current_player();
            cout << ":\n> please enter your move: ";
			get_player_move(game);
        }

		while(validate_movement(game) == false) {
			cout << "Player " << game.get_current_player(); //check if move was correct, there
            cout << ":\n> please re-enter your move: ";     //were no other chessmates on the way etc.
			get_player_move(game);
		}
	}
    return 0;
}

