//
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------

class Cruiser : public Ship
{
private:
  /* data */
public:
  Cruiser() : Ship("Cruiser", 3) {}
  ~Cruiser(){}
};
