#include "header.hpp"

bool check_knight_rules(ChessGame &game, t_move_cells move_cells) {
    //check if move can be performed with correct number of cells
    if (abs(move_cells.row_diff) * abs(move_cells.col_diff) != 2) {
        cout << "Nice try, bad realization. Incorrect move for Knight\n";
        return false;
    }
    //if knight eats enemy's chessman
    if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player != game.get_current_player()) {
        eat_chessman(game, move_cells, "You are a great warrior! Exccellent move");
        return true;
    }
    //simple move to the empty cell
    else {
        make_move(game, move_cells);
        return true;
    }
}

