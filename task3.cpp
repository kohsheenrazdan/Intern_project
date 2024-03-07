#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the game is over
bool gameOver(const vector<vector<char>>& board, char& winner) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {
            winner = board[i][0];
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '.') {
            winner = board[0][j];
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')) {
        winner = board[1][1];
        return true;
    }

    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }

    // If no winner and the board is full, it's a draw
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.')); // Initialize empty board
    char currentPlayer = 'X';
    char winner = ' ';

    // Main game loop
    while (true) {
        // Draw the board
        drawBoard(board);

        // Prompt the current player to make a move
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by space: ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '.') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board with the current player's move
        board[row][col] = currentPlayer;

        // Check if the game is over
        if (gameOver(board, winner)) {
            // Draw the final board
            drawBoard(board);

            // Print the result
            if (winner == ' ') {
                cout << "It's a draw!" << endl;
            } else {
                cout << "Player " << winner << " wins!" << endl;
            }
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
