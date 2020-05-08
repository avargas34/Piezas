#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *›
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
    //initialize size of board
    board.resize(BOARD_ROWS);
    for (auto i = 0; i < board.size(); i++)
    {
        board[i].resize(BOARD_COLS);
    }

    //set board locations to be blank
    for (auto i = 0; i < BOARD_ROWS; i++)
    {
        for (auto i2 = 0; i2 < BOARD_COLS; i2++)
        {
            board[i][i2] = Blank;
        }
    }

    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    //copy of constructor for blank board
    board.resize(BOARD_ROWS);
    for (auto i = 0; i < board.size(); i++)
    {
        board[i].resize(BOARD_COLS);
    }

    for (auto i = 0; i < BOARD_ROWS; i++)
    {
        for (auto i2 = 0; i2 < BOARD_COLS; i2++)
        {
            board[i][i2] = Blank;
        }
    }

    turn = X;
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
    if (turn == X)
    {
        //set turn to next player
        turn = O;

        //invalid location
        if (column > 3 || column < 0)
            return Invalid;

        //No blank spaces
        for (auto i = 0; i < BOARD_ROWS; i++)
        {
            if (board[i][column] == Blank)
            {
                board[i][column] = X;
                return X;
            }
        }
    }

    if (turn == O)
    {
        //set turn to next player
        turn = X;

        //invalid location
        if (column > 3 || column < 0)
            return Invalid;

        //No blank spaces
        for (auto i = 0; i < BOARD_ROWS; i++)
        {
            if (board[i][column] == Blank)
            {
                board[i][column] = O;
                return O;
            }
        }
    }

    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    //coordinates are out of bounds
    if (row > BOARD_ROWS || row < 0 || column > BOARD_COLS || column < 0)
        return Invalid;

    //return the piece at location
    else
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
    //Check if board is empty, return invalid if it is
    for (auto i = 0; i < BOARD_ROWS; i++)
    {
        for (auto i2 = 0; i2 < BOARD_COLS; i2++)
        {
            if (board[i][i2] == Blank)
                return Invalid;
        }
    }

    //Only runs if complete game
    int curX = 0;
    int curO = 0;
    int adjXhori = 0;
    int adjOhori = 0;
    int adjXcol = 0;
    int adjOcol = 0;
    
    //checking horizontally
    for (auto i = 0; i < BOARD_ROWS; i++)
    {
        adjXhori = 0;
        adjOhori = 0;

        for (auto i2 = 0; i2 < BOARD_COLS - 1; i2++)
        {
            if (board[i][i2] == board[i][i2 + 1] && board[i][i2] == 'X')
                adjXhori++;

            else if (board[i][i2] == board[i][i2 + 1] && board[i][i2] == 'O')
                adjOhori++;

            if (adjXhori > curX)
                curX = adjXhori;

            if (adjOhori > curO)
                curO = adjOhori;
        }
    }
    
    //checking vertically
    for (auto i = 0; i < BOARD_ROWS - 1; i++)
    {
        adjXcol = 0;
        adjOcol = 0;

        for (auto i2 = 0; i2 < BOARD_COLS; i2++)
        {
            if (board[i][i2] == board[i + 1][i2] && board[i][i2] == 'X')
                adjXcol++;

            else if (board[i][i2] == board[i + 1][i2] && board[i][i2] == 'O')
                adjOcol++;

            if (adjXcol > curX)
                curX = adjXcol;

            if (adjOcol > curO)
                curO = adjOcol;
        }
    }

    //X won
    if (curX > curO)
        return X;

    //O won
    if (curO > curX)
        return O;

    //tie game
    return Blank;
}