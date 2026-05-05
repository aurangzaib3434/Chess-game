#include "Board.h"
#include "SpecificPieces.h"
#include <iostream>
#include <cstdlib>
#include <windows.h> // INTERNAL WINDOWS LIBRARY FOR COLORS

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            grid[i][j] = nullptr;
    setupBoard();
}

Board::~Board() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (grid[i][j] != nullptr) delete grid[i][j];
}

void Board::setupBoard() {
    // Black Major Pieces
    grid[0][0] = new Rook(BLACK); grid[0][1] = new Knight(BLACK);
    grid[0][2] = new Bishop(BLACK); grid[0][3] = new Queen(BLACK);
    grid[0][4] = new King(BLACK); grid[0][5] = new Bishop(BLACK);
    grid[0][6] = new Knight(BLACK); grid[0][7] = new Rook(BLACK);

    // Black Pawns
    for (int i = 0; i < 8; i++) grid[1][i] = new Pawn(BLACK);

    // White Major Pieces
    grid[7][0] = new Rook(WHITE); grid[7][1] = new Knight(WHITE);
    grid[7][2] = new Bishop(WHITE); grid[7][3] = new Queen(WHITE);
    grid[7][4] = new King(WHITE); grid[7][5] = new Bishop(WHITE);
    grid[7][6] = new Knight(WHITE); grid[7][7] = new Rook(WHITE);

    // White Pawns
    for (int i = 0; i < 8; i++) grid[6][i] = new Pawn(WHITE);
}

void Board::displayBoard() const {
    system("cls"); // Clears console screen

    // Get Windows Console Handle for colors
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\n    0  1  2  3  4  5  6  7\n";
    cout << "  -------------------------\n";

    for (int i = 0; i < 8; ++i) {
        SetConsoleTextAttribute(hConsole, 7); // Reset to default console color (White text on Black)
        cout << i << " |";

        for (int j = 0; j < 8; ++j) {
            // NAYE COLORS:
            // 112 = Light Gray Background (Light squares)
            // 48  = Cyan Background (Dark squares)
            int bgColor = ((i + j) % 2 == 0) ? 112 : 48;
            int fgColor = 0; // Default text color

            if (grid[i][j] != nullptr) {
                // White Pieces = 15 (Bright White text)
                // Black Pieces = 0 (Pure Black text)
                fgColor = (grid[i][j]->getColor() == WHITE) ? 15 : 0;
            }

            // Apply color to console square
            SetConsoleTextAttribute(hConsole, bgColor + fgColor);

            if (grid[i][j] == nullptr) {
                cout << "   "; // Empty square (colored background only)
            }
            else {
                cout << " " << grid[i][j]->getSymbol() << " "; // Piece with color
            }
        }

        SetConsoleTextAttribute(hConsole, 7); // Reset to default color after row ends
        cout << "| " << i << "\n";
    }

    cout << "  -------------------------\n";
    cout << "    0  1  2  3  4  5  6  7\n\n";
}

bool Board::isKingCaptured(Color kingColor) const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getColor() == kingColor) {
                if (grid[i][j]->getSymbol() == 'K' || grid[i][j]->getSymbol() == 'k') {
                    return false; // King is still on the board
                }
            }
        }
    }
    return true; // King is missing (Captured)
}

bool Board::movePiece(int startX, int startY, int endX, int endY, Color currentPlayer) {
    // Validate boundaries
    if (startX < 0 || startX > 7 || startY < 0 || startY > 7 || endX < 0 || endX > 7 || endY < 0 || endY > 7) {
        cout << "Error: Out of bounds!\n"; return false;
    }

    Piece* pieceToMove = grid[startX][startY];

    // Basic Validations
    if (pieceToMove == nullptr) {
        cout << "Error: No piece at starting position!\n"; return false;
    }
    if (pieceToMove->getColor() != currentPlayer) {
        cout << "Error: Not your turn!\n"; return false;
    }
    if (grid[endX][endY] != nullptr && grid[endX][endY]->getColor() == currentPlayer) {
        cout << "Error: Cannot capture your own piece!\n"; return false;
    }

    // Call Polymorphic ValidMove from specific pieces
    if (pieceToMove->isValidMove(startX, startY, endX, endY, grid)) {
        // Check Win Condition (Captured King)
        if (grid[endX][endY] != nullptr && (grid[endX][endY]->getSymbol() == 'K' || grid[endX][endY]->getSymbol() == 'k')) {
            cout << "\n*** KING CAPTURED! GAME OVER! ***\n";
            system("pause");
            exit(0);
        }

        // Execute Move
        delete grid[endX][endY];
        grid[endX][endY] = pieceToMove;
        grid[startX][startY] = nullptr;
        pieceToMove->setHasMoved(true);
        return true;
    }
    else {
        cout << "Error: Invalid move for that piece type!\n";
        return false;
    }
}