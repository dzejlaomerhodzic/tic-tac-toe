#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// The outcome of game can be determined with these constatnt values:
const int AI_WIN = 10;
const int HUMAN_WIN = -10;
const int DRAW = 0;

// The board in which Tic Tac Toe is played
vector<vector<char>> board(3, vector<char>(3, ' '));

// Different types of functions which will be used:
void displayBoard();
bool isMovesLeft();
int evaluate();
int minimax(bool isMaximizing, int depth);
pair<int, int> findBestMove();
bool checkWin(char player);
void playGame();

int main() {
    playGame();
    return 0;
}

// Does not return anything just displays the current state of game
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (board[i][j] == ' ' ? '-' : board[i][j]) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Check if there are moves left on the board
bool isMovesLeft() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

// Evulauation of the current state of game
int evaluate() {
    if (checkWin('X')) {
        return AI_WIN;
    }
    if (checkWin('O')) {
        return HUMAN_WIN;
    }
    return DRAW;
}

// Check if a player has won the game
bool checkWin(char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Implementazion of the Minimax algorithm (for finding the best move)
int minimax(bool isMaximizing, int depth) {
    int score = evaluate();

    // Base outcomes: game over or no moves left
    if (score == AI_WIN || score == HUMAN_WIN || !isMovesLeft()) {
        return score;
    }

    if (isMaximizing) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X'; // AI's move
                    best = max(best, minimax(false, depth + 1));
                    board[i][j] = ' '; // Undo the move
                }
            }
        }
        return best - depth; // Prefer quicker wins
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O'; // Human's move
                    best = min(best, minimax(true, depth + 1));
                    board[i][j] = ' '; // Undo the move
                }
            }
        }
        return best + depth; // Delay losses
    }
}

// Find the best move for the AI
pair<int, int> findBestMove() {
    int bestValue = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X'; // AI's move
                int moveValue = minimax(false, 0);
                board[i][j] = ' '; // Undo the move
                if (moveValue > bestValue) {
                    bestMove = {i, j};
                    bestValue = moveValue;
                }
            }
        }
    }
    return bestMove;
}

// Main game loop (where the game as a whole is happening)
void playGame() {
    char humanPlayer, aiPlayer;
    cout << "Choose your marker (X or O): ";
    cin >> humanPlayer;
    aiPlayer = (humanPlayer == 'X') ? 'O' : 'X';

    cout << "You are: " << humanPlayer << ", AI is: " << aiPlayer << "\n";
    displayBoard();

    while (true) {
        if (humanPlayer == 'X') {
            // Human's turn
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;

            // Input validation
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = 'X';
            displayBoard();

            if (checkWin('X')) {
                cout << "You win!\n";
                break;
            }
            if (!isMovesLeft()) {
                cout << "It's a draw!\n";
                break;
            }

            auto [aiRow, aiCol] = findBestMove();
            board[aiRow][aiCol] = 'O';
            cout << "AI moves to " << aiRow << ", " << aiCol << "\n";
            displayBoard();

            if (checkWin('O')) {
                cout << "AI wins!\n";
                break;
            }
        } else {
            // AI's turn
            auto [aiRow, aiCol] = findBestMove();
            board[aiRow][aiCol] = 'X';
            cout << "AI moves to " << aiRow << ", " << aiCol << "\n";
            displayBoard();

            if (checkWin('X')) {
                cout << "AI wins!\n";
                break;
            }
            if (!isMovesLeft()) {
                cout << "It's a draw!\n";
                break;
            }

            // Human's turn
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;

            // Input validation
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = 'O';
            displayBoard();

            if (checkWin('O')) {
                cout << "You win!\n";
                break;
            }
        }

        if (!isMovesLeft()) {
            cout << "It's a draw!\n";
            break;
        }
    }
}
