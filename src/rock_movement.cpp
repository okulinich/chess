#include "header.hpp"

bool check_rock_rules(ChessGame &game, t_move_cells move_cells) {
//the rock can move only in four basic directions, so one of
//the defferences must be zero, otherwise - incorrect move
    if (move_cells.row_diff != 0 && move_cells.col_diff != 0) {
        cout << "Oh, remember, rock can move forwards, backwards, ";
        cout << "right or left, no other directions!\n";
        return false;
    }
    //if there are other chessmans on the rocks way
    if(!check_rock_directions(game, move_cells))
        return false;
    //the rock it's enemy's chassman
    if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player != game.get_current_player()) {
        eat_chessman(game, move_cells, "Yeap, that was good!");
        return true;
    }
    //simple move to the empty cell
    else {
        make_move(game, move_cells);
        return true;
    }
}


bool check_rock_directions(ChessGame &game, t_move_cells move_cells) {
//the same as with bishop
    /*The following code cheks if there are other chessmans on the Bishop's way*/
    /*          the are 4 basic directions, so there are 4 cases below         */
    /*                                                                         */
    //the rock moves rigth
    if(move_cells.row_diff == 0 && move_cells.col_diff > 0) {
        for(int i = move_cells.col_start - 1; i > move_cells.col_dest; i--){
            if(game.get_board_cell(move_cells.row_start, i).chessman != nullptr){
                cout << "Ooops, there are chessmans on your way..\n";
                return false;
            }
        }
    }
    //the rock moves left
    else if(move_cells.row_diff == 0 && move_cells.col_diff < 0){
        for(int i = move_cells.col_start + 1; i < move_cells.col_dest; i++){
            if(game.get_board_cell(move_cells.row_start, i).chessman != nullptr){
                cout << "Ooops, there are chessmans on your way..\n";
                return false;
            }
        }
    }
    //the rock moves forwards
    else if(move_cells.row_diff > 0 && move_cells.col_diff == 0){
        for(int i = move_cells.row_start - 1; i > move_cells.row_dest; i--){
            if(game.get_board_cell(i, move_cells.col_start).chessman != nullptr){
                cout << "Ooops, there are chessmans on your way..\n";
                return false;
            }
        }
    }
    //the rock moves backwards
    else if(move_cells.row_diff < 0 && move_cells.col_diff == 0){
        for(int i = move_cells.row_start + 1; i < move_cells.row_dest; i++){
            if(game.get_board_cell(i, move_cells.col_start).chessman != nullptr){
                cout << "Ooops, there are chessmans on your way..\n";
                return false;
            }
        }
    }
    return true;
}


