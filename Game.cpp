// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "Game.hpp"
// -------------------------------------------

Game::Game(Player* p1, Player* p2)
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
    bool p1Won = true;
    while (true)
    {
        _player1->makeMove(_player2);
        if (_player2->allShipsSunk())
        {
            break;
        }
        _player2->makeMove(_player1);
        if (_player1->allShipsSunk())
        {
            p1Won = false;
            break;
        }
        displayStatus();
    }
    std::cout << _player1->getName() << "'s board:" << std::endl;
    _player1->getGrid().print();
    std::cout << _player2->getName() << "'s board:" << std::endl;
    _player2->getGrid().print();
    std::cout << "Congragulation!\n" << (p1Won ? _player1->getName() : _player2->getName()) << " won!" << std::endl;
    
}

bool Game::isGameOver() const
{
    return (_player1->allShipsSunk() || _player2->allShipsSunk());   
}

void Game::displayStatus()
{
    using namespace std;
    cout << _player1->getName() << "'s board:" << endl;
    _player1->getGrid().print(true,true);   // show Axes, hide ships;
}
