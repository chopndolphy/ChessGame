#pragma once
#include "app_logic/Enums.h"
#include <array>
#include <string>

class UserInterface;
class Player;
class ChessBoard;
class GamePlay {
    public:
        GamePlay(Player* white, Player* black, ChessBoard* board, UserInterface* interface);
        void takeTurn();
        bool isGameOver() {
            return gameOver;
        }

    private:
        ChessBoard* board;
        Player* whitePlayer;
        Player* blackPlayer;
        UserInterface* userInterface;

        Color colorTurn = Color::White;
        bool gameOver = false;

        void updateGameState();
        void updateView(std::array<std::array<std::string, 8>, 8> boardView);
};