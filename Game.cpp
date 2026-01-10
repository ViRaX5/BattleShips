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
    std::cout << "Placing ships!" << std::endl;
    player1->placeAllShips();
    player2->placeAllShips();
}

void Game::start()
{
    bool p1Won = true;
    while (true)
    {
        std::cout << "Player 1 display:\n";
        player1->displayGrid();
        std::cout << "Player 2 display:\n";
        player2->displayGrid();
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
    std::cout << "Congragulation!\n" << (p1Won ? player1->getName() : player2->getName()) << " won!" << std::endl;
}

bool Game::isGameOver() const
{
    return (player1->allShipsSunk() || player2->allShipsSunk());   
}