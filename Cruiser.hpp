// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Cruiser Size = 3
class Cruiser : public Ship
{
private:
  /* data */
public:
  Cruiser() : Ship("Cruiser", 3) {}
  ~Cruiser(){}
};
