#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "BossLevel.h"

class Game
{
private:
	sf::RenderWindow* window;		//window will render the sprites in a given scene.
	void openWindow();		//Called right as the Game class is initialized. It initializes the window by defining its size and characteristics 
	BossLevel gameScene;		//BossLevel will be scene where the actual game takes place

public:
	Game();		//Game constructor
	~Game();	//Game destructor (a destructor is the last function that is going to be called before an object is destroyed.)

	bool gameIsRunning();		//A boolean which tells whether the window is still open or not

	void Run();		//Every function called in this function will be called every frame.
	void Update();
	void Render();
};

