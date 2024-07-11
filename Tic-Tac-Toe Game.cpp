#include <iostream>
#include <vector>

using namespace std;
int coor;
// define the game board
vector<vector<char>> board(3, vector<char>(3, ' '));

//   function to display the current state of the board
void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has   won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draww
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool playAgain = true;
    while (playAgain) {
        char currentPlayer = 'X';
        bool gameOver = false;

        // Clear the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row column): ";

            int row, col;
            cin >> row >> col;

            // Check if the move is valid
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move, try again." << endl;
                continue;
            }

            // Update the board with the players's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            // Check if the game is a draw
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            }
            // Switch to the other player
            else {
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                } else {
                    currentPlayer = 'X';
                }
            }
        }

        // Ask if the players want to play again
        char playAgainInput;
        cout << "Do you want to play again? (y/n) ";
        cin >> playAgainInput;
        playAgain = (playAgainInput == 'y' || playAgainInput == 'Y');
    }

    return 0;
}