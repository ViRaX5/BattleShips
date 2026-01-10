// -------------------------------------------
#include "Game.hpp"
// -------------------------------------------

Game::Game(Player* p1, Player* p2)
{
    Game::player1 = p1;
    Game::player2 = p2;
}

void Game::setup()
{
    player1->placeAllShips();
    player2->placeAllShips();
}

void Game::start()
{
    bool p1Won = true;
    while (true)
    {
        player1->makeMove(player2);
        if (player2->allShipsSunk())
        {
            break;
        }
        player2->makeMove(player1);
        if (player1->allShipsSunk())
        {
            p1Won = false;
            break;
        }
    }
    std::cout << "Congragulation!\n" << p1Won ? player1->getName() : player2->getName() << " won!" << std::endl;
}

void Game::isGameOver()
{
    return (player1->allShipsSunk() || player2->allShipsSunk());   
}