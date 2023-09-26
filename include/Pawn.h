#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
    public:
        Pawn(std::vector<int> square, Color pieceColor, ChessBoard* board);
        bool isLegalMove(std::vector<int> square);
    private:
};