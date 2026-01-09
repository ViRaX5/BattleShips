//
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------

class BattleShip : public Ship
{
public:
  BattleShip() : Ship("Battle Ship", 4) {}
  ~BattleShip();
};
