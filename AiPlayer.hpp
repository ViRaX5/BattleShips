//
// -------------------------------------------
#pragma once
#include "Player.hpp"
// -------------------------------------------

class AiPlayer
{
private:
    /* data */
public:
    AiPlayer(/* args */);
    ~AiPlayer();
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
    int getRandomCoordinate();
};


