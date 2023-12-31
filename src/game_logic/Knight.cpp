#include "game_logic/Knight.h"
#include "interface/KnightViewConsole.h"

Knight::Knight(Color color, Coord location, ChessBoard* board) {
    this->location = location;
    this->color = color;
    this->board = board;
    movedYet = false;
    createView();
}
bool Knight::isLegalMove(Coord destination) {
    int pathLengthX = std::abs(destination.x() - location.x());
    int pathLengthY = std::abs(destination.y() - location.y());
    if (location.x() == destination.x() && location.y() == destination.y()) {
        return false; // Moving to same square
    } else if (board->getPieceAt(destination)->getColor() == color) {
        return false; // Moving to same colored piece
    } else if (location.x() > 7 || location.x() < 0 || location.y() > 7 || location.y() < 0) {
        return false; // Moving out of bounds
    } else if ((pathLengthX == 1 && pathLengthY == 2) || (pathLengthX == 2 && pathLengthY == 1)) {
        return true; // Correctly moving in L shape
    } else {
        return false;
    }
}
void Knight::createView() {
    view = new KnightViewConsole(color);
}