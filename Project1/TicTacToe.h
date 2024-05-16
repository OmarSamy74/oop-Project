#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe();

    void printBoard() const;
    bool makeMove(int row, int col);
    bool checkWinner() const;
    bool isBoardFull() const;
    void switchPlayer();
    void playTicTacToe();
};

#endif // TICTACTOE_H
