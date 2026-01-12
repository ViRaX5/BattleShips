// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267
// -------------------------------------------
#include "Game.hpp"
// -------------------------------------------
#define MAX_TURNS_PER_PLAYER 200
// -------------------------------------------
Game::Game(Player *p1, Player *p2)
{
    Game::_player1 = p1;
    Game::_player2 = p2;
}

void Game::setup()
{
    std::cout << "Placing ships!" << std::endl;
    _player1->placeAllShips();
    _player2->placeAllShips();
}

void Game::start()
{
    // bool p1Won = true;

    bool gameOver = false;
    bool p1Won = false;
    int turn = 0;

    // while (true)
    while (turn < MAX_TURNS_PER_PLAYER && !gameOver)
    {
        _player1->makeMove(_player2);
        if (_player2->allShipsSunk())
        {
            p1Won = true;
            gameOver = true;
            break;
        }
        _player2->makeMove(_player1);
        if (_player1->allShipsSunk())
        {
            p1Won = false;
            gameOver = true;
            break;
        }
        ++turn;
        displayStatus();
    }

    bool draw = (!gameOver && turn == MAX_TURNS_PER_PLAYER);

    if (draw)
        std::cout << "Simulation ended in a DRAW (Max turns reached)." << std::endl;

    std::cout << _player1->getName() << "'s board:" << std::endl;
    _player1->getGrid().print();
    std::cout << _player2->getName() << "'s board:" << std::endl;
    _player2->getGrid().print();
    
    if (!draw)
        std::cout << "Congragulation!\n"
                  << (p1Won ? _player1->getName() : _player2->getName()) << " won!" << std::endl;
}

bool Game::isGameOver() const
{
    return (_player1->allShipsSunk() || _player2->allShipsSunk());
}

void Game::displayStatus()
{
    using namespace std;
    cout << _player1->getName() << "'s board:" << endl;
    _player1->getGrid().print(true, true); // show Axes, hide ships;
}
