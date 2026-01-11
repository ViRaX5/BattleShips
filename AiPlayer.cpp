// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "AiPlayer.hpp"
// -------------------------------------------

AiPlayer::AiPlayer(const char* name) : Player(name) {}

int AiPlayer::getRowToPlaceShip()
{
    return getRandomCoordinate();
}

int AiPlayer::getColToPlaceShip()
{
    return getRandomCoordinate();
}

bool AiPlayer::getOrientationToPlaceShip()
{
    return getRandomCoordinate()%2;
}

int AiPlayer::getRandomCoordinate()
{
    // Ensure srand(...) is called in main
    return std::rand() % 10;
}