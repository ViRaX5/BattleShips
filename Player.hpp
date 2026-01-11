// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267 
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
    /* -----------------------------------------------------------------------------------------
    * Function: Player::Player
    * Purpose : Initializes common player state (name, grid, ships container).
    * Input   : name (string/const char*)
    * Output  : none
    * Notes   : Does not start gameplay; only sets initial state.
    * ----------------------------------------------------------------------------------------- */
    Player(const char* name);
    ~Player();
    /* -----------------------------------------------------------------------------------------
    * Function: Player::placeAllShips
    * Purpose : Places all ships onto the player's grid (virtual/overridden by Human/AI).
    * Input   : none
    * Output  : none
    * Notes   : Must ensure no overlap and all ships are within bounds.
    * ----------------------------------------------------------------------------------------- */
    virtual void placeAllShips();
    /* -----------------------------------------------------------------------------------------
    * Function: Player::makeMove
    * Purpose : Performs one attack move against the opponent (virtual/overridden).
    * Input   : opponent (Player*)
    * Output  : none (or bool hit if you designed it so)
    * Notes   : Must handle invalid shots (out-of-bounds, repeated shots) before applying.
    * ----------------------------------------------------------------------------------------- */
    void makeMove(Player* opponent);
    /* -----------------------------------------------------------------------------------------
    * Function: Player::allShipsSunk
    * Purpose : Checks if the player's fleet is fully destroyed (lose condition).
    * Input   : none
    * Output  : true if all ships sunk, false otherwise
    * Notes   : Used by Game loop to decide when game ends.
    * ----------------------------------------------------------------------------------------- */
    bool allShipsSunk() const;
    void displayGrid();
    inline virtual char* getName() {return playerName;}
    virtual int getRowToPlaceShip() = 0;
    virtual int getColToPlaceShip() = 0;
    virtual bool getOrientationToPlaceShip() = 0;
    inline virtual Grid getGrid() const {return grid;}
};
/* -----------------------------------------------------------------------------------------
 * Function: HumanPlayer::placeAllShips
 * Purpose : Reads user input and places ships manually with validation.
 * Input   : none
 * Output  : none
 * Notes   : Must re-prompt on bad input, out-of-bounds, or overlap.
 * ----------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
 * Function: HumanPlayer::makeMove
 * Purpose : Reads user input for an attack and applies hit/miss to opponent grid.
 * Input   : opponent (Player*)
 * Output  : none (or bool)
 * Notes   : Must prevent repeated shots and reject invalid coordinates.
 * ----------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
 * Function: AiPlayer::placeAllShips
 * Purpose : Randomly places ships on its grid without overlaps/out-of-bounds.
 * Input   : none
 * Output  : none
 * Notes   : Should retry until valid placement is found for each ship.
 * ----------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
 * Function: AiPlayer::makeMove
 * Purpose : Chooses a valid random attack coordinate and applies it.
 * Input   : opponent (Player*)
 * Output  : none (or bool)
 * Notes   : Must never attack the same cell twice.
 * ----------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
 * Function: AiPlayer::getRandomCoordinate (if exists)
 * Purpose : Returns a random index within valid grid range.
 * Input   : none
 * Output  : int in range 0..9
 * Notes   : RNG should be seeded once in main (or use <random> engine).
 * ----------------------------------------------------------------------------------------- */