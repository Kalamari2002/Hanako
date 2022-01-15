#include "Player.h"
Player::Player() :GameObject("./Sprites/Player/mrmomo.png", sf::Vector2i(0, 0), sf::Vector2f(.2f, .2f)) {
	for (int i = 0; i < NUMBER_OF_BULLETS; i++) {
		bullets.push_back(new PlayerBullet());
	}
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

void Player::Shoot() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		sf::Time elapsed = fireRate.getElapsedTime();

		if (elapsed.asSeconds() >= TIME_BETWEEN_BULLETS) {

			bullets[currentBulletIndex]->position.x = this->position.x;
			bullets[currentBulletIndex]->position.y = this->position.y;

			currentBulletIndex == bullets.size() - 1 ? currentBulletIndex = 0 : currentBulletIndex++;
			fireRate.restart();
		}
	}

}

void Player::Update() {
	GameObject::Update();		//The player will inherit the GameObject Update function, and add its unique Movement function
	Movement();
	Shoot();
}