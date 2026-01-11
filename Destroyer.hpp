// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
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
  ~Destroyer(){}
};
