#include "header.hpp"

bool check_queen_rules(ChessGame &game, t_move_cells move_cells) {
    if (abs(move_cells.row_diff) != abs(move_cells.col_diff) 
        && move_cells.row_diff != 0 && move_cells.col_diff != 0) {
        cout << "Nope, Queen can't do something like that\n";
        return false;
    }
    //Queen can move like a bishop and like a rock
    //so check if there are other chessmans on her way
    if(!check_rock_directions(game, move_cells) || !check_bishop_directions(game, move_cells))
        return false;
    //Queen eats enemy's chessmate
    if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player != game.get_current_player()){
        eat_chessman(game, move_cells, "Brilliant! Congratulations!");
        return true;
    }
    //simple move to the empty cell
    else {
        make_move(game, move_cells);
        return true;
    }
}

