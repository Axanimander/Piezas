#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    turn = X;
    reset();
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    turn = X;
    board = std::vector<std::vector<Piece>>(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece returnType = Blank;
    if(column > BOARD_COLS || column < 0){
        returnType = Invalid;
        
    }else if(pieceAt(2, column) != Blank){
        returnType = Blank;
    }else{
        for(int row = 0; row < BOARD_ROWS; row++){
            if(pieceAt(row, column) == Blank){
                board[row][column] = turn;
                returnType = turn;
                break;
            }
        }
    }
    turn == X ? turn = O : turn = X;
    return returnType;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row > BOARD_ROWS || row < 0 || column > BOARD_COLS || column < 0){
        return Invalid;
    }
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int colx = 0;
    int colo = 0;
    int rowx = 0;
    int rowo = 0;
    int maxx = 0;
    int maxo = 0;
    for(int x = 0; x < BOARD_ROWS; x++){
        for(int y = 0; y < BOARD_COLS; y++){
            if(board[x][y] == Blank){
                return Invalid;
            }if(board[x][y] == X){
                colx++;
            }else if(board[x][y] == O){
                colo++;
            }
        }
        if(maxx < colx){
            maxx = colx;
        }if(maxo < colo){
            maxo = colo;
        }
    }
    for(int y = 0; y < BOARD_COLS; y++){
        for(int x = 0; x < BOARD_ROWS; x++){
            if(board[x][y] == X){
                rowx++;
            }else if(board[x][y] == O){
                rowo++;
            }
        }
        if(maxx < rowx){
            maxx = rowx;
        }if(maxo < rowo){
            maxo = rowo;
        }
    }

    if(maxx == maxo){
        return Blank;
    }

    return maxx > maxo ? X : O;
}