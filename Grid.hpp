//
// -------------------------------------------
#pragma once
// -------------------------------------------
// Grid Size: 10 X 10
#define  GRID_X_AXIS_MAX 10
#define  GRID_Y_AXIS_MAX 10
//
#define VALID_GRID_INPUT(row, col) ((row >= 0) && (row < GRID_X_AXIS_MAX) && (col >= 0) && (col < GRID_Y_AXIS_MAX))

// -------------------------------------------
#include <iostream>
#include <exception>
#include <stdexcept>
#include <iomanip>
// -------------------------------------------
// S = Ship
// X = Hit
// M = Miss
// horizontal = 1(Up/Down) : 0(Left/Right) ;

//Optional Helpers?
//struct for Coord?
enum Orientation{horizontal,Vertical};
enum AttackResult{Hit,Miss,AlreadyShot,Invalid};


class Grid
{
private:
  /* data */
  char cells[GRID_X_AXIS_MAX][GRID_Y_AXIS_MAX];
  //Helper Funcs:

public:
  Grid();
  ~Grid() {}
  inline bool isTileOccupied(int row, int col) const{return VALID_GRID_INPUT(row,col)? (cells[row][col] != '~') : false ;}

  bool inBounds(int row,int col,int shipSize,bool horizontal)const;

  void placeShip(int row,int col,int shipSize, bool horizontal, char symbol);

  void markHit(int row, int col);

  void markMiss(int row, int col);

  char getCell(int row,int col)const;

  void printGrid();

  void print(bool showAxes, bool hideShips) const;

  bool Grid::isInBounds(int row, int col) const;

  bool Grid::isAlreadyShot(int row, int col) const;
};

