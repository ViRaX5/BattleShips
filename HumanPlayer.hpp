// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Player.hpp"
// -------------------------------------------

class HumanPlayer : public Player
{    
public:
    HumanPlayer(const char* name);
    ~HumanPlayer();
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
};

