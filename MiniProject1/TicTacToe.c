#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10  // Maximum grid size

// Function Prototypes
void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int size);
void printBoard(char board[MAX_SIZE][MAX_SIZE], int size);
void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player);
void aiMove(char board[MAX_SIZE][MAX_SIZE], int size, char aiPlayer,
            char humanPlayer);
int checkWin(char board[MAX_SIZE][MAX_SIZE], int size, char player);
int checkDraw(char board[MAX_SIZE][MAX_SIZE], int size);
void updateScore(int *playerScore, int *aiScore, int winner);

// Main Function
int main() {
  int size, mode, playerScore = 0, aiScore = 0, winner;
  char board[MAX_SIZE][MAX_SIZE];
  char currentPlayer;

  printf("Welcome to Tic-Tac-Toe!\n");
  while (1) {  // Loop for valid input
    printf("Enter board size (3 - 10): ");
    scanf("%d", &size);
    if (size >= 3 && size <= 10) {
      break;  // Break if input is valid
    }
    printf("Invalid size. Please enter a number between 3 and 10.\n");
  }
  // add a validate input to ensure the user inputs either 1 or 2
  printf("Choose mode: 1 for Player vs Player, 2 for Player vs AI: ");
  scanf("%d", &mode);

//Loop to make sure the mode input is valid
  while (mode != 1 && mode != 2) {
    printf("Invalid mode. Please enter 1 or 2: ");
    scanf("%d", &mode);
  }

//game running loop
  while (1) {
    initializeBoard(board, size);
    currentPlayer = 'X';  // 'X' always starts
    winner = 0;           // No winner initially
//prints out board and checks all the features of the tic tac toe game
    while (1) {
      printBoard(board, size);

    //For AI mode to determine whose turn it is
      if (currentPlayer == 'X' || mode == 1) {
        printf("Player %c's turn.\n", currentPlayer);
        playerMove(board, size, currentPlayer);
      } else {
        printf("AI's turn.\n");
        aiMove(board, size, 'O', 'X');
      }
      //checks to see if there was a win on the board
      if (checkWin(board, size, currentPlayer)) {
        printBoard(board, size);
        printf("Player %c wins!\n", currentPlayer);
        if (currentPlayer == 'X') {
          winner = 1;
        } else {
          winner = 2;
        }
        updateScore(&playerScore, &aiScore, winner);
        break;
      } 
      //checks to see if theres a draw on the board
      else if (checkDraw(board, size)) {
        printBoard(board, size);
        printf("It's a draw!\n");
        break;
      }

      // Switch turns
      if (currentPlayer == 'X') {
        currentPlayer = 'O';
      } else {
        currentPlayer = 'X';
      }
    }
 //displays score at the end of the match
    if (mode == 1) {
      printf("Score - Player 1: %d, Player 2: %d\n", playerScore, aiScore);
    } else {
      printf("Score - Player: %d, AI: %d\n", playerScore, aiScore);
    }
    printf("Play again? (1 for Yes, 0 for No): ");
    int rematch;
    scanf("%d", &rematch);
    if (!rematch) {
      break;
    }
  }
  return 0;
}

// Initialize the board with empty spaces
void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = ' ';
    }
  }
}

// Display the board
void printBoard(char board[MAX_SIZE][MAX_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf(" %c ", board[i][j]);
     //for the vertical lines
      if (j < size - 1) {
        printf("|");
      }
    }
    printf("\n");
    if (i < size - 1) {
      //for the horizontal lines
      for (int k = 0; k < size; k++) {
        printf("--- ");
      }
      printf("\n");
    }
  }
}

// Player move function
void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player) {
  int row, col;
  while (1) {
    printf("Enter row and column (1-%d) for player %c: ", size, player);
    scanf("%d %d", &row, &col);
    row--;
    col--;  // Adjust inputs for 0-based indexing
  //validates input
    if (row >= 0 && row < size && col >= 0 && col < size &&
        board[row][col] == ' ') {
      board[row][col] = player;
      break;
    } else {
      printf("Invalid move. Try again.\n");
    }
  }
}

void aiMove(char board[MAX_SIZE][MAX_SIZE], int size, char aiPlayer,
            char humanPlayer) {
  // 1. Win Check: If the AI can win in the next move, it takes that move.
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = aiPlayer;
        if (checkWin(board, size, aiPlayer)) {
          return;  // Win immediately
        }
        board[i][j] = ' ';
      }
    }
  }

  // 2. Block Check: If the opponent is about to win, the AI blocks the move.
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = humanPlayer;
        if (checkWin(board, size, humanPlayer)) {
          board[i][j] = aiPlayer;  // Block the human player
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // 3. Random Move: If no immediate win or block is available, the AI makes a
  // random move.
  int row, col;
  srand(time(0));
  do {
    row = rand() % size;
    col = rand() % size;
  } while (board[row][col] != ' ');
  board[row][col] = aiPlayer;
}

// Check for win condition
int checkWin(char board[MAX_SIZE][MAX_SIZE], int size, char player) {
  // Check rows and columns
  for (int i = 0; i < size; i++) {
    int rowWin = 1, colWin = 1;
    for (int j = 0; j < size; j++) {
      if (board[i][j] != player) {
        rowWin = 0;
      }
      if (board[j][i] != player) {
        colWin = 0;
      }
    }
    if (rowWin || colWin) {
      return 1;
    }
  }

  // Check diagonals
  int diagonals1 = 1, diagonals2 = 1;
  for (int i = 0; i < size; i++) {
    if (board[i][i] != player) {
      diagonals1 = 0;
    }
    if (board[i][size - i - 1] != player) {
      diagonals2 = 0;
    }
  }
  return diagonals1 || diagonals2;
}
 
// Check for draw condition
int checkDraw(char board[MAX_SIZE][MAX_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }  // Found an empty space, not a draw
  return 1;  // No empty spaces, it's a draw
}

// Update the score
void updateScore(int *playerScore, int *aiScore, int winner) {
  if (winner == 1) {
    (*playerScore)++;
  } else if (winner == 2) {
    (*aiScore)++;
  }
}
