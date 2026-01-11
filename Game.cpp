// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "Game.hpp"
// -------------------------------------------
static void winnerConfetti(const char* winnerName);

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
    //player1->getGrid().printGrid();
    player1->getGrid().print();
    std::cout << player2->getName() << "'s board:" << std::endl;
    //player2->getGrid().printGrid();
    player2->getGrid().print();
    std::cout << "Congragulation!\n" << (p1Won ? player1->getName() : player2->getName()) << " won!" << std::endl;
    
    // Confetti - YAY
    //std::cout << "\n Winner is: " << winner->getName() << "\n";
    //winnerConfetti(winner->getName());
    winnerConfetti( (p1Won ? player1->getName() : player2->getName()) );
}

bool Game::isGameOver() const
{
    return (player1->allShipsSunk() || player2->allShipsSunk());   
}

void Game::displayStatus()
{
    using namespace std;
    cout << player1->getName() << "'s board:" << endl;
    //player1->displayGrid();
    player1->getGrid().print(true,true);   // show Axes, hide ships;
    // cout << player2->getName() << "'s board:" << endl;
    // player2->displayGrid();
}

/*
//-----------------------------------------------------
// WINNER CONFETTI ANIMATION (Tryout)::
//-----------------------------------------------------
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
//-----------------------------------------------------

static void CLEAR_SCREEN()
{
    // checks if 32/64bit sys:
    using namespace std;

    #ifndef _WIN32
        system("cls");
    #else
    //cout << "\x1B[2J\x1B[X";
    
    // Works perfectly in WSL/Linux terminals
    cout << "\033[2J\033[H" << std::flush;
    #endif
}

// add to Game::start():
//  std::cout << "\nWinner is: " << winner->getName() << "\n";
//  WinnerConfetti(winner->getName());
static void winnerConfetti(const char* winnerName)
{
    using namespace std;
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> pick(0,5);
    const char conf[] = { '*' , '+' , 'o' , '.','^','@'};

    for(int frame = 0; frame < 20 ; ++frame)
    {
        CLEAR_SCREEN();
        cout<<"\n WINNER: "<<winnerName << "! :) ";
    }

    for (int row = 0; row < 12; ++row)
    {
        cout<<"   ";
        for (int col = 0; col < 45; ++col){ conf[pick(rng)];}
        cout<<"\n";
        // added for clean the screen and make anim effect;
        cout<<flush;
    }
    this_thread::sleep_for(chrono::milliseconds(75));
    
}
// Small Fix for Bad Input::
#include <limits>
#include <iostream>

static void ClearBadInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

    //--------------------------------------------------------------------
    // CONFETTI TESTI:
    char t = 0;
    std::cout << "Type 'c' to test, or press Enter to start: ";
    //std::getline(std::cin, cmd);
    std::cin >> t;

    if (t == 'c' || t == 'C')
    { winnerConfetti("TEST MODE"); return;}
    //--------------------------------------------------------------------
*/
