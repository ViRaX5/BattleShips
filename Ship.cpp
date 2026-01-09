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
  std::cout << name << "got hit!" << std::endl;

}