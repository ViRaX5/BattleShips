// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
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


