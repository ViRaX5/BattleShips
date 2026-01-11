// Dor mandel;      ID : 315313825
// Amit Lachman;    ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------

class Carrier :  public Ship
{ 
public:
  Carrier() : Ship("Carrier",5) {}
  ~Carrier(){}
};

