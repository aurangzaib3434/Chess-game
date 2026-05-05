#include "SpecificPieces.h"
#include <cmath>

// Helper function to check if sliding pieces are blocked
bool isPathClear(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    int dx = (endX - startX);
    int dy = (endY - startY);

    int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
    int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

    int currX = startX + stepX;
    int currY = startY + stepY;

    while (currX != endX || currY != endY) {
        if (board[currX][currY] != nullptr) return false;
        currX += stepX;
        currY += stepY;
    }
    return true;
}

King::King(Color c) : Piece(c, c == WHITE ? 'K' : 'k') {}
bool King::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return (dx <= 1 && dy <= 1) && (dx + dy > 0);
}

Queen::Queen(Color c) : Piece(c, c == WHITE ? 'Q' : 'q') {}
bool Queen::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    if ((startX == endX || startY == endY) || (dx == dy && dx > 0)) {
        return isPathClear(startX, startY, endX, endY, board);
    }
    return false;
}

Rook::Rook(Color c) : Piece(c, c == WHITE ? 'R' : 'r') {}
bool Rook::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    if (startX == endX || startY == endY) {
        return isPathClear(startX, startY, endX, endY, board);
    }
    return false;
}

Bishop::Bishop(Color c) : Piece(c, c == WHITE ? 'B' : 'b') {}
bool Bishop::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    if (dx == dy && dx > 0) {
        return isPathClear(startX, startY, endX, endY, board);
    }
    return false;
}

Knight::Knight(Color c) : Piece(c, c == WHITE ? 'N' : 'n') {}
bool Knight::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

Pawn::Pawn(Color c) : Piece(c, c == WHITE ? 'P' : 'p') {}
bool Pawn::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const {
    int direction = (color == WHITE) ? -1 : 1;

    // Forward move
    if (endY == startY && endX == startX + direction && board[endX][endY] == nullptr) {
        return true;
    }
    // First double move
    if (!hasMoved && endY == startY && endX == startX + 2 * direction &&
        board[endX][endY] == nullptr && board[startX + direction][startY] == nullptr) {
        return true;
    }
    // Diagonal capture
    if (std::abs(endY - startY) == 1 && endX == startX + direction &&
        board[endX][endY] != nullptr && board[endX][endY]->getColor() != color) {
        return true;
    }
    return false;
}