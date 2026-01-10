//
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Grid.hpp"
#include "Ship.hpp"
#include "BattleShip.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
// -------------------------------------------

#define NUM_OF_SHIPS 5

class Player
{
private:
    char *playerName;
    Ship* ships[NUM_OF_SHIPS];
    Grid grid;
public:
    Player(const char* name);
    ~Player();
    virtual void placeAllShips();
    void makeMove(Player* opponent);
    bool allShipsSunk() const;
    void displayGrid();
    inline virtual char* getName() {return playerName;}
    virtual int getRowToPlaceShip() = 0;
    virtual int getColToPlaceShip() = 0;
    virtual bool getOrientationToPlaceShip() = 0;
};
