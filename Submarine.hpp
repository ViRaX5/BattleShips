// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Submarine Size = 3
class Submarine : public Ship
{
private:
public:
  Submarine() : Ship("Submarine", 3) {}
  ~Submarine(){}
};
