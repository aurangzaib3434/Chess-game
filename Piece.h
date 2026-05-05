#pragma once
#ifndef PIECE_H
#define PIECE_H

enum Color { WHITE, BLACK, NONE };

class Piece {
protected:
    Color color;
    char symbol;
    bool hasMoved;

public:
    Piece(Color c, char s);
    virtual ~Piece();

    Color getColor() const;
    char getSymbol() const;
    bool getHasMoved() const;
    void setHasMoved(bool moved);

    // Pure virtual function for polymorphism
    virtual bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) const = 0;
};

#endif