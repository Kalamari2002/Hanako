#include "Game.h"
Game::Game() 
{
	this->openWindow();		//As the game class is initialized, it will open a window 
}

Game::~Game()
{
	delete this->window;		//When the game is closed, it deletes the window to free up space
}

void Game::openWindow() {

	//									window dimensions		window title	including a close button
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hanako", sf::Style::Close);		//Initializing a window object of type RenderWindow.
	this->window->setFramerateLimit(60);		//The window will not exceed 60 frames per second
}

bool Game::gameIsRunning() {
	return window->isOpen();		//Returns the "isOpen" bool from the RenderWindow class
}

void Game::Run() {		//Called every frame
	Update();
	Render();

}

void Game::Update() {
	sf::Event e;		//An Event registers every input on the screen. An input could be a key press to a mouse click or even mouse movement
	while (this->window->pollEvent(e)) {		//As long as there are inputs on the screen
		if (e.Event::type == sf::Event::Closed) {		//If the event is clicking the close button
			this->window->close();		//The window is closed
		}
	}
	gameScene.UpdateScene();		//Whatever the current scene is, the game will update it
}

void Game::Render() {
	this->window->clear();		//This erases the last drawing on the screen
	for (int i = 0; i < gameScene.sceneObjects.size(); i++) {		//Every sprite on the scene will be drawn on the window
		window->draw(gameScene.sceneObjects[i]->sprite);
	}
	this->window->display();	//Finally, the window will display its new drawing
}

