//
#include "Player.hpp"
#include <string.h>

Player::Player(const char *name)
{
    playerName = new char[strlen(name) + 1];
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
            ships[i]->setCoord(row, col,orientation);
            //ships[i]->setHorizontal(orientation);
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
    std::cout << "It is " << getName() << "'s turn!" << std::endl;
    while (true)
    {
        std::cout << "Make an attack! Where would you like to attack?" << std::endl;
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        if (opponent->grid.getCell(row, col) == '~')
        {
            opponent->grid.markMiss(row, col);
            break;
        }
        else if (opponent->grid.getCell(row, col) == 'S')
        {
            for (int i = 0; i < NUM_OF_SHIPS; i++)
            {
                std::cout << "Debug, searching ships, current ship is: " << ships[i]->getName() << std::endl;
                if (opponent->ships[i]->isHorizontal())
                {
                    if (row == opponent->ships[i]->getRow())
                    {
                        if (col >= opponent->ships[i]->getCol() && col < (opponent->ships[i]->getCol() + opponent->ships[i]->getSize()))
                        {
                            std::cout << "Debug, ship name is: " << opponent->ships[i]->getName() << std::endl;
                            opponent->ships[i]->takeHit();
                            break;
                        }
                    }
                }
                else
                {
                    if (col == opponent->ships[i]->getCol())
                    {
                        if (row >= opponent->ships[i]->getRow() && row < (opponent->ships[i]->getRow() + opponent->ships[i]->getSize()))
                        {
                            std::cout << "Debug, ship name is: " << opponent->ships[i]->getName() << std::endl;
                            opponent->ships[i]->takeHit();
                            break;
                        }
                    }
                }
                
            }
            opponent->grid.markHit(row, col);
            break;
        }
        else
        {
            std::cout << "You are trying to hit somewhere you have already shot at, try again." << std::endl;
        }
    }
    std::cout << opponent->getName() << "'s grid:" << std::endl;
    opponent->displayGrid();
    std::cout << getName() << "'s grid:" << std::endl;
    displayGrid();
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
    for (int i = 0; i < GRID_X_AXIS_MAX; i++)
    {
        for (int j = 0; j < GRID_Y_AXIS_MAX; j++)
        {
            if (grid.getCell(i, j) == 'S')
            {
                std::cout << "~ ";
            }
            else
            {
                std::cout << grid.getCell(i, j) << " ";
            }
        }
        std::cout << std::endl;
    }
    
}
