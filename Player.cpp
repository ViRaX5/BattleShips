//
#include "Player.hpp"
#include <string.h>

Player::Player(const char *name)
{
    strcpy(playerName, name);
    BattleShip *b = new BattleShip();
    Carrier *ca = new Carrier();
    Cruiser *cr = new Cruiser();
    Destroyer *d = new Destroyer();
    Submarine *s = new Submarine();
    ships[0] = b;
    ships[1] = ca;
    ships[2] = cr;
    ships[3] = d;
    ships[4] = s;
}

Player::~Player()
{
    delete[] playerName;
    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        delete ships[i];
    } 
}

void Player::placeAllShips()
{
    int i = 0;
    while (i < NUM_OF_SHIPS)
    {
        std::cout << "Please place the ship: " << ships[i]->getName() << std::endl;
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        bool orientation = getOrientationToPlaceShip();
        if ((grid.inBounds(row, col, ships[i]->getSize(), orientation)) && (!grid.isTileOccupied(row, col)))
        {
            grid.placeShip(row, col, ships[i]->getSize(), orientation, 'S');
            ships[i]->setCoord(row, col);
            i++;
        }
        else
        {
            std::cout << "Invalid ship placement attempt, try again" << std::endl;
        }
    }
}
void Player::makeMove(Player *opponent)
{
    while (true)
    {
        std::cout << "Make an attack! Where would you like to attack?" << std::endl;
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        if (opponent->grid.getCell(row, col) == '~')
        {
            opponent->grid.markMiss(row, col);
        }
        else if (opponent->grid.getCell(row, col) == 'S')
        {
            for (int i = 0; i < NUM_OF_SHIPS; i++)
            {
                if (ships[i]->isHorizontal())
                {
                    if (row == ships[i]->getRow())
                    {
                        if (col >= ships[i]->getCol() && col <= (ships[i]->getCol() + ships[i]->getSize()))
                        {
                            ships[i]->takeHit();
                            break;
                        }
                    }
                }
                else
                {
                    if (col == ships[i]->getCol())
                    {
                        if (row >= ships[i]->getRow() && row <= (ships[i]->getRow() + ships[i]->getSize()))
                        {
                            ships[i]->takeHit();
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            std::cout << "You are trying to hit somewhere you have already shot at, try again." << std::endl;
        }
    }
}
bool Player::allShipsSunk() const
{
    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        if (!ships[i]->isSunk())
        {
            return false;
        }
    }
    return true;
}
void Player::displayGrid()
{
    grid.printGrid();
}
