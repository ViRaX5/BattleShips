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
        displayStatus();
    }
    std::cout << player1->getName() << "'s board:" << std::endl;
    player1->getGrid().printGrid();
    std::cout << player2->getName() << "'s board:" << std::endl;
    player2->getGrid().printGrid();
    std::cout << "Congragulation!\n" << (p1Won ? player1->getName() : player2->getName()) << " won!" << std::endl;
    delete player1;
    delete player2;
    //  std::cout << "\nWinner is: " << winner->getName() << "\n";
    //  WinnerConfetti(winner->getName());
}

bool Game::isGameOver() const
{
    return (player1->allShipsSunk() || player2->allShipsSunk());   
}

void Game::displayStatus()
{
    using namespace std;
    cout << player1->getName() << "'s board:" << endl;
    player1->displayGrid();
    // cout << player2->getName() << "'s board:" << endl;
    // player2->displayGrid();
}