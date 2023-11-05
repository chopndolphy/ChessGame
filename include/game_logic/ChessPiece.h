#pragma once
#include <vector>
#include <cstdlib>
#include "app_logic/Enums.h"
#include "app_logic/ErrorLogger.h"
#include "game_logic/ChessBoard.h"
#include "interface/ChessPieceView.h" 

class ChessPiece {
    public:
        virtual ~ChessPiece();
        void move(std::vector<int> square) {
            pieceBoard->setPieceAt(square, this);
            location = square;
            movedYet = true;
        }
        virtual bool isLegalMove(std::vector<int> square) = 0;
        Color getColor() const {
            return color;
        }
        const std::vector<int> getLocation() const {
            return location;
        }
        bool hasDoubleMoved() const {
            return doubleMoved;
        }
        std::string getConsoleView() {
            return view->getConsoleDisplay();
        }
    protected:
        std::vector<int> location;
        Color color;
        bool movedYet;
        bool doubleMoved = false;
        ChessBoard* pieceBoard;
        ChessPieceView* view;
        void createView(Color color, PieceType type);
};