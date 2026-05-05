#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
private:
    Piece* grid[8][8];

public:
    Board();
    ~Board();

    void setupBoard();
    void displayBoard() const;

    bool movePiece(int startX, int startY, int endX, int endY, Color currentPlayer);
    bool isKingCaptured(Color kingColor) const;
};

#endif