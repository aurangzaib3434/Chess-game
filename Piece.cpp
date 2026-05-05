#include "Piece.h"

Piece::Piece(Color c, char s) : color(c), symbol(s), hasMoved(false) {}
Piece::~Piece() {}

Color Piece::getColor() const { return color; }
char Piece::getSymbol() const { return symbol; }
bool Piece::getHasMoved() const { return hasMoved; }
void Piece::setHasMoved(bool moved) { hasMoved = moved; }