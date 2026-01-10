//
// -------------------------------------------
#pragma once
#include "Player.hpp"
// -------------------------------------------

class AiPlayer : public Player
{
private:
    /* data */
public:
    AiPlayer(const char* name);
    ~AiPlayer();
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
    int getRandomCoordinate();
};


