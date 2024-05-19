#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
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
