#pragma once
#ifndef SPECIFICPIECES_H
#define SPECIFICPIECES_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

class Queen : public Piece {
public:
    Queen(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

class Rook : public Piece {
public:
    Rook(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

class Bishop : public Piece {
public:
    Bishop(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

class Knight : public Piece {
public:
    Knight(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

class Pawn : public Piece {
public:
    Pawn(Color c);
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const override;
};

#endif