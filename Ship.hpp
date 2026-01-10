//
// -------------------------------------------
#pragma once
// -------------------------------------------
#include <iostream>
#include <string.h>
// -------------------------------------------
using std::string;

class Ship
{
private:
  char* name;  // or char* name as written in the Assignment Page
  int size;
  int hitsTaken;
  int row;
  int column;
  bool horizontal;

public:
  Ship(const char *shipName, int shipSize): size(shipSize) ,hitsTaken(0) {name = new char[strlen(shipName) + 1]; strcpy(name, shipName);}
  virtual ~Ship() {delete[] name;}
  virtual void takeHit();
  inline bool isSunk() const {return  hitsTaken >= size;}
  inline int getSize() {return size;}
  inline void setCoord(int row, int col, bool hor) {this->row = row; column = col; horizontal = hor;}
  inline int getRow() {return row;}
  inline int getCol() {return column;}
  //inline void setHorizontal(bool hor) {horizontal = hor;}
  inline bool isHorizontal() {return horizontal;}
  inline char* getName() {return name;}
};

/*
Carrier (size = 5)
Battleship (size = 4)
Cruiser (size = 3)
Submarine (size = 3)
Destroyer (size = 2)
*/