#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <limits> // for std::numeric_limits

/*
 * Program: Tic-Tac-Toe Board
 * Author: Francisco Figueroa
 * Date: 2025-10-25
 * Description: Just a simple tic-tac-toe game I been working on to work on my C++ skills.
 */



char board[3][3]; // 3x3 character array representing the game board



// Generate a random number 0, 1, or 2
int randomNumberGenerator() {

    return std::rand() % 3; // returns 0, 1, or 2
}


/**
 * @brief Creates an empty board.
 */

void createBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
}

/**
 * @brief This iterates through the board array in order to print out it's contents.
 */

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief This makes the robot moves.
 */

 void playerMove() {

     std::cout << std::endl <<"Player Move: " << std::endl;
     int row, col;
     do {
         std::cout << "Enter row (1-3) and column (1-3): ";
         std::cin >> row >> col;

         if (board[row-1][col-1] != '_') {
             std::cout << "Cell already taken. Try again." << std::endl;
         }
         if (std::cin.fail()) {
             std::cout << "Invalid input! Not an integer." << std::endl;
             std::cin.clear();
             std::cin.ignore(1000, '\n'); // ignore up to 1000 characters until newline

         }

     } while (board[row-1][col-1] != '_');

     board[row-1][col-1] = 'X';
 }


/**
 * @brief This makes the robot moves.
 */
 void robotMove() {
     std::cout << std::endl <<"Robot Move: " << std::endl;

     int row, col;
     do {
         row = randomNumberGenerator();
         col = randomNumberGenerator();
     } while (board[row][col] != '_'); // repeat until an empty cell is found

     board[row][col] = 'O';
 }


/**
 * @brief Returns true if the board still has an empty space.
 */

bool checkAvailable() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Returns true if the rows equal to each other
 */
 bool checkRows() {
     for (int i = 0; i < 3; i++) {
         if (board[i][0] != '_' &&
             board[i][0] == board[i][1] &&
             board[i][1] == board[i][2]) {
             return true;
         }
     }
     return false;
 }

 /**
  * @brief Returns true if the columns equal to each other
  */
 bool checkColumns() {
     for (int i = 0; i < 3; i++) {
         if (board[0][i] != '_' &&
             board[0][i] == board[1][i] &&
             board[1][i] == board[2][i]) {
             return true;
         }
     }
     return false;
 }

 /**
  * @brief Returns true if the diagonals equal to each other
  */
 bool checkDiagonals() {
     if (board[1][1] != '_' &&
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
         return true;
     }
     return false;
 }


 /**
  * @brief Returns true if there is a winner
  */
bool checkWin() {

    if (checkRows() || checkColumns() || checkDiagonals()) {
        std::cout << "We Have A Winner";
        return true;
    }
    return false;

}

int main() {
    createBoard();
    std::srand(time(0)); // This is a random generator seed.
    printBoard();

    while (checkAvailable() && !checkWin()) { // Basically keeps going if there is free space, and there is no winner yet.
        playerMove();
        printBoard();
        robotMove();
        printBoard();

    }
return 0;
}
