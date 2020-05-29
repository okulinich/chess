#pragma once
#include "Square.hpp"

class ChessGame {
    private:
        int current_player;
        int p1_chessmans_least; //these will be used to determine when the game is over (# of chessmans = 0 for either player)
        int p2_chessmans_least;
        std::string move;            //move to be parsed
        Square board[8][8];
    public:
        ChessGame();
        int get_current_player();
        void change_current_player();
        void decr_chessmans_amount(int player);
        std::string get_move();
        void set_move(std::string move);
        void init_board();
        Square get_board_cell(int x, int y);
        void del_board_cell(int x, int y);
        void set_board_cell(int x, int y, Chessman *new_chessman);
};
