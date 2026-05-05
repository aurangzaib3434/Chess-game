#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board gameBoard;
    Color currentPlayer = WHITE;
    bool gameOver = false;

    cout << "=== OOP CONSOLE CHESS ===\n";

    while (!gameOver) {
        gameBoard.displayBoard();
        cout << (currentPlayer == WHITE ? "White's turn (UPPERCASE)" : "Black's turn (lowercase)") << "\n";

        int startX, startY, endX, endY;
        cout << "Enter move (row col to row col, e.g., 6 0 5 0): ";
        cin >> startX >> startY >> endX >> endY;

        if (gameBoard.movePiece(startX, startY, endX, endY, currentPlayer)) {
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
        }
        else {
            cout << "Press Enter to try again...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}