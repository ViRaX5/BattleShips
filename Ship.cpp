//
// -------------------------------------------
#include "Ship.hpp"
#include <iostream>
// -------------------------------------------

/* summary:
increments hitsTaken and Prints "<shipname> got hit!"
*/
void Ship::takeHit()
{
  hitsTaken++;
  std::cout << "A ship was hit!" << std::endl;
  if (hitsTaken == size)
  {
    std::cout << name << " sunk!" << std::endl;
  }
  
}