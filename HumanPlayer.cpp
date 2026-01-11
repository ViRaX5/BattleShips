// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "HumanPlayer.hpp"
// -------------------------------------------
#include <string>
#include <algorithm>
#include <cctype>
// -------------------------------------------

HumanPlayer::HumanPlayer(const char* name) : Player(name)
{
}

int HumanPlayer::getRowToPlaceShip()
{
    std::cout << "Please choose a row (0-9)" << std::endl;
    int row = -1;
    while (!(row >= 0 && row <= 9))
    {
        std::cin >> row;
        //row--;
        if (!(row >= 0 && row <= 9))
        {
            std::cout << "Invalid row number, try again" << std::endl;
        }  
    }
    return row;
}

int HumanPlayer::getColToPlaceShip()
{
    std::cout << "Please choose a column (0-9)" << std::endl;
    int column = -1;
    while (!(column >= 0 && column <= 9))
    {
        std::cin >> column;
        if (!(column >= 0 && column <= 9))
        {
            std::cout << "Invalid column number, try again" << std::endl;
        }  
    }
    return column;
}

bool HumanPlayer::getOrientationToPlaceShip()
{
    while (true)
    {
        std::cout << "Please choose in what orientation you want the ship to be (horizontal/vertical/h/v)" << std::endl;
        std::string orientation;
        std::cin >> orientation;
        std::transform(orientation.begin(), orientation.end(), orientation.begin(), ::tolower);
        if (orientation == "horizontal" || orientation == "h")
        {
            return true;
        }
        else if (orientation == "vertical" || orientation == "v")
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
