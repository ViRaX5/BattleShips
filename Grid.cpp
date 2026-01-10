//
// -------------------------------------------
#include "Grid.hpp"
// -------------------------------------------

Grid::Grid()
{
  for(int row = 0 ; row < GRID_X_AXIS_MAX ;row++)
  {
    for(int col = 0 ; col < GRID_Y_AXIS_MAX ;col++)
    {
      cells[row][col] = '~';
    }
  }
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
  using namespace std;
  // if ((row<0)||(row>=GRID_X_AXIS_MAX)||(col<0)||(col>=GRID_Y_AXIS_MAX)) return false;
  if (!VALID_GRID_INPUT(row, col))
  {
    cout << "Invalid row/column" << endl;
    return false;
  }
  if (shipSize <= 0)
  {
    cout << "Invalid Ship Size!" << endl;
    return false;
  }

  else if (horizontal)
    return (col + shipSize - 1) < GRID_Y_AXIS_MAX;
  else
    return (row + shipSize - 1) < GRID_X_AXIS_MAX;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol = 'S')
{
  // checkUps:
  if (!inBounds(row, col, shipSize, horizontal) || (shipSize <= 0) || (symbol != 'S'))
  {
    std::cout << "Ship cannot Be Placed!" << std::endl;
    return;
  }
  if (horizontal)
  {
    for (int i = 0; i < shipSize; i++)
      cells[row][col + i] = symbol;
  }
  else
  {
    for (int i = 0; i < shipSize; i++)
      cells[row + i][col] = symbol;
  }
}

void Grid::markHit(int row, int col)
{
  using namespace std;
  if (!VALID_GRID_INPUT(row, col))
    cout << "MarkMiss out of Bounds! try again" << endl;
  if (cells[row][col] == 'X' || cells[row][col] == 'M')
    return;
  cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
  using namespace std;
  if (!VALID_GRID_INPUT(row, col))
    cout << "MarkMiss out of Bounds! try again" << endl;
  if (cells[row][col] == 'X' || cells[row][col] == 'M')
    return;
  cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const
{
  return Grid::cells[row][col];
}

// Helper Funcs:
void Grid::printGrid()
{
  for (int i = 0; i < GRID_X_AXIS_MAX; i++)
  {
    for (int j = 0; j < GRID_Y_AXIS_MAX; j++)
    {
      std::cout << cells[i][j] << " ";
    }
    std::cout << std::endl;
  }
  
}