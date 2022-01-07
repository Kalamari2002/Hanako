#include "Player.h"
Player::Player() :GameObject("./Sprites/Player/mrmomo.png", sf::Vector2i(0, 0), sf::Vector2f(.2f, .2f)) {
}

void Player::Movement() {

	//Getting player input. X and Y velocity changes depending on what key was last pressed, and nullified if a certain axis has no current input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		velocity.x = VEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocity.x = -VEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		velocity.y = -VEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		velocity.y = VEL;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocity.x = 0;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		velocity.y = 0;
	}


	//Multiplying the velocity to the deltaTime, so that the velocity remain constant regardless of fps
	this->position.x += velocity.x * deltaTime;
	this->position.y += velocity.y * deltaTime;

}

void Player::Update() {
	GameObject::Update();		//The player will inherit the GameObject Update function, and add its unique Movement function
	Movement();
}