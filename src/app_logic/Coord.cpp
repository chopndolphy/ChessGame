#include "app_logic/Coord.h"

Coord::Coord() {
    index.first = 0;
    index.second = 0;
    square.first = 'A';
    square.second = '1';
}
Coord::Coord(int xIndex, int yIndex) {
    index.first = xIndex;
    index.second = yIndex;
    square.first = indexToSqaure(xIndex, SquareAxis::File);
    square.second = indexToSqaure(yIndex, SquareAxis::Rank);
    }
Coord::Coord(char file, char rank) {
    square.first = std::toupper(file);
    square.second = std::toupper(rank);
    index.first = squareToIndex(file);
    index.second = squareToIndex(rank);
    }
void Coord::setIndex(int xIndex, int yIndex) {
    index.first = xIndex;
    index.second = yIndex;
    square.first = indexToSqaure(xIndex, SquareAxis::File);
    square.second = indexToSqaure(yIndex, SquareAxis::Rank);
    }
void Coord::setSquare(char file, char rank) {
    square.first = std::toupper(file);
    square.second = std::toupper(rank);
    index.first = squareToIndex(file);
    index.second = squareToIndex(rank);
    }
void Coord::setXIndex(int xIndex) {
    index.first = xIndex;
    square.first = indexToSqaure(xIndex, SquareAxis::File);
    }
void Coord::setYIndex(int yIndex) {
    index.second = yIndex;
    square.second = indexToSqaure(yIndex, SquareAxis::Rank);
    }
void Coord::setFile(char file) {
    square.first = std::toupper(file);
    index.first = squareToIndex(file);
    }
void Coord::setRank(char rank) {
    square.second = std::toupper(rank);
    index.second = squareToIndex(rank);
    }
int Coord::squareToIndex(char fileOrRank) {
    char character = toupper(fileOrRank);
    if (48 < static_cast<int>(character) && static_cast<int>(character) < 57) { // is a number between 1 and 8
        character -= '1';
    } else if (64 < static_cast<int>(character) && static_cast<int>(character) < 73) { // is a letter between A and H
        character -= 'A';
    }
    return static_cast<int>(character);
}
char Coord::indexToSqaure(int xOrY, SquareAxis fileOrRank) {
    int number = xOrY;
    switch (fileOrRank) {
        case SquareAxis::File:
            number += 65;
            break;
        case SquareAxis::Rank:
            number += 49;
            break;
    }
    return static_cast<char>(number);
}