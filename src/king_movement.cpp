#include "header.hpp"

//if choosed chess is king-> checks wether the move is valid
bool check_king_rules(ChessGame &game, t_move_cells move_cells) {
    //king can move only on one cell 
    if(abs(move_cells.row_diff) > 1 || abs(move_cells.col_diff) > 1) {
        cout << "Hey, King can move only on one cell\n";
        return false;
    }
    //if there is enemy's chessman on the destination cell
    if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player != game.get_current_player()) {
        eat_chessman(game, move_cells, "The king of the North! Good move:)");
        return true;
    }
    //simple move to the empty cell
    else {
        make_move(game, move_cells);
        return true;
    }
}
