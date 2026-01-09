//
// -------------------------------------------
#pragma once

#include "Player.hpp"
// -------------------------------------------

class HumanPlayer : public Player
{
private:
    /* data */
public:
    HumanPlayer(/* args */);
    ~HumanPlayer();
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
};


