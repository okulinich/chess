#include "header.hpp"

void Display(ChessGame game){

	char displayBoard[17][25] = {
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', 'f', '1', '|', 'f', '2', '|', 'f', '3', '|', 'f', '4', '|', 'f', '5', '|', 'f', '6', '|', 'f', '7', '|', 'f', '8', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', 'f', '1', '|', 'f', '2', '|', 'f', '3', '|', 'f', '4', '|', 'f', '5', '|', 'f', '6', '|', 'f', '7', '|', 'f', '8', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', 'f', '1', '|', 'f', '2', '|', 'f', '3', '|', 'f', '4', '|', 'f', '5', '|', 'f', '6', '|', 'f', '7', '|', 'f', '8', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
        {'|', 'f', '1', '|', 'f', '2', '|', 'f', '3', '|', 'f', '4', '|', 'f', '5', '|', 'f', '6', '|', 'f', '7', '|', 'f', '8', '|'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' }
    };
    int disp_row[8] = {15, 13, 11, 9, 7, 5, 3, 1};
    int disp_col[8] = {1, 4, 7, 10, 13, 16, 19, 22};

	//updates real chessman locations on the "display board"
	for(int i = 0; i < 8; i++) {
	    for(int j = 0; j < 8; j++) {
            //update display board chessmans to match the real board
            if(game.get_board_cell(i, j).chessman == nullptr) {
                displayBoard[disp_row[i]][disp_col[j]] = ' ';
                displayBoard[disp_row[i]][disp_col[j] + 1] = ' ';
            }
            else if(game.get_board_cell(i, j).chessman->name.compare("Pawn") == 0) {
                displayBoard[disp_row[i]][disp_col[j]] = 'p';
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
            }
            else if(game.get_board_cell(i, j).chessman->name.compare("King") == 0) {
                displayBoard[disp_row[i]][disp_col[j]] = 'K';
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
            }
            else if(game.get_board_cell(i, j).chessman->name.compare("Queen") == 0) {
                displayBoard[disp_row[i]][disp_col[j]] = 'Q';
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
            }
            else if(game.get_board_cell(i, j).chessman->name.compare("Bishop") == 0) {
                displayBoard[disp_row[i]][disp_col[j]] = 'B';
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
            }
            else if(game.get_board_cell(i, j).chessman->name.compare("Knight") == 0) {
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
                displayBoard[disp_row[i]][disp_col[j]] = 'N';
            }
            else {
                displayBoard[disp_row[i]][disp_col[j]] = 'R';
                displayBoard[disp_row[i]][disp_col[j] + 1] = game.get_board_cell(i, j).chessman->player + '0';
            }
		}
	}

    cout << "   a  b  c  d  e  f  g  h\n";
	for(int i = 0, n = 7; i < 17; i++) {
        i % 2 == 1 ? cout << n-- << " " : cout << "  ";
		for(int j = 0; j < 25; j++)
			cout << displayBoard[i][j];
		cout << endl;
	}
	cout << endl << endl;

}

