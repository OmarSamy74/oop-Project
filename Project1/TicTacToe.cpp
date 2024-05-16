#include "C:\Users\DELL\OneDrive\Desktop\baladina\Project1\Project1\TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

void TicTacToe::printBoard() const {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << "\n---------\n";
    }
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;  // Invalid move
    }

    board[row][col] = currentPlayer;
    return true;
}

bool TicTacToe::checkWinner() const {
    for (const auto& row : board) {
        if (row[0] == currentPlayer && row[1] == currentPlayer && row[2] == currentPlayer) {
            return true;
        }
    }

    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) {
            return true;
        }
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

bool TicTacToe::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void TicTacToe::playTicTacToe() {
    while (true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (!makeMove(row, col)) {
            cout << "Invalid move, try again.\n";
            continue;
        }

        if (checkWinner()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "It's a tie!\n";
            break;
        }

        switchPlayer();
    }
}
