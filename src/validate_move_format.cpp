#include "header.hpp"

static void del_extra_spaces(string &move) {
    string new_move;

    for(int i = 0; i < move.length(); i++)
        if(!isspace(move[i]))
            new_move.push_back(move[i]);
    move = new_move;
}


//this function makes sure that the user has entered a potentially correct move based on formatting alone
bool validate_move_format(ChessGame &game) {
    string move = game.get_move();
    
    //delete extra spaces if there are such in the string
    del_extra_spaces(move);
    //renew string, now it has no extra spaces
    game.set_move(move);

    //this basically just checkes each of the characters in the 3 sections of the move
    //format to ensure that the user has entered a valid range of inputs
    if (move[0] < 'a' || move[0] > 'h' ||   //
        move[1] < '0' || move[1] > '7') {   //
        cout << "Oh, first cell is incorrect.\n";
        return false;
    }
        
    //check if delimiter is here
    if(move[2] != '-' || move[3] != '>'){
        cout << "add a delimiter '->' besides two cells please!\n";
        return false;
    }

    //check destination cell
    if (move[4] < 'a' || move[4] > 'h' ||   //valid ranger of letters for destination index
        move[5] < '0' || move[5] > '7') {   //valid range of numbers for destination index
        cout << "Oh, destination cell is incorrect.\n";
        return false;
    }

    return true;
}
