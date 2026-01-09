//
// -------------------------------------------
#include "HumanPlayer.hpp"
#include <string>
#include <algorithm>
#include <cctype>
// -------------------------------------------

int HumanPlayer::getRowToPlaceShip()
{
    std::cout << "Please choose in what row you want to place your ship" << std::endl;
    int row = -1;
    std::cin >> row;
    return row;
}

int HumanPlayer::getColToPlaceShip()
{
    std::cout << "Please choose in what column you want to place your ship" << std::endl;
    int column = -1;
    std::cin >> column;
    return column;
}

bool HumanPlayer::getOrientationToPlaceShip()
{
    while (true)
    {
        std::cout << "Please choose in what orientation you want the ship to be (horizontal/vertical)" << endl;
        std::string orientation;
        std::cin >> orientation;
        std::transform(orientation.begin(), orientation.end(), orientation.begin(), ::tolower);
        if (orientation == "horizontal")
        {
            return true;
        }
        else if (orientation == "vertical")
        {
            return false;
        }
        else
        {
            std::cout << "invalid input, write horizontal or vertical, try again." << std::endl;
        } 
    }
    return true;
}
