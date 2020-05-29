#include "header.hpp"

bool check_bishop_rules(ChessGame &game, t_move_cells move_cells) {
    //bishop can move only diagonally, so the difference beetween start-dest rows
    //and start-dest cols must be equal 
    if(abs(move_cells.row_diff) != abs(move_cells.col_diff)){
        cout << "Do you remember? Bishop can move only diagonally\n";
        return false;
    }
    //check if there are other chessmans on the bishop's way
    if(!check_bishop_directions(game, move_cells)) {
        return false;
    } 
    //bishop eats enemy's chassman
    if (game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman != nullptr 
        && game.get_board_cell(move_cells.row_dest, move_cells.col_dest).chessman->player != game.get_current_player()){
        eat_chessman(game, move_cells, "Well done! What a round!");
        return true;
    }
    //simple move to the empty cell
    else {
        make_move(game, move_cells);
        return true;
    }
}

bool check_bishop_directions(ChessGame &game, t_move_cells move_cells) {
/*The following code cheks if there are other chessmans on the Bishop's way*/
    /*          the are 4 diagonals, so there are 4 cases below                 */
    /*                                                                         */
    //if both differences are positive, then bishop moves backwards and to the left
    //for example from point [7][7] to [3][3], so i check if trere are other shessmans on the way
    if(move_cells.row_diff > 0 && move_cells.col_diff > 0) {
        for(int i = move_cells.row_start - 1; i > move_cells.row_dest; i--) {
            for(int j = move_cells.col_start - 1; j > move_cells.col_dest; j--) {
                if(game.get_board_cell(i, j).chessman != nullptr) {
                    cout << "Ooops, there are chessmans on your way..\n";
                    return false;
                }
            }
        }
    }
    //if both differences are negative, then bishop moves forwards and to the right
    else if(move_cells.row_diff < 0 && move_cells.col_diff < 0) {
        for(int i = move_cells.row_start+1; i < move_cells.row_dest; i++) {
            for(int j = move_cells.col_start+1; j < move_cells.col_dest; j++) {
                if (game.get_board_cell(i, j).chessman != nullptr) {
                    cout << "Ooops, there are chessmans on your way..\n";
                    return false;
                }
            }
        }
    }
    //bishop moves forwards and to the left
    else if(move_cells.row_diff > 0 && move_cells.col_diff < 0) {
        for(int i = move_cells.row_start-1; i > move_cells.row_dest; i--) {
            for(int j = move_cells.col_start+1; j < move_cells.col_dest; j++) {
                if(game.get_board_cell(i, j).chessman != nullptr) {
                    cout << "Ooops, there are chessmans on your way..\n";
                    return false;
                }
            }
        }
    }
    //bishop moves backwards and to the right
    else if(move_cells.row_diff < 0 && move_cells.col_diff > 0) {
        for(int i = move_cells.row_start+1; i < move_cells.row_dest; i++) {
            for(int j = move_cells.col_start-1; j > move_cells.col_dest; j--) {
                if(game.get_board_cell(i, j).chessman != nullptr) {
                    cout << "Ooops, there are chessmans on your way..\n";
                    return false;
                }
            }
        }
    }
    return true;
}

