# Tic-Tac-Toe AI with Minimax Algorithm

## Overview
This project implements the Minimax algorithm for a Tic-Tac-Toe game. The Minimax algorithm is a recursive decision-making system used for turn-based deterministic games where two players have opposing objectives. The AI ensures that it makes optimal moves by evaluating all possible game states and selecting the best one.

## Features
- **AI-powered Tic-Tac-Toe**: The AI uses the Minimax algorithm to determine the best moves.
- **User vs. AI Gameplay**: Users can play against an AI opponent.
- **Optimized Move Selection**: The AI calculates the best possible move based on the board state.
- **Terminal State Evaluation**: The algorithm identifies wins, losses, or draws effectively.
- **Error Handling**: Prevents invalid moves and ensures a smooth gaming experience.

## How It Works
The Minimax algorithm works by:
1. Evaluating all possible game states from the current state.
2. Assigning scores: a high positive score for an AI win, a negative score for a human win, and zero for a draw.
3. Recursively calling itself to explore all possible moves.
4. Selecting the optimal move for the AI by maximizing its score and minimizing the opponent’s score.

## Code Overview
The core functions of the implementation include:
- `displayBoard()`: Displays the current state of the game.
- `isMovesLeft()`: Checks if there are any remaining moves on the board.
- `evaluate()`: Determines the score of a given board state.
- `minimax(isMaximizing, depth)`: Recursively calculates the best move for AI.
- `findBestMove()`: Identifies the optimal move for the AI.
- `checkWin(player)`: Checks if a given player has won.
- `playGame()`: Manages the game loop, allowing user interaction.

## Getting Started
### Prerequisites
Ensure you have a C++ compiler installed, such as:
- GCC (g++)
- Clang
- MSVC (Windows users)

### Running the Game
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/tic-tac-toe-minimax.git
   ```
2. Navigate to the project directory:
   ```sh
   cd tic-tac-toe-minimax
   ```
3. Compile the code:
   ```sh
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
4. Run the game:
   ```sh
   ./tic_tac_toe
   ```

## How to Play
1. Choose your marker (X or O).
2. The AI will automatically play optimally.
3. Enter your move by specifying the row and column index (0-2).
4. The game continues until there is a win or a draw.

## Future Improvements
- Implement an Alpha-Beta Pruning optimization for faster decision-making.
- Add a GUI using a graphics library for better user experience.
- Allow two-player mode without AI involvement.
