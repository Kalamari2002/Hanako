// Hanako.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"


sf::Clock timer;
float deltaTime;

int main()
{
    Game game;

    while (game.gameIsRunning()) {      //While the window is open, the game class will execute the Run function every frame
        game.Run();
        deltaTime = timer.restart().asSeconds();        //deltaTime is an external variable that maintains a consistent time measurement regardless of fps
    }

    return 0; 
}
