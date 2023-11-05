#include "game_logic/ChessPiece.h"
#include "game_logic/ChessBoard.h"
#include "interface/BishopView.h"
#include "interface/KingView.h"
#include "interface/KnightView.h"
#include "interface/RookView.h"
#include "interface/PawnView.h"
#include "interface/QueenView.h"
#include "interface/BishopViewConsole.h"
#include "interface/KingViewConsole.h"
#include "interface/KnightViewConsole.h"
#include "interface/RookViewConsole.h"
#include "interface/PawnViewConsole.h"
#include "interface/QueenViewConsole.h"
#include <iostream>

ChessPiece::~ChessPiece() {
    delete view;
}
void ChessPiece::createView(Color color, PieceType type) {
    // macro to check if console or other?
    // factory pattern?

    switch (type) {
    case RookType:
        view = new RookViewConsole(color);
        break;
    case BishopType:
        view = new BishopViewConsole(color);
        break;
    case KnightType:
        view = new KnightViewConsole(color);
        break;
    case QueenType:
        view = new QueenViewConsole(color);
        break;
    case PawnType:
        view = new PawnViewConsole(color);
        break;
    case KingType:
        view = new KingViewConsole(color);
        break;
    default:
        break;
    }
}