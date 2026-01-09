//
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------

class Destroyer : public Ship
{
private:
  /* data */
public:
  Destroyer() : Ship("Destroyer", 2) {}
  ~Destroyer();
};
